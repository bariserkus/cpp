#include <iostream>
#include <future>
#include <chrono>
#include <vector>
#include <mutex>
#include <cmath>
#include <iomanip>

#define M_PI 3.14159265358979323846

using namespace std;

double calculate_pi(int terms, int start, int skip)
{
    double sum = 0.0;

    for(int i = start; i < terms; i+=skip)
    {
        int sign = pow(-1, i);
        double term = sign * 1.0 / (i * 2 + 1);
        sum = sum + term;
    }
    return 4 * sum;
}

int main()
{
    vector<shared_future<double>> futures;

    const int CONCURRENCY = 12; //(int)thread::hardware_concurrency();

    auto start = chrono::steady_clock::now();

    for (int i = 0; i < CONCURRENCY; ++i)
    {
        shared_future<double> f = async(launch::async, calculate_pi, 1E7, i, CONCURRENCY);
        futures.push_back(f);
    }

    double sum = 0.0;
    
    for(auto f:futures)
    {
        sum += f.get();
    }

    auto end = chrono::steady_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end-start).count();

    cout << "Duration: " << duration << " miliseconds" << '\n';
    cout << setprecision(15) << "PI:  " << M_PI << '\n';
    cout << setprecision(15) << "Sum: " << sum << '\n';

    return 0;
}
