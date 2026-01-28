#include <chrono>
#include <deque>
#include <iostream>
#include <list>
#include <mutex>
#include <thread>
#include <unistd.h>

using namespace std;

std::deque<unsigned int> FIFO;
std::mutex FIFO_lock;

void process()
{
    while (1) {
        std::unique_lock l(FIFO_lock);
        if (!FIFO.empty()) {
            cout << FIFO.back() << endl;
            FIFO.pop_back();
        }
    }
}

int main()
{
    std::thread t(process);
    unsigned int i = 0;
    while (1) {
        {
            std::unique_lock l(FIFO_lock);
            FIFO.push_front(i++);
        }
        std::this_thread::sleep_for(10ms);
    }
}
