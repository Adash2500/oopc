#include <iostream>
#include <memory>

class Example {
public:
  int *val;

  Example(Example &&rhs) : val(rhs.val) {
    rhs.val = nullptr;
    std::cout << "Example::Example(Example &&)" << std::endl;
  }

  Example &operator=(Example &&rhs) // buggy
  {
    if (&rhs == this)
      return *this;
    val = rhs.val;
    rhs.val = nullptr;
    std::cout << "Example::operator=(Example &&)" << std::endl;
    return *this;
  }

  Example() : val(new int(0)) {
    std::cout << "Example::Example()" << std::endl;
  }

  Example(int a) : val(new int(a)) {
    std::cout << "Example::Example(" << a << ")" << std::endl;
  }

  ~Example() {
    delete val;
    std::cout << "Example::~Example()" << std::endl;
  }
};

int main() {
  Example a(3);

  Example b = std::move(a);

  Example c(Example(4));

  Example d;

  d = std::move(b);
}
