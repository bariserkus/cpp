#include <iostream>
#include <thread>
#include <cmath>
#include <iomanip>
#include <future>



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
    packaged_task<double(int)> pt1(calculate_pi);

    future<double> f1 = pt1.get_future();
    
    thread t1(move(pt1), 1000);
    t1.join();

    try
    {
        double result = f1.get();
        cout << setprecision(15) << result << '\n';
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    









    return 0;
}