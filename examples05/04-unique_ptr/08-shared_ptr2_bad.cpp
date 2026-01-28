#include <iostream>
#include <memory>

class Example {
  public:
    int val;
    std::shared_ptr<Example> ptr;

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
    std::shared_ptr<Example> p1 = std::make_shared<Example>();
    std::shared_ptr<Example> p2 = std::make_shared<Example>();
    p1->ptr = p2;
    p2->ptr = p1;
    return 0;
}
