#include <iostream>
#include <thread>

thread_local int  i = 0;

void foo(){
    ++i;
    std::cout << i;

}


int main() {
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "\nHello, World!" << std::endl;
    return 0;
}

