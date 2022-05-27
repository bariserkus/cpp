#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <cmath>
#include <iomanip>

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
    cout << setprecision(15) << calculate_pi(1E7) << "\n";

    return 0;
}