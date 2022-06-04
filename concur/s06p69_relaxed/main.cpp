#include <iostream>
#include <vector>
#include <chrono>
#include <atomic>
#include <thread>
#include <cassert>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x_then_y(){
    y.store(true, std::memory_order_relaxed);
    x.store(true, std::memory_order_relaxed);
}

void read_y_then_x(){
    while(!y.load(std::memory_order_relaxed)){
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
