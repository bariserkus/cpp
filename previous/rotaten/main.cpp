#include <iostream>
#include <vector>


using namespace std;

void swapval(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void reversevec(vector<int>& v, int s, int e)
{
    while (s < e)
    {
        swap(v[s], v[e]);
        ++s;
        --e;
    }
}

void rotatevec(vector<int>& v, int n)
{
    int len = v.size();

    if (n > len) n = n%len;
    if (n < 0) n = len + n;
    if (n < len)
    {
        reversevec(v,0,len-1);
        reversevec(v,0,n-1);
        reversevec(v,n,len-1);
    }
    if (n == len || n == 0); // Do nothing
}

int main()
{
    vector<int> v = {1, 2, 3, 5, 6, 7, 10, 25, 30, 63};
    int n = -3;
    rotatevec(v,n);
    //reversevec(v, 0, v.size()-1);


    cout << "Vector is: ";
    for (int i:v) cout << i << ' ';
    cout << endl;
    return 0;
}
