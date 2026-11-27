#include <stdio.h>
#include <unistd.h>

int main(void) {
  long clk_tck = sysconf(_SC_CLK_TCK);
  long max_child_pc = sysconf(_SC_CHILD_MAX);
  printf("최대 클럭수 %ld\n", clk_tck);
  printf("최대 자식 수 %ld\n", max_child_pc);

  return 0;
}
