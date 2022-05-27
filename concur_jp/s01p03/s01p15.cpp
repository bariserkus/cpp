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
        this_thread::sleep_for(chrono::milliseconds(5000));
        unique_lock<mutex> ul(m);
        ready = true;
        ul.unlock();
        c.notify_one();
    });

    unique_lock<mutex> ul(m);

    while(!ready)
    {
        cout << "In the while loop\n";
        c.wait(ul);
        
    }

    cout << "Ready : " << ready << '\n';
    
    t1.join();
    return 0;
}