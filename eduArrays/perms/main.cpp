/*
 * Permutations (medium)
 * Given a set of distinct numbers, find all of its permutations.
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Permutations {
public:
    static vector<vector<int>> findPermutations(const vector<int>& nums) {
        vector<vector<int>> result;
        std::vector<int>::iterator it;
        result[0].push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i){
            for (int j = 0; j < result.size(); ++j){
                for (int l = 1; l < )
                it = result[j].begin();
                while (it != )
                for ( k = 0; k < result[j].size(); ++k){
                    it = result[j].insert(it, );
                }
            }
        }


        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> result = Permutations::findPermutations(vector<int>{1, 3, 5});
    cout << "Here are all the permutations: " << endl;
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}
