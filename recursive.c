#include <stdio.h>

void up_and_down(int n) {
  printf("level %d\n", n);
  if (n < 3)
    up_and_down(n + 1);
  printf("Level %d\n", n);
}

int main(void) {
  up_and_down(1);
  return 0;
}
