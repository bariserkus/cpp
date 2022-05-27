#include <iostream>
#include <thread>

void foo(){
    std::cout << "ID of this thread: " << std::this_thread::get_id() << " \n";
}

int main() {
    std::thread thread_1(foo);
    std::thread thread_2(foo);
    std::thread thread_3(foo);
    std::thread thread_4;

    std::cout << "\n";

    std::cout << "Thread 1:" << thread_1.get_id() << " \n";
    std::cout << "Thread 2:" << thread_2.get_id() << " \n";
    std::cout << "Thread 3:" << thread_3.get_id() << " \n";
    std::cout << "Thread 4:" << thread_4.get_id() << " \n";

    thread_1.join();
    thread_2.join();
    thread_3.join();

    std::cout << "Thread 1 (after join):" << thread_1.get_id() << " \n";

    std::cout << "Hardware Concurrancy:" << std::thread::hardware_concurrency() << " \n";



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
