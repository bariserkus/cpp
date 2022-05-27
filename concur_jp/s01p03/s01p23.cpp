#include <iostream>
#include <future>
#include <chrono>
#include <vector>
#include <mutex>
#include <thread>
#include <queue>
#include <cmath>

using namespace std;

mutex m, mm;

template <typename E>
class blocking_queue
{
private:
    mutex _m;
    condition_variable _c;
    int _max_size;
    queue<E> _queue;

public:
    blocking_queue(int ms) : _max_size(ms)
    {
    }
    void push(E e)
    {
        unique_lock<mutex> lock(_m);

        _c.wait(lock, [&]()
                { return (int)_queue.size() < _max_size; });
        _queue.push(e);

        lock.unlock();
        _c.notify_one();
    }

    E front()
    {
        unique_lock<mutex> lock(_m);

        _c.wait(lock, [&]()
                { return !_queue.empty(); });

        return _queue.front();
    }

    void pop()
    {
        unique_lock<mutex> lock(_m);
        _c.wait(lock, [&]()
                { return !_queue.empty(); });

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

int work(int id)
{
    unique_lock<mutex> lock(m);
    cout << "Starting " << id << '\n';
    lock.unlock();

    int seconds = (int)((5.0 * rand()) / RAND_MAX + 3);

    this_thread::sleep_for(chrono::seconds(seconds));

    lock.lock();
    cout << "Ending " << id << '\n';
    lock.unlock();

    return id * 5;
}

int main()
{
    blocking_queue<shared_future<int>> futures(2);

    thread t([&](){
        for (int i = 0; i < 20; ++i)
        {
            shared_future<int> f = async(launch::async, work, i);
            futures.push(f);
        }
    });

    unique_lock<mutex> lock(mm);
    for (int i = 0; i < 20; ++i)
    {
        shared_future<int> f = futures.front();
        int value = f.get();
        futures.pop();
        cout << "Returned " << value << '\n';
    }
    lock.unlock();

    t.join();

    return 0;
}
