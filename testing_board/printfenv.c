#include <stdio.h>
#include <stdlib.h>

int main() {
  char *ptr;

  ptr = getenv("HOME");
  printf("HOME = %s\n", ptr);

  return 0;
}
