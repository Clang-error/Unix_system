#include <signal.h>
#include <stdio.h>

int main(void) {
  fprintf(stdin, "hello\n");
  if (raise(15) == -1)
    perror("failed raise");
  printf("can't reach here");
  return 0;
}
