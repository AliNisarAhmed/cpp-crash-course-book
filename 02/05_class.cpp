class ClockOfTheLongNow {
  int year;

public:
  void add_year() { year++; }

  bool set_year(int new_year) {
    if (new_year < 2019) {
      return false;
    }
    year = new_year;
    return true;
  }

  int get_year() { return year; }
};

struct ClockOfTheLongNow2 {
  ClockOfTheLongNow2() { year = 2019; }
  ClockOfTheLongNow2(int year_in) {
    if (!set_year(year_in)) {
      year = 2019;
    }
  }
  void add_year() { year++; }
  bool set_year(int new_year) {
    if (new_year < 2019) {
      return false;
    }
    year = new_year;
    return true;
  }
  int get_year() { return year; }

private:
  int year;
};

int main() {
  ClockOfTheLongNow c;
  c.set_year(2024);
  c.get_year();

  ClockOfTheLongNow2 c2;
  c2.get_year(); // 2019 due to constructor

  ClockOfTheLongNow2 c3{2020};
}
