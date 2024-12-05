#include <cstdio>
struct College {
  char name[256];
};

void print_name(College *college_ptr) {
  printf("%s College\n", college_ptr->name);
}

void print_names(College *colleges, size_t n) {
  for (size_t i = 0; i < n; i++) {
    print_name(&colleges[i]);
  }
}

int main() {
  College best_colleges[] = {"magdalen", "nuffield", "kellog"};

  print_name(best_colleges); // only prints "magdalen"

  print_names(best_colleges, sizeof(best_colleges) / sizeof(College)); // prints all colleges
}
