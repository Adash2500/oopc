class A {
  public:
    int a;
};

class B : public A {
  public:
    int b;
};

class C : private A {
  public:
    int c;
    void fun()
    {
        a = 15;
    };
};

int main()
{
    A a;
    B b;
    C c;

    a.a = 17;
    b.a = 17;
    // c.a = 17;

    A* aptr = &b;
    A* aptr2 = &c;
    aptr2->a = 17;
}
