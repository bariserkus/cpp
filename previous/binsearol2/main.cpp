#include <iostream>
#include <vector>
using namespace std;

int binarySearchRot(vector<int>& arr, int s, int e, int key)
{
    int m;
    if (s <= e)
    {
        m = (e - s) / 2 + s;

        if (arr[m] == key) return m;

        if ( (arr[m] > arr[s] && key > arr[s] && key < arr[m]) || (arr[m] > arr[e]) )
        {
            cout << "Test-A" << endl;
            return binarySearchRot(arr, s, m-1, key);
        }

        if ( (arr[m] < arr[e] && key > arr[m] && key < arr[e]) || (arr[m] < arr[s]) )
        {
            cout << "Test-B" << endl;
            return binarySearchRot(arr, m+1, e, key);
        }
        //return binarySearchRot(arr, m+1, e, key);
    }
    return -1;
}

int main(void) {
    vector<int> v1 = {14, 15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    cout<<"Key(2) found at: "<< binarySearchRot(v1, 0, v1.size(), 2)<<endl;

    return 0;

}
