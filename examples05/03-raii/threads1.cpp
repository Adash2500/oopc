#include "mutex.h"
#include <stdio.h>
#include <thread>

int Counter = 0;

void thread1()
{
    for (unsigned int i = 0; i < 100000; i++) {
        Counter++;
        Counter--;
    }
}

void thread2()
{
    for (unsigned int i = 0; i < 100000; i++) {
        Counter++;
        Counter--;
    }
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    printf("Counter=%d\n", Counter);
}
