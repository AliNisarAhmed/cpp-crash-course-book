#include <cstdio>
enum class Operation { Add, Subtract, Multiply, Divide };

struct Calculator {
  Calculator(Operation op_in) { op = op_in; }

  int calculate(int a, int b) {
    switch (op) {
    case Operation::Add: {
      return a + b;
    };

    case Operation::Divide: {
      return a / b;
    };

    case Operation::Multiply: {
      return a * b;
    };

    case Operation::Subtract: {
      return a - b;
    };
    default:
      return 0;
    };
  }

private:
  Operation op;
};

int main() {
  Calculator add_calc{Operation::Add};
  printf("result: %d\n", add_calc.calculate(10, 29));
}
