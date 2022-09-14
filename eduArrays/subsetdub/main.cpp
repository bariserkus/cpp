/*
 * Subsets With Duplicates (easy)
 * Given a set of numbers that might contain duplicates, find all of its distinct subsets.
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class SubsetWithDuplicates {
public:
    static vector<vector<int>> findSubsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        vector<vector<int>> temp = subsets;
        subsets.push_back(vector<int>());
        for(int i = 0; i < nums.size(); ++i){
            if (nums[i] != nums[i-1]){
                temp = subsets;
            }
            int n = temp.size();
            for(int j = 0; j < n; ++j){
                temp[j].push_back(nums[i]);
            }
            subsets.insert(subsets.end(), temp.begin(), temp.end());
        }
        return subsets;
    }
};

int main(int argc, char* argv[]) {
    vector<int> vec = {1, 1, 1, 3, 3};
    vector<vector<int>> result = SubsetWithDuplicates::findSubsets(vec);
    cout << "Here is the list of subsets: " << endl;
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    vec = {1, 5, 3, 3};
    result = SubsetWithDuplicates::findSubsets(vec);
    cout << "Here is the list of subsets: " << endl;
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}