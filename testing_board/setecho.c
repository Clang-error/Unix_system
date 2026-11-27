#include <errno.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define ECHOFLAGS (ECHO | ECHOE | ECHOK | ECHONL)

int setecho(int fd, int onflags) {
  int error;
  struct termios term;

  if (tcgetattr(fd, &term) == -1)
    return -1;
  if (onflags)
    term.c_lflag |= ECHOFLAGS;
  else
    term.c_lflag &= ~ECHOFLAGS;
  while (((errno = tcsetattr(fd, TCSAFLUSH, &term)) == -1) && (errno == EINTR))
    ;
  return error;
}
