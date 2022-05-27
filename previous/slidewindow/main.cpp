#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> find_max_sliding_window(vector<int>& v, int window_size)
{
    vector<int> result;
    deque<int> w;
    int i, k = window_size;

    cout << "Vector : ";
    for (int j: v) cout << j << ' ';
    cout << endl;

    for (i=0; i < k; ++i)
    {

        while(!w.empty() && (v[i] >= v[w.back()]) )
        {
            w.pop_back();
        }
        w.push_back(i);
        cout << "i = " << i << "-> Deque: ";
        for (int j: w) cout << j << ' ';
        cout << endl;
    }
    result.push_back(v[w.front()]);

    cout << "Result: ";
    for (int j: result) cout << j << ' ';
    cout << endl;

    for (; i < (int)v.size(); ++i)
    {


        while(!w.empty() && (w.front() <= i - k) )
        {
            w.pop_front();
        }

        while(!w.empty() && (v[i] >= v[w.back()]) )
        {
            w.pop_back();
        }
        w.push_back(i);
        result.push_back(v[w.front()]);
        cout << "i = " << i << "-> Deque: ";
        for (int j: w) cout << j << ' ';
        cout << " | " << "Result: ";
        for (int j: result) cout << j << ' ';
        cout << endl;
    }
    return result;
}

int main()
{
    vector<int> x = {8, 6, 9, -3, 23, -1, 34, 56, 67, -1, -4, -8, -2, 9, 10, 34, 67};
    auto res = find_max_sliding_window(x, 3);
    cout << "Result: ";
    for (int j: res) cout << j << ' ';
    return 0;
}
