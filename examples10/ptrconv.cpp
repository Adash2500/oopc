class A {
    int a;
};

class B {
    int b;
};

class C : public A, public B {
    int c;
};

int main()
{
    C c;

    A* aptr = &c;
    B* bptr = &c;
}
