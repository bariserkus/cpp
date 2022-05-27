#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <cmath>
#include <iomanip>
#include <future>

using namespace std;

double calculate_pi(int terms)
{
    double sum = 0.0;

    for(int i = 0; i < terms; ++i)
    {
        int sign = pow(-1, i);
        double term = sign * 1.0 / (i * 2 + 1);
        sum = sum + term;
    }
    return 4 * sum;
}

int main()
{
    promise<double> p;

    auto do_calculation = [&](int terms)
    {
        auto result = calculate_pi(terms);

        p.set_value(result);
    };
    
    thread t1(do_calculation, 1E7);
    t1.join();

    future<double> f = p.get_future();

    cout << setprecision(15) << f.get() << "\n";


    return 0;
}