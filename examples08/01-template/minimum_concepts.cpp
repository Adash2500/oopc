#include <iostream>
#include <string>
#include <concepts>

using namespace std;

template <class T> 
concept LessComparable = requires(const T l, const T r, bool res)
{
    res = (l < r);
};

template <class T> T minimum(T x, T y) requires std::constructible_from<T, const T&> && LessComparable<T>
{
    if (x < y)
        return x;
    else
        return y;
}

class NotComparable
{
};

class NotCopyConstructible
{
  public:
    NotCopyConstructible(){};
    NotCopyConstructible(const NotCopyConstructible&) = delete;
    friend bool operator<(NotCopyConstructible, NotCopyConstructible){return true;};
};

int main()
{
    int x = 50, y = 30;
    string a = "hello", b = "goodbye";
    cout << "minimum for ints " << minimum(x, y) << endl;
    cout << "minimum for strings " << minimum(a, b) << endl;
//    minimum(NotComparable(), NotComparable());
//    minimum(NotCopyConstructible(), NotCopyConstructible());

}
