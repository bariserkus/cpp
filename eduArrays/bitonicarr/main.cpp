/*
 * Bitonic Array Maximum (easy)
 * Find the maximum value in a given Bitonic array.
 * An array is considered bitonic if it is monotonically increasing and then monotonically decreasing.
 * Monotonically increasing or decreasing means that for any index i in the array arr[i] != arr[i+1].
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MaxInBitonicArray {
public:
    static int findMax(const vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int middle;
        int result;

        while (end != start){
            middle = (start + end)/2;
            if (arr[middle] > arr[middle+1]){
                end = middle;
            } else if (arr[middle < arr[middle+1]]){
                start = middle + 1;
            }
            if (start == end){
                result = start;
            }
        }
        return arr[result];
    }

};

int main(int argc, char* argv[]) {
    cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12, 4, 2}) << endl;
    cout << MaxInBitonicArray::findMax(vector<int>{3, 8, 3, 1}) << endl;
    cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12}) << endl;
    cout << MaxInBitonicArray::findMax(vector<int>{10, 9, 8}) << endl;
}
