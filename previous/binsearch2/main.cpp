#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int s, int e, int key)
{
    int m;
    if (s <= e)
    {
        cout << "Test" << endl;
        m = (e - s) / 2 + s;

        if (arr[m] == key) return m;

        if (arr[m] > key) return binarySearch(arr, s, m-1, key);

        return binarySearch(arr, m+1, e, key);
    }
    return -1;
}

int main(void) {
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout<<"Key(3) found at: "<<binarySearch(v1, 0, v1.size(), 3)<<endl;
    cout<<"Key(6) found at: "<<binarySearch(v1, 0, v1.size(), 7)<<endl;

    return 0;

}
