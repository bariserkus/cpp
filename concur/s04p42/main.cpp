#include <iostream>
#include <tbb/tbb.h>
//#include <algorithm>
//#include <vector>
//#include <execution>


int main(){

    tbb::parallel_invoke(
            []() { std::cout << " Hello " << std::endl; },
            []() { std::cout << " TBB! " << std::endl; }
    );

    return 0;
}

/*
std::vector<int> v{0,2,5,2,-1};

std::cout << v[3] << '\n';

// standard sequential sort
std::sort(v.begin(), v.end());

// sequential execution
std::sort(std::execution::seq, v.begin(), v.end());
*/