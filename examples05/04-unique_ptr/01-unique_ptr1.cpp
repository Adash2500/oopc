#include <iostream>
#include <memory>

class Example {
  public:
    int val;

    Example() : val(0)
    {
        std::cout << "Example::Example()" << std::endl;
    }

    Example(int a) : val(a)
    {
        std::cout << "Example::Example(" << a << ")" << std::endl;
    }

    ~Example()
    {
        std::cout << "Example::~Example()" << std::endl;
    }
};

int main()
{
    std::unique_ptr<Example> a(new Example());
}
