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
