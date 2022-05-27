#include <iostream>
#include <mutex>
#include <thread>
#include <list>

//! Example 1
//!

class list_wrapper{
    std::list<int> my_list;
    std::mutex m;

public:
    void add_to_list(int const & x){
        std::lock_guard<std::mutex> lg(m);
        my_list.push_front(x);
    }

    void size(){
        std::lock_guard<std::mutex> lg(m);
        int size = my_list.size();
        std::cout << "Size of the list is : " << size << "\n";
    }

    std::list<int>* get_data(){
        return &my_list;
    }
};

//! Example 2
class data_object {

public:
    void some_operation()
    {
        std::cout << "this is some operation \n";
    }
};


class data_wrapper{
    data_object protected_data;
    std::mutex m;

public:
    template <typename function>
    void do_some_work(function f){
        std::lock_guard<std::mutex> lg(m);
        f(protected_data);
    }
};

data_object* unprotected_data;

void malicious_function(data_object& data){
    unprotected_data = &data;
}

int main() {
    data_wrapper wrapper;
    wrapper.do_some_work(malicious_function);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
