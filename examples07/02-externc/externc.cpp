extern "C" int fun1();
extern "C" {
void fun2(int a);
int fun3(double b);
}

int main()
{
    int a = fun1();
    fun2(a);
    a = fun3(3.14);
}
