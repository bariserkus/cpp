#include <iostream>
#include <chrono>
#include <thread>
#include "jthread_local.h"
//
using namespace::std::literals;

void do_something()
{
    int counter{ 0 };
    while (counter < 10)
    {
        if (interrupt_point())
        {
            return;
        }
        std::this_thread::sleep_for(0.2s);
        std::cerr << "This is interruptible thread : " << counter << std::endl;
        ++counter;
    }
}

void do_something_else()
{
    int counter{ 0 };
    while (counter < 10)
    {
        std::this_thread::sleep_for(0.2s);
        std::cerr << "This is non-interruptible thread : " << counter << std::endl;
        ++counter;
    }
}

int main()
{

    std::cout << std::endl;
    jthread_local nonInterruptable(do_something_else);
    jthread_local interruptible(do_something);

    std::this_thread::sleep_for(1.0s);
    interruptible.interrupt();
    nonInterruptable.interrupt();

    //std::cout << std::endl;
    return 0;
}