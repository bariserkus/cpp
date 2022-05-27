#include <iostream>
#include <thread>
#include <chrono>

void foo(){
    std::cout << "Hello from foo \n";
}

void bar(){
    std::cout << "Hello from bar \n";
}

int main() {
    std::thread thread_1(foo);

    //std::thread thread_2 = thread_1;  // Compiler error. Nop copy constructor

    std::thread thread_2 = std::move(thread_1);

    thread_1 = std::thread(bar); //Implicit move constructor...

    std::thread thread_3(foo);

    thread_1 = std::move(thread_3);


    thread_1.join();
    thread_2.join();
    thread_3.join();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
