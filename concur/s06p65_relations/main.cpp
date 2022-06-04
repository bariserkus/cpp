#include <iostream>
#include <vector>
#include <chrono>
#include <atomic>
#include <thread>

std::atomic<bool> data_ready = false;
std::vector<int> data_vector;
int i = 7;

void reader(){
    while(!data_ready){
        std::cout << "Data is not ready. :( Waiting 1 sec..." << '\n';
        std::this_thread::sleep_for(std::chrono::seconds (1));
    }

    std::cout << "Data is ready! :) Printing Vector: " << '\n';
    for (int j : data_vector){
        std::cout << j << ",  ";
    }
    std::cout << "Setting the data_ready to false... " << '\n';
    data_ready.store(false);

}

void writer(){
    std::cout << "Writing new data to vector... " << '\n';
    data_vector.push_back(i++);
    std::cout << "Setting the data_ready to true... " << '\n';
    data_ready.store(true);
}

int main() {

    std::thread t_reader1(reader);

    std::this_thread::sleep_for(std::chrono::seconds (2));
    std::thread t_writer1(writer);

    t_reader1.join();
    t_writer1.join();

    std::thread t_reader2(reader);
    std::thread t_writer2(writer);

    t_reader2.join();
    t_writer2.join();

    return 0;
}
