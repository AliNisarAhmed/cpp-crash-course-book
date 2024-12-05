#include <cstdio>
#include <stdexcept>

void carbon_thaw(const int &encased_solo) {
  // Line below will be a compiler error without const_cast
  // encased_solo++;
  auto &sick_solo = const_cast<int &>(encased_solo);
  sick_solo++;
}

short increment_as_short(void *target) {
  auto as_short = static_cast<short *>(target);
  *as_short = *as_short + 1;
  return *as_short;
}

template <typename To, typename From> To narrow_cast(From value) {
  const auto converted = static_cast<To>(value);
  const auto backwards = static_cast<From>(converted);
  if (value != backwards) {
    throw std::runtime_error{"Narrowed!"};
  }
  return converted;
}

int main() {
  int beast{65};
  auto mark_of_the_beast = increment_as_short(&beast);
  printf("%d is mark_of_the_beast", mark_of_the_beast);

  auto timer = reinterpret_cast<const unsigned long *>(0x1000);

  int perfect{496};
  const auto perfect_short = narrow_cast<short>(perfect);
  printf("perfect_short: %d\n", perfect_short);

  try {
    int cyclic{142857};
    const auto cyclic_short = narrow_cast<short>(cyclic);
    printf("cyclic_short: %d\n", cyclic_short);
  } catch (const std::runtime_error &e) {
    printf("Exception: %s\n", e.what());
  }
}
