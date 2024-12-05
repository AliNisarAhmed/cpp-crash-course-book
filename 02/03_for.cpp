#include <cstdio>
#include <string>

int main() {
  unsigned long max = 0;
  unsigned long values[] = {10, 20, 40, 50, 5};
  for (unsigned long value : values) {
    if (value > max) {
      max = value;
    }
  }

  printf("The max is %lu\n", max);

  std::string s = "ldfsdlf"
                  "lsdfjsldf"
                  "oikasl\n"
                  "pdfjlsdjf";

  printf("string: %s\n", s.c_str());
}
