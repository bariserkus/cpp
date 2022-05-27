#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

template<typename E>
class blocking_queue
{
private:
    mutex _m;
    condition_variable _c;
    int _max_size;
    queue<E> _queue;

public:
    blocking_queue(int ms): _max_size(ms)
    {

    }
    void push(E e)
    {
        unique_lock<mutex> lock(_m);

        _c.wait(lock, [&](){return (int)_queue.size() < _max_size;});
        _queue.push(e);

        lock.unlock();
        _c.notify_one();
    }

    E front()
    {
        unique_lock<mutex> lock(_m);

        _c.wait(lock, [&](){return !_queue.empty();});
        
        return _queue.front();
    }

    void pop()
    {
        unique_lock<mutex> lock(_m);
        _c.wait(lock, [&](){return !_queue.empty();});

        _queue.pop();

        lock.unlock();
        _c.notify_one();

    }

    int size()
    {
        lock_guard<mutex> lock(_m);
        return _queue.size();
    }
};

int main()
{
    blocking_queue<int> qu(5);

    thread t1([&](){
        for(int i = 0; i < 10; i++)
        {
            cout << "Pushing " << i <<  '\n';
            cout << "Queue size : " << qu.size()<< '\n';
            qu.push(i);
        }
    });
    thread t2([&](){
        for(int i = 0; i < 10; i++)
        {
            auto item =qu.front();
            qu.pop();
            cout << "Consumed item :" << item << '\n';
        }
    });

    t1.join();
    t2.join();
    
    return 0;
}
