#include <iostream>
#include <vector>
#include <chrono>
#include <atomic>
#include <thread>
#include <cassert>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x_then_y(){

    x.store(true, std::memory_order_relaxed);
    y.store(true, std::memory_order_release);
}

void read_y_then_x(){
    while(!y.load(std::memory_order_acquire)){
        ;
    }
    if(x.load(std::memory_order_relaxed)){
        z++;
    }
}

int main() {

    x = false;
    y = false;
    z = 0;

    std::thread thread_writer(write_x_then_y);
    std::thread thread_reader(read_y_then_x);
    //std::this_thread::sleep_for(std::chrono::seconds(2))  ;

    thread_writer.join();
    thread_reader.join();

    std::cout << "z: " << z << '\n';
    assert(z != 0);

    return 0;
}
