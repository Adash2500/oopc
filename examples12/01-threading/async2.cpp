#include <exception>
#include <future>
#include <iostream>
#include <string>
#include <thread>

std::string fun()
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    throw std::runtime_error("Exception from future");
    return std::string("Hello from future!");
}

int main(int argc, const char* argv[])
{
    std::future<std::string> fut =
        std::async(&fun); // asynchronously: starts now or later
    try {
        std::string str = fut.get(); // but will be finished here
        std::cout << str << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}