#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class MinSizeSubArraySum {
public:
    static int findMinSubArray(int S, const vector<int>& arr) {

        int n_arr{(int)arr.size()};
        int min_len{numeric_limits<int>::max()};

        int start{0};
        int end{0};

        int sum{arr[start]};
        int prev_val{0};
        int curr_len{2};

        for (start; start < n_arr; ++start){
            curr_len -= 1;
            sum = sum - prev_val;
/*            cout << "[FOR] start: " << start << ", end: " << end <<
                 ", arr[start]: " << arr[start] <<
                 ", arr[end]: " << arr[end] <<
                 ", sum: " << sum <<
                 ", curr_len: " << curr_len << ", min_len: " << min_len << '\n'; */       while(sum < S && end < n_arr-1){
                ++end;
                sum += arr[end];
                curr_len = end - start + 1;
/*                cout << "[WHL] start: " << start << ", end: " << end <<
                ", arr[start]: " << arr[start] <<
                ", arr[end]: " << arr[end] <<
                ", sum: " << sum <<
                ", curr_len: " << curr_len << ", min_len: " << min_len << '\n'; */       }
            if (end < n_arr && sum >= S) {
                min_len = min(min_len, curr_len);
                prev_val = arr[start];
            }
/*            cout << "[OUT] start: " << start << ", end: " << end <<
                 ", arr[start]: " << arr[start] <<
                 ", arr[end]: " << arr[end] <<
                 ", sum: " << sum <<
                 ", curr_len: " << curr_len << ", min_len: " << min_len << '\n'; */       if (end == n_arr-1 && (start == end || sum < S)){
                break;
            }
        }
        return min_len;
    }
};

int main() {
    int result;
    result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 8});
    cout << "Smallest subarray length: " << result << endl;
    result = MinSizeSubArraySum::findMinSubArray(6, vector<int>{2, 1, 5, 2, 3, 2});
    cout << "Smallest subarray length: " << result << endl;
    result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{2, 1, 5, 2, 3, 2});
    cout << "Smallest subarray length: " << result << endl;
    result = MinSizeSubArraySum::findMinSubArray(9, vector<int>{3, 4, 1, 1, 6});
    cout << "Smallest subarray length: " << result << endl;    return 0;
}
