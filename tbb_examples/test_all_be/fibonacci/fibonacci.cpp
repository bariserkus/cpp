/*
    Copyright (c) 2005-2022 Intel Corporation

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/* Example program that computes Fibonacci numbers in different ways.
   Arguments are: [ Number [Threads [Repeats]]]
   The defaults are Number=500 Threads=1:4 Repeats=1.

   The point of this program is to check that the library is working properly.
   Most of the computations are deliberately silly and not expected to
   show any speedup on multiprocessors.
*/

// enable assertions
#ifdef NDEBUG
#undef NDEBUG
#endif
#include <iostream>
#include <vector>
#include "oneapi/dpl/algorithm"
#include "oneapi/dpl/execution"

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 10, 20, 4 };

    std::sort(std::execution::seq, vec.begin(), vec.end()); // sequential
    std::sort(std::execution::par, vec.begin(), vec.end()); // parallel

    std::cout << "Test 3" << '\n';

    return 0;
}