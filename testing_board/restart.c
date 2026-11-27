/* restart.c — 4장 슬라이드 코드 그대로 (r_read의 retval만 ssize_t로 고침: -1을 담아야 하므로) */
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include "restart.h"

#define BLKSIZE 1024

/* 프로그램 4.3 [p53] */
ssize_t r_read(int fd, void *buf, size_t size) {
    ssize_t retval;
    while (retval = read(fd, buf, size), retval == -1 && errno == EINTR) ;
    return retval;
}

/* 프로그램 4.4 [p55~56] */
ssize_t r_write(int fd, void *buf, size_t size) {
    char *bufp;
    size_t bytestowrite;
    ssize_t byteswritten;
    size_t totalbytes;

    for (bufp = buf, bytestowrite = size, totalbytes = 0;
         bytestowrite > 0;
         bufp += byteswritten, bytestowrite -= byteswritten) {
        byteswritten = write(fd, bufp, bytestowrite);
        if ((byteswritten == -1) && (errno != EINTR))   /* real error on fd */
            return -1;
        if (byteswritten == -1)                         /* interrupted: retry same spot */
            byteswritten = 0;
        totalbytes += byteswritten;
    }
    return totalbytes;
}

/* 프로그램 4.5 [p58~59] */
int readwrite(int fromfd, int tofd) {
    char buf[PIPE_BUF];
    int bytesread;

    if ((bytesread = r_read(fromfd, buf, PIPE_BUF)) == -1)
        return -1;
    if (bytesread == 0)
        return 0;
    if (r_write(tofd, buf, bytesread) == -1)
        return -1;
    return bytesread;
}

/* 프로그램 4.6 [p60~61] */
int copyfile(int fromfd, int tofd) {
    char buf[BLKSIZE];
    int bytesread, byteswritten;
    int totalbytes = 0;

    for ( ; ; ) {
        if ((bytesread = r_read(fromfd, buf, BLKSIZE)) <= 0)   /* EOF(0) 또는 오류(-1)면 끝 */
            break;
        if ((byteswritten = r_write(tofd, buf, bytesread)) == -1)
            break;
        totalbytes += byteswritten;
    }
    return totalbytes;
}

/* 프로그램 4.7 [p62~63] */
ssize_t readblock(int fd, void *buf, size_t size) {
    char *bufp;
    size_t bytestoread;
    ssize_t bytesread;
    size_t totalbytes;

    for (bufp = buf, bytestoread = size, totalbytes = 0;
         bytestoread > 0;
         bufp += bytesread, bytestoread -= bytesread) {
        bytesread = read(fd, bufp, bytestoread);
        if ((bytesread == 0) && (totalbytes == 0))   /* 읽기 전에 파일 끝에 도달 */
            return 0;
        if (bytesread == 0) {                        /* 조금 밖에 읽지 못한 채 파일 끝에 도달 */
            errno = EINVAL;
            return -1;
        }
        if ((bytesread == -1) && (errno != EINTR))   /* 읽기 실패 */
            return -1;
        if (bytesread == -1)                         /* 시그널에 의한 인터럽트 */
            bytesread = 0;
        totalbytes += bytesread;
    }
    return totalbytes;
}

/* 프로그램 4.8 [p66] */
int readwriteblock(int fromfd, int tofd, char *buf, int size) {
    int bytesread;

    bytesread = readblock(fromfd, buf, size);
    if (bytesread != size)                           /* can only be 0 or -1 */
        return bytesread;
    return r_write(tofd, buf, size);
}

/* 프로그램 4.10 [p92] */
int r_close(int fd) {
    int retval;
    while (retval = close(fd), retval == -1 && errno == EINTR) ;
    return retval;
}
