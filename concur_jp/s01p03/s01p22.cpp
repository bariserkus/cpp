#include <iostream>
#include <future>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

mutex m, mm;

int work (int id)
{
    unique_lock<mutex> lock(m);
    cout << "Starting " << id << '\n';
    lock.unlock();

    this_thread::sleep_for(chrono::seconds(3));
    
    lock.lock();
    cout << "Ending " << id << '\n';
    lock.unlock();

    return id*5;

}

int main()
{
    vector<shared_future<int>> futures;

    for (int i = 0; i < (int)thread::hardware_concurrency(); ++i)
    {
        shared_future<int> f = async(launch::async, work, i);
        futures.push_back(f);
    }
    unique_lock<mutex> lock(mm);
    for(auto f:futures)
    {
        cout << "Returned " << f.get() << '\n';
    }
    lock.unlock();

    return 0;
}
