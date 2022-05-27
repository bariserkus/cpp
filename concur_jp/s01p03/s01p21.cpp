#include <iostream>
#include <future>
#include <chrono>

using namespace std;

int work(int id)
{
    for(int i = 0; i < 5; i++)
    {
        cout << "Running : " << id << '\n' ;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    return id*7;


}



int main()
{
    future<int> f1 = async(launch::async, work, 0);
    future<int> f2 = async(launch::async, work, 1);

    cout << "F1.get: " << f1.get() << '\n';
    cout << "F2.get: " <<  f2.get() << '\n';

    return 0;
}
