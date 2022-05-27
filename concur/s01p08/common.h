//
// Created by bariserkus on 09.05.2022.
//

#ifndef S01P08_COMMON_H
#define S01P08_COMMON_H

#include <vector>
#include <thread>

class thread_guard{
    std::thread& t;
public:
    explicit thread_guard(std::thread & _t) : t(_t){}
    ~thread_guard(){
        if(t.joinable()){
            std::cout << "In the thread guard destructor" << std::endl;
            t.join();
        }
    }
    thread_guard(thread_guard &) = delete;
    thread_guard& operator= (thread_guard &) = delete;

};


#endif //S01P08_COMMON_H
