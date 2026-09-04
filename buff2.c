#include <stdio.h>

int main(void) {
  char buf[80];
  printf("Enter your first name: ");
  scanf("%79s", buf); // 이렇게 사용하면 오버플로우가 발생하지않음
}
