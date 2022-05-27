#include <iostream>
#include <execution>
#include <algorithm>
#include <vector>



int main(){
   std::vector<int> v{0,2,5,2,-1};

   std::cout << v[3] << '\n';

   // standard sequential sort
   std::sort(v.begin(), v.end());

   // sequential execution
   std::sort(std::execution::par, v.begin(), v.end());

   return 0;
}
