#include <cstdio>
struct Element {
  Element *next{};
  Element *previous{};

  void insert_after(Element *new_element) {
    new_element->next = this->next;
    if (this->next) {
      this->next->previous = new_element;
    }
    new_element->previous = this;
    this->next = new_element;
  }

  void insert_before(Element *new_element) {
    new_element->next = this;
    new_element->previous = this->previous;
    if (this->previous) {
      this->previous->next = new_element;
    }
    this->previous = new_element;
  }

  short operating_number;
};

int main() {
  Element tr1, tr2, tr3;
  tr1.operating_number = 1;
  tr2.operating_number = 2;
  tr3.operating_number = 3;
  tr3.insert_before(&tr2);
  tr2.insert_before(&tr1);

  for (auto *cursor = &tr1; cursor; cursor = cursor->next) {
    printf("operating_number: %d\n", cursor->operating_number);
  }

  for (auto *cursor = &tr3; cursor; cursor = cursor->previous) {
    printf("operating_number in reverse: %d\n", cursor->operating_number);
  }
}
