#include <future>
#include <iostream>
#include <string>
#include <thread>

std::string fun()
{ // normal function
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return std::string("Hello from future!");
}

int main(int argc, const char* argv[])
{
    std::future<std::string> fut =
        std::async(&fun); // asyncronously: starts now or later
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout << "Wait for result" << std::endl;
    std::string str = fut.get(); // but will be finished here
    std::cout << str << std::endl;

    return 0;
}