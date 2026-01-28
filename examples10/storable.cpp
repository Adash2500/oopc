#include <iostream>

class Storable {
  public:
    Storable(){};
    virtual void write(){};
    virtual ~Storable()
    {
        write();
    } // to be called
    // from overriding destructors
};

class Data : public Storable {
  public:
    int* data;
    Data()
    {
        data = new int(32);
    };
    ~Data()
    {
        delete data;
    };
    void write() override
    {
        std::cout << *(this->data) << std::endl;
    };
};

int main()
{
    Data d;
    Storable* ptr = &d;
    ptr->write();
}
