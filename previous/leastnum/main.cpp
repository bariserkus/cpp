#include <iostream>
#include <vector>


using namespace std;

int find_least_common_number(vector<int>& v1, vector<int>& v2, vector<int>& v3)
{
    decltype(v1.size()) i = 0, j = 0, k = 0;

    while (i < v1.size() && j < v2.size() && k < v3.size())
    {
        if(v1[i] == v2[j] && v2[j] == v3[k]) return v1[i];

        if (v1[i] < v2[j] && v1[i] < v3[k]) ++i;
        else if (v2[j] < v1[i] && v2[j] < v3[k]) ++j;
        else if (v3[k] < v1[i] && v3[k] < v2[j]) ++k;
        else if (v1[i] == v2[j] && v1[i] < v3[k]) {++i; ++j;}
        else if (v1[i] == v3[k] && v1[i] < v2[j]) {++i; ++k;}
        else if (v2[j] == v3[k] && v2[j] < v1[i]) {++j; ++k;}
    }
    return -1;
}

int main()
{
  vector<int> v1 = {1, 2, 3, 5, 6, 7, 10, 25, 30, 63, 64};
  vector<int> v2 = {0, 3, 4, 5, 6, 7, 8, 50};
  vector<int> v3 = {1, 3, 4, 6, 7, 10, 14};
    cout << "Common Number is: " << find_least_common_number(v1, v2, v3) << endl;
    return 0;
}
