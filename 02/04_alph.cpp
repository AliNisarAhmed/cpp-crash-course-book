#include <cstdio>
int main() {
  char alphabet[27];
  for (int i = 0; i < 26; i++) {
    alphabet[i] = i + 'a';
  }
  alphabet[26] = 0;
  printf("%s\n", alphabet);
  for (int i = 0; i < 26; i++) {
    alphabet[i] = i + 'A';
  }
  printf("%s\n", alphabet);
}
