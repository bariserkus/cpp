#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool find_sum_of_two(vector<int>& A, int val)
{
    unordered_set<int> h;
    for (const int& a: A)
    {
        if (h.find(val-a) != h.end())
            return true;
        h.insert(a);
    }
    return false;
}

int main() {
  vector<int> v = {5, 7, 1, 2, 8, 4, 3};
  vector<int> test = {3, 20, 1, 2, 7};

  for(int i=0; i<(int)test.size(); i++){
    bool output = find_sum_of_two(v, test[i]);
    cout << "find_sum_of_two(v, " << test[i] << ") = " << (output ? "true" : "false") << endl;
  }
  return 0;
}
