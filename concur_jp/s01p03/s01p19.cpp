#include <iostream>
#include <thread>
#include <queue>

using namespace std;

template<typename E>
class blocking_queue
{
private:
    int _max_size;
    queue<E> _queue;

public:
    blocking_queue(int ms): _max_size(ms)
    {

    }
    void push(E e)
    {
        _queue.push(e);
//        cout << "push" << '\n';
    }

    E pop()
    {
        E item = _queue.front();
        _queue.pop();
//        cout << "pop" << '\n';
        return item;
    }
};

int main()
{
    blocking_queue<int> qu(5);

    thread t1([&](){
        for(int i = 0; i < 10; i++)
        {
            qu.push(i);
        }
    });
    thread t2([&](){
        for(int i = 0; i < 10; i++)
        {
            auto item =qu.pop();
            cout << "Consumed item :" << item << '\n';
        }
    });

    t1.join();
    t2.join();
    
    return 0;
}
