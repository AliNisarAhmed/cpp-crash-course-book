#include <cstdio>
#include <cstdlib>

int absolute_value(int x) { return abs(x); }

int main() {
  int my_num = -10;
  printf("The absolute value of %d is %d.\n", my_num, absolute_value(my_num));
}
