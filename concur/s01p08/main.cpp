#include <iostream>
#include "common.h"

void foo(){
    printf("Hello from function foo\n");
}

void other_operations(){
    printf("Hello from other operations\n");
    throw std::runtime_error("This is a runtime error in other operations!\n");
}

int main() {
    std::thread foo_thread(foo);
    thread_guard tg(foo_thread);
    try {
        other_operations();
//        foo_thread.join();
    }
    catch (...)    {
//        foo_thread.join();
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
