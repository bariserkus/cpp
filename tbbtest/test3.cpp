	#include <iostream>
	#include "oneapi/tbb.h"
	#include <execution>

	int main(){
	int sum = oneapi::tbb::parallel_reduce(oneapi::tbb::blocked_range<int>(1,101), 0,
	   [](oneapi::tbb::blocked_range<int> const& r, int init) -> int {
	      for (int v = r.begin(); v != r.end(); v++  ) {
		 init += v;
	      }
	      return init;
	   },
	   [](int lhs, int rhs) -> int {
	      return lhs + rhs;
	   }
	);

	std::cout << sum << '\n';

	return 0;
	}
