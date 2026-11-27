#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void) {
  sigset_t alarmset;
  struct timespec req = {1, 0};

  if ((sigemptyset(&alarmset) == -1 || sigaddset(&alarmset, 14) == -1)) {
    perror("failed initalize");
    return 1;
  }
  if (sigprocmask(SIG_BLOCK, &alarmset, NULL) == -1) {
    perror("failed sigprocmask");
    return 1;
  }

  printf("set complete, blocked\n");

  alarm(10);

  for (int i = 0; i < 10; i++) {
    nanosleep(&req, NULL);
    printf("%d sec\n", i + 1);
  }

  printf("can reach here!");

  return 0;

  // alarm(10);
}
