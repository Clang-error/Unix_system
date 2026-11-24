#include <_stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <sys/dirent.h>

int main(int argc, char *argv[]) {
  struct dirent *direntp;
  DIR *dirp;

  if (argc != 2) { // 인자가 두개가 아니라면.
    fprintf(stderr, "Usage: %s diretory_name\n", argv[0]);
    return 1;
  }
  if ((dirp = opendir(argv[1])) == NULL) { // 두번째 인자로 디렉터리 오픈
    perror("failed open directory");
    return 1;
  }
  while ((direntp = readdir(dirp)) != NULL) {
    printf("%s\n", direntp->d_name);
  }
  while ((closedir(dirp) == -1) && (errno == EINTR)) {
    return 0;
  }
}
