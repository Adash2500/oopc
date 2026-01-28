#include <iostream>
#include <string>
using namespace std;
template <class T> void swap_value(T& var1, T& var2)
{
    T temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}

class Value {
  private:
    int x;

  public:
    Value(int i = 0) : x(i) {}
    friend ostream& operator<<(ostream& out, Value v);
};

ostream& operator<<(ostream& out, Value v)
{
    out << "value(" << v.x << ")";
    return out;
}

int main()
{
    Value v1(5), v2(10);
    cout << "original " << v1 << " " << v2 << endl;
    swap_value(v1, v2);
    cout << "after " << v1 << " " << v2 << endl;
}
