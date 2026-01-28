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

template <class T> void bubblesort(T* A, unsigned int size)
{
    for (unsigned int i = 0; i < size - 1; i++)
        for (unsigned int j = size - 1; j > i; j--)
            if (A[j] < A[j - 1])
                swap_value(A[j], A[j - 1]);
}

int main()
{
    string S[5] = {"ula", "ala", "ola", "genowefa", "stefania"};
    int I[3] = {4, 1234, -7};
    bubblesort(S, 5);
    bubblesort(I, 3);
    for (int i = 0; i < 5; i++)
        cout << S[i] << endl;
    for (int i = 0; i < 3; i++)
        cout << I[i] << endl;
}
