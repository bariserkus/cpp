#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
public:
    static int findMaxSumSubArray(int k, const std::vector<int>& arr) {
        int maxSum = 0;
        int curSum = 0;
        int n = arr.size();
        for (int j = 0; j < n; ++j){
            curSum += arr[j];
            if (j >= k - 1) {
                maxSum = std::max(curSum, maxSum);
                curSum -= arr[j-(k-1)];
            }
        }
        return maxSum;
    }
};


int main() {
    std::vector<int> myarr {1, 2, 3, 4, 3, 9, 7, 6, 5, 8, 6, 4 };
    int k = 3;
    int mymax;
    MaxSumSubArrayOfSizeK m;
    mymax = m.findMaxSumSubArray(k, myarr);

    std::cout << "My Max :" << mymax <<std::endl;
    return 0;
}
