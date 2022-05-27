#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

int main(){

    atomic<int> count = 0;
    const int ITERATIONS = 10000;
    int j = 0;

    thread t1([&count](){
        for(int i = 0; i < ITERATIONS; ++i){
            ++count;
        }
    });
    thread t2([&count](){
        for(int i = 0; i < ITERATIONS; ++i){
            ++count;
        }
    });

    t1.join();
    t2.join();

    //this_thread::sleep_for(chrono::milliseconds(5000));
    
    cout << count << "\n";
    

    
    return 0;
}