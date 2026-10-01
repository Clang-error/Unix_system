#include <fcntl.h>
#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd;
  if ((fd = open(argv[1], O_RDONLY)) == -1) {
    perror("open::");
    return -1;
  }
}
