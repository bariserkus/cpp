#include <iostream>
#include <thread>
#include <list>
#include <mutex>

std::list<int> my_list;
std::mutex m;

class list_wrapper{
    std::list<int> my_list;
    std::mutex m;

};

void add_to_list(int const & x){
/*    m.lock();
    my_list.push_front(x);
    m.unlock(); */
    std::lock_guard<std::mutex> lg(m);
    my_list.push_back(x);
}

void size(){
    m.lock();
    int size = my_list.size();
    m.unlock();
    std::cout<< "size of the list is : " << size << std::endl;
}


int main() {
    std::thread t1(add_to_list, 4);
    std::thread t2(add_to_list, 11);

    t1.join();
    t2.join();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
