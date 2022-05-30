#include <iostream>
#include <list>
#include <algorithm>
#include <future>
#include <random>
#include <chrono>

template<typename T>
void printlist(std::list<T> l, int j){
    std::cout << j << " : " ;
    for(int i : l)
        std::cout << i << ' ';
    std::cout << '\n';
}

template<typename T>
std::list<T> seq_sort(std::list<T> input){
    if (input.size() < 2){
        return input;
    }

    std::list<T> result;
    result.splice(result.begin(), input, input.begin());
    T pivot = *result.begin();

    auto divide_point = std::partition(input.begin(), input.end(), [&](T const& t){
        return t < pivot;
    });

    std::list<T> lower_list;
    lower_list.splice(lower_list.end(), input, input.begin(), divide_point);

    auto new_lower(seq_sort(std::move(lower_list)));
    auto new_upper(seq_sort(std::move(input)));

    result.splice(result.begin(), new_lower);
    result.splice(result.end(), new_upper);

    return result;
}

template<typename T>
std::list<T> par_sort(std::list<T> input){
    if (input.size() < 2){
        return input;
    }

    //printlist(input, 0);

    std::list<T> result;
    result.splice(result.begin(), input, input.begin());
    T pivot = *result.begin();

    //printlist(input, 1);

    auto divide_point = std::partition(input.begin(), input.end(), [&](T const& t){
        return t < pivot;
    });

    //printlist(input, 2);
    //std::cout << "Divide Point : " << *divide_point << '\n';

    std::list<T> lower_list;
    lower_list.splice(lower_list.end(), input, input.begin(), divide_point);

    //printlist(lower_list, 3);
    //printlist(input, 4);

    std::future<std::list<T>> new_upper_future(std::async(&par_sort<T>, std::move(input)));
    auto new_lower(par_sort(std::move(lower_list)));


    result.splice(result.begin(), new_upper_future.get());
    result.splice(result.begin(), new_lower);

    return result;
}

void print_results(const char* const tag, const std::list<int>& sorted,
                   std::chrono::high_resolution_clock::time_point startTime,
                   std::chrono::high_resolution_clock::time_point endTime) {
    printf("%s: Lowest: %d Highest: %d Time: %fms\n", tag, sorted.front(),
           sorted.back(),
           duration_cast<std::chrono::duration<double, std::milli>>(endTime - startTime).count());
}

int main()
{
    const size_t  n = 1'000;
    std::random_device rd;

    // generate some random integers:
    //std::list<int> mylist{44, 52, 92, 32, 25, 27, 84, 33, 29, 23, 63, 34, 23, 75, 48, 42, 96, 53, 84, 72};
    printf("Testing with %zu integers...\n", n);
    std::list<int> mylist(n);
    for (auto& i : mylist) {
        i = static_cast<int>(rd());
    }
    std::list<int> mylist2 = mylist;

    {
        const auto startTime = std::chrono::high_resolution_clock::now();
        std::list<int> result = seq_sort(mylist);
        const auto endTime = std::chrono::high_resolution_clock::now();
        print_results("Serial STL ", result, startTime, endTime);
    }

    {
        const auto startTime = std::chrono::high_resolution_clock::now();
        std::list<int> result = par_sort(mylist2);
        const auto endTime = std::chrono::high_resolution_clock::now();
        print_results("Parallel STL ", result, startTime, endTime);
    }


/*
    std::cout << "My List:     ";
    for(int i : mylist)
        std::cout << i << ' ';

    std::cout << "\nSorted List: ";
    for(int i : result)
        std::cout << i << ' ';
*/
    return 0;
}