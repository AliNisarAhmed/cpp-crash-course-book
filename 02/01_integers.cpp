#include <cstdio>
int main() {
  unsigned short a = 0b10101010;
  printf("%hu\n", a);
  int b = 0123;
  printf("%d\n", b);
  unsigned long long d = 0xFFFFFFFFFF;
  printf("%llu\n", d);

  printf("-----\n");

  unsigned int ali = 1024;
  printf("Hex: %x\n", ali);
  printf("%u, %o\n", ali, ali);
}
