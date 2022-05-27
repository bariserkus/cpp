#include<iostream>
#include<vector>

using namespace std;

class Pair
{
public:
    int first, second;
    Pair(int x, int y)
    {
        first = x;
        second = y;
    }
};

vector<Pair> merge_intervals(vector<Pair>& v)
{
    int len = v.size();
    if(len == 0) return v;

    vector<Pair> result;
    result.push_back(Pair(v[0].first, v[0].second));

    for (int i = 1; i < len; ++i)
    {
        if (v[i].first <= result[result.size()-1].second )
            result[result.size()-1].second = v[i].second;
        else if (v[i].first > result[result.size()-1].second)
            result.push_back(v[i]) ;
    }
    return result;
}


int main()
{
    vector<Pair> v
    {
        Pair(1, 5),
        Pair(3, 7),
        Pair(4, 6),
        Pair(6, 8),
        Pair(10, 12),
        Pair(11, 15)
    };

    vector<Pair> result = merge_intervals(v);

    for(int i = 0; i < (int) result.size(); i++)
    {
        cout << "[" << result[i].first << ", " << result[i].second << "] ";
    }
}
