/* restart.h — 4장 슬라이드의 재시작/블록 I/O 함수 원형 (구현은 restart.c) */
#ifndef RESTART_H
#define RESTART_H

#include <sys/types.h>

ssize_t r_read(int fd, void *buf, size_t size);          /* 프로그램 4.3 [p53]: EINTR이면 read 재호출 */
ssize_t r_write(int fd, void *buf, size_t size);         /* 프로그램 4.4 [p55~56]: EINTR + 부분 쓰기 처리, 성공 시 size 반환 */
int readwrite(int fromfd, int tofd);                     /* 프로그램 4.5 [p58~59]: 한 번 읽고 그만큼 씀 */
int copyfile(int fromfd, int tofd);                      /* 프로그램 4.6 [p60~61]: EOF까지 읽고 쓰기 반복, 총 바이트 반환 */
ssize_t readblock(int fd, void *buf, size_t size);       /* 프로그램 4.7 [p62~63]: 정확히 size만큼 읽음 (size / 0 / -1) */
int readwriteblock(int fromfd, int tofd, char *buf, int size); /* 프로그램 4.8 [p66] */
int r_close(int fd);                                     /* 프로그램 4.10 [p92]: EINTR이면 close 재호출 */

#endif
