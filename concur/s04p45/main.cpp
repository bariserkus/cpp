#include <iostream>
#include <chrono>
#include <execution>
#include <chrono>
#include "parallel_for_each.h"
#include "utils.h"

const size_t testSize = 100000;

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::milli;

void print_results(const char *const tag,
                   high_resolution_clock::time_point startTime,
                   high_resolution_clock::time_point endTime) {
    printf("%s: Time: %fms\n", tag, duration_cast<duration<double, milli>>(endTime - startTime).count());
}


int main()
{
    std::vector<int> ints(testSize);
    for (auto& i : ints) {
        i = 1;
    }

    auto long_function = []( const int& n )
    {
        int sum = 0;
        for (auto i = 0; i < 100000; i++)
        {
            sum += 1*(i-499);
        }
    };

    auto startTime = high_resolution_clock::now();
    std::for_each(ints.cbegin(), ints.cend(), long_function);
    auto endTime = high_resolution_clock::now();
    print_results("STL                   ", startTime, endTime);

    startTime = high_resolution_clock::now();
    for_each(std::execution::seq, ints.cbegin(), ints.cend(), long_function);
    endTime = high_resolution_clock::now();
    print_results("STL-seq               ", startTime, endTime);

    startTime = high_resolution_clock::now();
    std::for_each(std::execution::par, ints.cbegin(), ints.cend(), long_function);
    endTime = high_resolution_clock::now();
    print_results("STL-par               ", startTime, endTime);

    startTime = high_resolution_clock::now();
    parallel_for_each_pt(ints.cbegin(), ints.cend(), long_function);
    endTime = high_resolution_clock::now();
    print_results("Parallel-package_task ", startTime, endTime);

    startTime = high_resolution_clock::now();
    parallel_for_each_async(ints.cbegin(), ints.cend(), long_function);
    endTime = high_resolution_clock::now();
    print_results("Parallel-async        ", startTime, endTime);

    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;

    return 0;
}