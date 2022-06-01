#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <execution>
#include <memory>

#include "parallel_find.h"
#include "common_objs.h"
#include "utils.h"

const size_t testSize = 100'000'000;

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
    for (size_t i = 0; i < testSize; i++)
    {
        ints[i] = i;
    }

    int looking_for = 27'500'000;

    auto startTime = high_resolution_clock::now();
    auto value_pt = parallel_find_pt(ints.begin(), ints.end(), looking_for);
    auto endTime = high_resolution_clock::now();
    print_results("Parallel-package_task_impl :", startTime, endTime);

    /*
    std::atomic<bool> done_flag{0};
    startTime = high_resolution_clock::now();
    auto value_async = parallel_find_async(ints.begin(), ints.end(), looking_for, &done_flag);
    endTime = high_resolution_clock::now();
    print_results("Parallel-async_impl :", startTime, endTime);
     */

    startTime = high_resolution_clock::now();
    std::find(ints.begin(), ints.end(), looking_for);
    endTime = high_resolution_clock::now();
    print_results("STL sequential :", startTime, endTime);

    startTime = high_resolution_clock::now();
    std::find(std::execution::par,ints.begin(), ints.end(), looking_for);
    endTime = high_resolution_clock::now();
    print_results("STL parallel-par :", startTime, endTime);

    startTime = high_resolution_clock::now();
    std::find(std::execution::seq, ints.begin(), ints.end(), looking_for);
    endTime = high_resolution_clock::now();
    print_results("STL parallel-seq :", startTime, endTime);

    return 0;
}