
// C++ program to print largest contiguous array sum
#include<iostream>
#include<tuple>
#include<climits>
using namespace std;

tuple<int, int> find_buy_sell_stock_prices(int* a, int size) {
  int current_diff = -2147483648;
  int current_first = a[0];
  int global_second = a[1];
  int global_diff = global_second - current_first;

  for (int i = 1; i < size; ++i)
  {
      current_diff = a[i] - current_first;
      if(current_diff > global_diff)
      {
          global_diff = current_diff;
          global_second = a[i];
      }

      if(a[i] < current_first)
      {
          current_first = a[i];
      }
  }

  tuple<int, int> result(std::make_pair(global_second - global_diff, global_second));
  return result; // t is a tuple with (high, low) price values
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = {1, 2, 3, 4, 3, 2, 1, 2, 5};
    int n = sizeof(a)/sizeof(a[0]);
    tuple<int, int> result;

    result = find_buy_sell_stock_prices(a, n);
    cout << "Buy Price: "<< get<0>(result) << ", Sell Price: " << get<1>(result) << endl;
    return 0;
}
