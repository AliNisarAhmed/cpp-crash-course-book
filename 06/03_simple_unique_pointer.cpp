
#include <cstdio>
#include <utility>
template <typename T> struct SimpleUniquePointer {
  SimpleUniquePointer() = default; // default constructor
  SimpleUniquePointer(T *pointer) : pointer{pointer} {}

  ~SimpleUniquePointer() {
    if (pointer) {
      delete pointer;
    }
  }

  // delete copy constructor
  SimpleUniquePointer(const SimpleUniquePointer &) = delete;

  // delete copy assignment constructor
  SimpleUniquePointer &operator=(const SimpleUniquePointer &) = delete;

  // move constructor
  SimpleUniquePointer(SimpleUniquePointer &&other) noexcept
      : pointer{other.pointer} {
    other.pointer = nullptr;
  }

  // move assignment constructor
  SimpleUniquePointer &operator=(SimpleUniquePointer &&other) noexcept {
    // if there's already a pointer, delete it
    if (pointer) {
      delete pointer;
    }
    pointer = other.pointer;
    other.pointer = nullptr;
    return *this;
  }

  T *get() { return pointer; }

private:
  T *pointer;
};

struct Tracer {
  Tracer(const char *name) : name{name} { printf("%s constructed.\n", name); }

  ~Tracer() { printf("%s destructed.\n", name); }

private:
  const char *const name;
};

void consumer(SimpleUniquePointer<Tracer> consumer_ptr) {
  printf("(cons) consumer_ptr: 0x%p\n", consumer_ptr.get());
}

int main() {
  auto ptr_a = SimpleUniquePointer(new Tracer{"ptr_a"});
  printf("(main) ptr_a: 0x%p\n", ptr_a.get());
  consumer(std::move(ptr_a));
  printf("(main) ptr_a: 0x%p\n", ptr_a.get());
}
