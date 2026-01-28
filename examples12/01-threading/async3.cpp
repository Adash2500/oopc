#include <future>
#include <iostream>
#include <string>
#include <thread>

std::string fun()
{ // normal function or the like
    return std::string("Hello from future!");
}

int main(int argc, const char* argv[])
{
    auto f1 = std::async(std::launch::async, &fun); // starts now in a thread
    std::string str1 = f1.get(); // blocks until thread implicitly joined
    std::cout << str1 << std::endl;

    auto f2 = std::async(std::launch::deferred, &fun); // later in main thread
    std::string str2 = f2.get();                       // call fun now
    std::cout << str2 << std::endl;

    return 0;
}
