#include "restart.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <unistd.h>
#define FIFOARG 1
#define FIFO_PERMS (S_IRWXU | S_IWGRP | S_IWOTH) // 유저 7 그룹 4 그외 4

int main(int argc, char *argv[]) {
  int requestfd;

  if (argc != 2) { // 인자가 안들어왔거나 , 2개이상이라면
    fprintf(stderr, "Usage: %s fifoname > logfile \n", argv[0]);
    return 1;
  }

  // 파이프를 만들었을때 -1을 리턴하고, errno 변수가 EEXIST 가 아니라면
  if ((mkfifo(argv[FIFOARG], FIFO_PERMS) == -1) && (errno != EEXIST)) {
    perror("Server failed to create a FIFO");
    return 1;
  }

  if ((requestfd = open(argv[FIFOARG], O_RDWR)) == -1) {
    perror("Server failed to open its FIFO");
    return 1;
  }

  copyfile(requestfd, STDOUT_FILENO);

  return 1;
}
