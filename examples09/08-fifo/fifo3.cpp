#include <chrono>
#include <condition_variable>
#include <deque>
#include <iostream>
#include <list>
#include <mutex>
#include <thread>
#include <unistd.h>

using namespace std;

std::deque<unsigned int> FIFO;
std::mutex FIFO_lock;
std::condition_variable cv;

void process()
{
    while (1) {
        std::unique_lock l(FIFO_lock);
        cv.wait(l, [] { return !FIFO.empty(); });
        {
            do {
                cout << FIFO.back() << endl;
                FIFO.pop_back();
            } while (!FIFO.empty());
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
        cv.notify_one();
        std::this_thread::sleep_for(10ms);
    }
}
