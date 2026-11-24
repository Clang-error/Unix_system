#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char *menu[2] = {"햄버거", "짱꺠"};
  int n = sizeof(menu) / sizeof(menu[0]);
  srand((unsigned)time(NULL));

  int idx = rand() % n;

  printf("%s\n", menu[idx]);
  return 0;
}
