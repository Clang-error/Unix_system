#include <stdio.h>
#include <unistd.h>

int main(void) {
  int second = 0;
  alarm(5);
  printf("Infinite loop..\n");
  for (;;) {
    sleep(1);
    printf("Elapsed %d seconds..\n", ++second);
  }
  printf("DO not reached here..\n");
  return 0;
}
