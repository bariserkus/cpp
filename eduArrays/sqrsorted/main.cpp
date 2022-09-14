/*
 * Squaring a Sorted Array (easy)
 * Given a sorted array, create a new array containing squares of
 * all the numbers of the input array in the sorted order.
 */
#include <iostream>
#include <vector>

using namespace std;

class SortedArraySquares {
public:
    static vector<int> makeSquares(const vector<int> &arr) {
        int n = (int) arr.size();
        vector<int> squares(n);

        vector<int>::const_iterator frwit = arr.begin();
        vector<int>::const_iterator bckit;

        int sqrsi = 0;
        if(arr.front() >= 0){
            cout << "All members are positive" << "\n";
            for(int i = 0; i < n; ++i){
                squares[i] = arr[i] * arr[i];
            }
        } else if (arr.back() < 0){
            cout << "All members are negative" << "\n";
            for(int i = 0; i < n ; ++i){
                squares[n-i-1] = arr[i] * arr[i];
            }
        } else {
            cout << "There are positive and negative numbers" << "\n";
            while (frwit != arr.end()) {
                if (*frwit >= 0) {
                    bckit = frwit - 1;
                    break;
                }
                ++frwit;
            }
            while (frwit != arr.end() && bckit != --arr.begin()) { //{-8, -6, -5, -2, -1, 0, 2, 3, 4, 5, 12, 20, 25, 30}
                if (*frwit < -(*bckit)) {
                    squares[sqrsi++] = (*frwit) * (*frwit);
                    ++frwit;
                } else if (*frwit > -(*bckit)) {
                    squares[sqrsi++] = (*bckit) * (*bckit);
                    --bckit;
                } else if (*frwit == -(*bckit)) {
                    squares[sqrsi++] = (*frwit) * (*frwit);
                    squares[sqrsi++] = (*bckit) * (*bckit);
                    ++frwit;
                    --bckit;
                }
            }
            if (frwit == arr.end()) {
                while (bckit != arr.begin()) {
                    squares[sqrsi++] = (*bckit) * (*bckit);
                    --bckit;
                }
                squares[sqrsi++] = (*bckit) * (*bckit);
            } else if (bckit == --arr.begin()) {
                while (frwit != arr.end()) {
                    squares[sqrsi++] = (*frwit) * (*frwit);
                    ++frwit;
                }
            }
        }
        return squares;
    }
};


int main(int argc, char *argv[]) {
    vector<int> result = SortedArraySquares::makeSquares(vector<int>{-8, -6, -5, -2, -1, 0, 2, 3, 4, 5, 12, 20, 25, 30});
    for (auto num: result) {
        cout << num << " ";
    }
    cout << endl;

    result = SortedArraySquares::makeSquares(vector<int>{-3, -1, 0, 1, 2});
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    result = SortedArraySquares::makeSquares(vector<int>{-5, -4, -3, -1 });
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    result = SortedArraySquares::makeSquares(vector<int>{0, 1, 2, 5, 7});
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;


}