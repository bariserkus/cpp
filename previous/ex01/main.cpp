#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> find_max_sliding_window(vector<int>& v, int window_size)
{
    vector<int> result;
    int n = v.size() - window_size;
    for (auto i=0; i <= n ; ++i)
    {
        //cout << "i = " << i << endl;
        int* pFirst = &v[i];
        int* pLast = &v[i+window_size];
        int* pMaxVal = max_element(pFirst,pLast);
        result.push_back(*pMaxVal);
        //cout << *pMaxVal << endl;
    }
    return result;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 3, 2, 1, 2, 5};
    auto res = find_max_sliding_window(vec, 4);

    cout << "Max = ";
    for(int i = 0; i < (int) res.size(); ++i)
        cout << res[i] << ", ";
    cout << endl;

    return 0;
}


