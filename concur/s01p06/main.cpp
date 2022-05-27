#include <iostream>
#include <thread>

void myfunc(){
    printf("Hello from myfunction\n");
}

int main() {
    std::thread mythread(myfunc);

    mythread.joinable() ?
    printf("before join: mythread is joinable\n") :
    printf("before join: mythread is not joinable\n");

    mythread.join();

    mythread.joinable() ?
    printf("after join: mythread is joinable\n") :
    printf("after join: mythread is not joinable\n");

    std::thread errthread;
    errthread.joinable() ? printf("errthread is joinable\n") : printf("errthread is not joinable\n");


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
