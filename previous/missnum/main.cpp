#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class MissingNumber
{
public:
    static int findMissingNumber(vector<int> &a)
    {

        int s = a.size();

        vector<int> v(s+1);
        iota(std::begin(v), std::end(v), 0);

        for (int i = 0; i < s; ++i)
        {
            v[a[i]] = -1;
        }


        for (int i = 0; i < s+1; ++i)
        {
            if (v[i] > 0) return v[i];
        }

        return -1;
    }
};


int main(int argc, char *argv[])
{
    vector<int> v1 = {4, 0, 3, 1};
    cout << MissingNumber::findMissingNumber(v1) << endl;
    v1 = {8, 3, 5, 2, 4, 6, 0, 1};
    cout << MissingNumber::findMissingNumber(v1) << endl;
}
