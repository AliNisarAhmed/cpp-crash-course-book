#include <chrono>
#include <iostream>
#include <thread>

struct TimerClass {
  TimerClass(const char *name)
      : timestamp{std::chrono::steady_clock::now()}, name{name} {}

  // copy constructor
  TimerClass(const TimerClass &other) : timestamp{other.timestamp} {
    std::cout << "copy constructor of name: " << name << '\n';
  }

  // copy assignment
  TimerClass operator=(const TimerClass &other) {
    std::cout << "copy assignment of name: " << name << '\n';
    if (this == &other) {
      return *this;
    }
    timestamp = other.timestamp;
    return *this;
  }

  // move constructor
  TimerClass(TimerClass &&other) noexcept : timestamp{other.timestamp} {
    std::cout << "move constructor of name: " << name << '\n';
  }

  // move assignment
  TimerClass operator=(const TimerClass &&other) {
    std::cout << "move assignment of name: " << name << '\n';
    if (this == &other) {
      return *this;
    }
    timestamp = other.timestamp;
    return *this;
  }

  ~TimerClass() {
    std::cout << "destructor of name: " << name << '\n';
    auto current = std::chrono::steady_clock::now() - timestamp;
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(current)
                     .count();
    std::cout << " microseconds\n";
    std::cout << "My name: " << name << '\n';
  }

private:
  std::chrono::steady_clock::time_point timestamp;
  const char *name;
};

struct TimerClassOwner {
  TimerClassOwner(TimerClass *t) : timerclass{t} {}

private:
  TimerClass *timerclass;
};

void calculation(TimerClass &&timer1, TimerClass *timer2) {
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main() {
  auto t2 = new TimerClass{"t2"};
  auto t3 = TimerClass{"t3"};
  auto t4 = TimerClass{"t4"};
  t3 = t4;
  calculation(TimerClass{"t1"}, t2);
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  delete t2;
}
