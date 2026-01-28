#include <assert.h>
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
    std::weak_ptr<Example> w1;
    {
        std::shared_ptr<Example> p1 = std::make_shared<Example>();
        w1 = p1;
        std::shared_ptr<Example> p2 = w1.lock();
        assert(p2 != nullptr);
    }

    std::shared_ptr<Example> p3 = w1.lock();
    assert(p3 == nullptr);
}
