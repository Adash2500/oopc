class A {
  public:
    int a;
};

class B : virtual public A {
    int b;
};

class C : virtual public A {
    int c;
};

class D : public B, public C {
    int d;
};

class E : public C, public B {
    int e;
};

int main()
{
    D d;
    E e;

    C* cptr1 = &d;
    C* cptr2 = &e;

    cptr1->a = 1;
    cptr2->a = 2;
}
