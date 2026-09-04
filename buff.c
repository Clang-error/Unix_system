#include <stdio.h>

int main(void) {
  char buf[80];

  printf("Enter your first name: ");
  scanf("%s", buf); // 이렇게 입력을 받으면 버퍼 오버플로우가 발생 할 수 있음
  // 악의적인 사용자라면 입력을 억지로 크게 넣어서 오버플로우를 유발할 수있음
}
