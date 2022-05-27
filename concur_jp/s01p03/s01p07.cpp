#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>

using namespace std;

void work(int &count, mutex &m){
    for(int i = 0; i < 1E6; ++i){
        m.lock();
        ++count;
        m.unlock();
    }
}

int main(){

    int count = 0;
    mutex m;
    
    thread t1(work, ref(count), ref(m));
    thread t2(work, ref(count), ref(m));

    t1.join();
    t2.join();

    //this_thread::sleep_for(chrono::milliseconds(5000));
    
    cout << count << "\n";
    

    
    return 0;
}