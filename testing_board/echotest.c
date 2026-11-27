#include <unistd.h>

int setecho(int fd, int onflag);

int main(void) {
  setecho(STDIN_FILENO, 0);
  return 0;
}
