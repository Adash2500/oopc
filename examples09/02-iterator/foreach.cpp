#include <iostream>
#include <stddef.h>

class Iterator;

class Collection {
    static const size_t size = 10;
    int data[size];
    friend class Iterator;

  public:
    Iterator begin();
    Iterator end();
};

class Iterator {
    int i;
    Collection* c;

  public:
    Iterator(int ii, Collection* cc) : i(ii), c(cc){};
    int& operator*()
    {
        return c->data[i];
    }
    Iterator& operator++()
    {
        ++i;
        return *this;
    }
    bool operator!=(const Iterator& o)
    {
        return i != o.i;
    }
};

Iterator Collection::begin()
{
    return Iterator(0, this);
}

Iterator Collection::end()
{
    return Iterator(Collection::size, this);
}

int main()
{
    Collection c;

    int a = 3;

    for (auto& i : c)
        i = a++;

    for (auto i : c)
        std::cout << i << std::endl;
}
