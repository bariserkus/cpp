#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void work(){
    for (int i = 0; i < 10; ++i){
        //this_thread::sleep_for(chrono::milliseconds(500));

        cout << "Loop : " << i << "\n";
    }
}

int main(){

    thread t1(work);
    thread t2(work);

    cout << "Hello World" << "\n";

    t1.detach();
    t2.detach();
    this_thread::sleep_for(chrono::milliseconds(5000));
    return 0;
}