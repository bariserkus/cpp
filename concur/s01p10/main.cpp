#include <iostream>
#include <thread>

void func_1(int x, int y){
    printf("X + Y = %d\n", x + y);
}

void func_2(int &x){
    while (true)
    {
        printf("Thread 1 value of X - %d \n", x);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}


int main() {
    int p{9}, q{8};
    std::thread thread_1(func_1, p, q);
    thread_1.join();
    std::cout << "Hello, World!" << std::endl;


    int x{9};
    printf("Main thread value of X - %d \n", x);

    std::thread thread_2(func_2,std::ref(x));
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    x = 15;
    printf("Main thread value of X has changed to - %d \n", x);
    thread_2.join();
    return 0;
}
