using namespace std;

#include <iostream>
#include <vector>

void swp(int* a, int* b);

class CyclicSort {
 public:
  static void cycsort(vector<int> &a) {
    int s = a.size();
    for (int i = 0; i < s; ++i)
    {
        cout << "i: "<< i << endl;
        if (a[i] != i)
        {
            swp(&a[i], &a[a[i]]);
            --i;
        }
    }
  }
};

void swp(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(int argc, char *argv[]) {
  vector<int> arr = {3, 1, 5, 4, 2};
  CyclicSort::cycsort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;

  arr = vector<int>{2, 6, 4, 3, 1, 5};
  CyclicSort::cycsort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;

  arr = vector<int>{1, 5, 6, 4, 3, 2};
  CyclicSort::cycsort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

