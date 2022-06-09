#include <iostream>
#include <vector>
#include <atomic>
#include <functional>
#include <future>
#include "thread_safe_q.h"
#include "common.h"
#include "utils.h"

class thread_pool{
private:
    std::atomic_bool done;
    threadsafe_queue<std::function<void()>> work_queue;
    std::vector<std::thread> threads;
    join_threads joiner;

    void worker_thread(){
        while (!done){
            std::function<void()> task;
            if (work_queue.try_pop(task)){
                task();
            } else {
                std::this_thread::yield();
            }
        }
    }

public:
    thread_pool():done(false), joiner(threads){
        int const thread_count = std::thread::hardware_concurrency();
        try{
            for (int i = 0; i < thread_count; ++i){
                threads.push_back(std::thread(&thread_pool::worker_thread, this));
            }
        } catch (...) {
            done = true;
            throw;
        }
    }

    ~thread_pool(){
        done = true;
    }

    template<typename Function_type>
    void submit(Function_type f)
    {
        work_queue.push(std::function<void()>(f));
    }

};

int main() {

    thread_pool pool;
    std::cout << "Testing Thread Pool" << '\n';
    for (int i = 0; i < 100; ++i){
        pool.submit([=]{
            printf(" %d printed by thread - %d \n", i, std::this_thread::get_id());
        });
    }

    int c = getchar();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
