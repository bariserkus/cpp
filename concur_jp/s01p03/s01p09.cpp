#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>

using namespace std;

class App
{
private:
    int count{0};
    mutex m;

public:
    void operator()()
    {
        for (int i = 0; i < 1E6; ++i)
        {
            const lock_guard<mutex> lg(m);
            ++count;
        }
    }

    int getCount()
    {
        return count;
    }
};

int main()
{
    App a;

    thread t1(ref(a));
    thread t2(ref(a));

    t1.join();
    t2.join();

    // this_thread::sleep_for(chrono::milliseconds(5000));

    cout << a.getCount() << "\n";

    return 0;
}