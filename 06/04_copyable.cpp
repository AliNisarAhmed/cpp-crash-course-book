#include <stdexcept>

int &get(int (&arr)[10], size_t index) {
  if (index >= 10) {
    throw std::out_of_range{"Out of bounds"};
  }
  return arr[index];
}

template <typename T> T &get2(T (&arr)[10], size_t index) {
  if (index >= 10) {
    throw std::out_of_range{"Out of bounds"};
  }
  return arr[index];
}

template <typename T, size_t Length> T &get3(T (&arr)[Length], size_t index) {
  if (index >= Length) {
    throw std::out_of_range{"Out of bounds"};
  }
  return arr[index];
}

template <size_t Index, typename T, size_t Length> T &get4(T (&arr)[Length]) {
  static_assert(Index < Length, "Out of bounds access");
  return arr[Index];
}

int main() {
  int arr[5] = {1, 2, 30, 4, 5};
  // throws exception, no type checking
  // int &three = get3(arr, 6);
  int three = get4<3>(arr);
  printf("three: %d\n", three);
}
