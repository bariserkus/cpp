#include <iostream>
#include <thread>

void foo(){
    printf("Hello from foo %d \n", std::this_thread::get_id());
}

class callable_class{
public:
    void operator()(){
        printf("Hello from class function call operator - %d \n", std::this_thread::get_id());
    }
};

int main(){
    std::thread thread1(foo);

    callable_class my_call_obj;
    std::thread thread2(my_call_obj);

    std::thread thread3([]{
        printf("Hello from lambda function - %d \n", std::this_thread::get_id());
    });

    thread1.join();
    thread2.join();
    thread3.join();

    printf("Hello from main - %d \n", std::this_thread::get_id());

    return 0;
}