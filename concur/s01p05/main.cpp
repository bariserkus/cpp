#include <iostream>
#include <thread>

void test(){
    printf("Hello from function test - ID number: %d \n", std::this_thread::get_id());
}


void functionA(){
    printf("Hello from function functionA - ID number: %d \n", std::this_thread::get_id());
    std::thread threadC(test);
    threadC.join();
}
void functionB(){
    printf("Hello from function functionB - ID number: %d \n", std::this_thread::get_id());
}

int main() {

    printf("Hello from function main - ID number: %d \n", std::this_thread::get_id());
    std::thread threadA(functionA);
    threadA.join();
    std::thread threadB(functionB);
    threadB.join();

    return 0;
}
