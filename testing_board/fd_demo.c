#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    char buf[9] = {0};

    write(1, "[1] fd 1번에 write하면 화면에 나온다\n", sizeof("[1] fd 1번에 write하면 화면에 나온다\n") - 1);

    int a = open("fd_demo.c", O_RDONLY);
    int b = open("fd_demo.c", O_RDONLY);
    printf("[2] 같은 파일을 두 번 open: a = %d, b = %d\n", a, b);

    read(a, buf, 8); printf("[3] a로 8바이트 읽기   : \"%s\"\n", buf);
    read(a, buf, 8); printf("[4] a로 또 8바이트 읽기: \"%s\"\n", buf);
    read(b, buf, 8); printf("[5] b로 8바이트 읽기   : \"%s\"\n", buf);

    close(a);
    int c = open("fd_demo.c", O_RDONLY);
    printf("[6] close(a) 후 새로 open: c = %d\n", c);
    return 0;
}
