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

std::shared_ptr<Example> getPtr()
{
    std::shared_ptr<Example> a(new Example());

    std::shared_ptr<Example> b = a;

    return a;
}

int main()
{
    std::shared_ptr<Example> c = getPtr();
}
