#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>

using namespace std;

int main()
{
    condition_variable c;
    mutex m;
    bool ready{false};

    thread t1([&](){
        this_thread::sleep_for(chrono::milliseconds(3000));

        cout << "t1 acquiring lock\n";
        unique_lock<mutex> ul(m);
        cout << "t1 acquired lock\n";
        ready = true;
        ul.unlock();
        cout << "t1 released lock; notifying \n";
        c.notify_one();
    });

    cout << "main thread acquiring lock\n";
    unique_lock<mutex> ul(m);

    cout << "main thread acquired lock; waiting \n";
    c.wait(ul, [&](){return ready;});

    cout << "main thread finished waiting \n";
    cout << "Ready : " << ready << '\n';
    
    t1.join();
    return 0;
}