#include <iostream>
#include <thread>
#include <chrono>

void foo(){
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    printf("hello from foo\n");
}

void bar(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    printf("hello from bar\n");
}
int main() {

    std::thread foo_thread(foo);
    std::thread bar_thread(bar);

    bar_thread.detach();
    printf("This is after bar thread is detached\n");

    foo_thread.join();
    printf("This is after foo thread is joined\n");

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    printf("hello from main\n");

    return 0;
}
