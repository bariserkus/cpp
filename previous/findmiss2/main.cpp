using namespace std;

#include <iostream>
#include <vector>

void swp(int* a, int* b);

class CyclicSort {
 public:
  static int cycsort(vector<int> &a) {
    int s = a.size();
    for (int i = 0; i < s; ++i)
    {
        if (a[i] != i && a[i] < s)
        {
            swp(&a[i], &a[a[i]]);
            --i;
        }
    }

    for (int i = 0; i < s; ++i)
        if (a[i] != i) return i;

    return -1;
  }
};

void swp(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(int argc, char *argv[]) {
  vector<int> arr = {3, 1, 5, 2, 0};
  cout << CyclicSort::cycsort(arr) << endl;

  arr = vector<int>{2, 6, 4, 3, 1, 0};
  cout << CyclicSort::cycsort(arr) << endl;

  arr = vector<int>{1, 5, 6, 4, 2, 0, 7, 8, 9};
  cout << CyclicSort::cycsort(arr) << endl;

return 0;
}

