#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <cmath>
#include <iomanip>
#include <future>
#include <exception>



using namespace std;

double calculate_pi(int terms)
{
    double sum = 0.0;

    if (terms < 1)
    {
        throw runtime_error("BE: Terms cannot be less than 1");
    }

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
        try
        {
            auto result = calculate_pi(terms);
            p.set_value(result);
        }
        catch(...)  //(const std::exception& e)
        {
            p.set_exception(current_exception());
            //std::cerr << e.what() << '\n';
        }
    };
    
    thread t1(do_calculation, 1E6);
    t1.join();

    future<double> f = p.get_future();

    try
    {
        cout << setprecision(15) << f.get() << "\n";
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    



    return 0;
}