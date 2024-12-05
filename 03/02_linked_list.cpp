#include <cstdio>
struct Element {
  Element *next{};

  void insert_after(Element *new_element) {
    new_element->next = this->next;
    this->next = new_element;
  }

  char prefix[2];
  short operating_number;
};

int main() {
  Element tr1, tr2, tr3;

  tr1.prefix[0] = 'T';
  tr1.prefix[1] = 'K';
  tr1.operating_number = 421;
  tr1.insert_after(&tr2);

  tr2.prefix[0] = 'F';
  tr2.prefix[1] = 'N';
  tr2.operating_number = 2187;
  tr2.insert_after(&tr3);

  tr3.prefix[0] = 'L';
  tr3.prefix[1] = 'S';
  tr3.operating_number = 005;

  for (Element *cursor = &tr1; cursor; cursor = cursor->next) {
    printf("stormtrooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1],
           cursor->operating_number);
  }
}
