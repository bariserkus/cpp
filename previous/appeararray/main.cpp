#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream f("data.in");
ofstream g("data.out");

int A[100];

int main()
{
    int n, x, maxim;
    f >> n;

    for (int i=1; i<=n; ++i)
    {
        f>>x;
        ++A[x];
        maxim = max(maxim, x);
    }

    for (int j=0; j<10; ++j) cout << A[j] << " ";
    cout << endl;

    if(A[3] > 0) g<< "YES, it appears";
    else g<< "NO, it does not appear";

    for (int i=0; i<=maxim; ++i)
    {
        if (A[i]>0)
        {
            for (int j=1; j<=A[i]; ++j)
                cout << i << " ";
        }
    }
    cout << endl;
    cout << "Hello world!" << endl;
    return 0;
}
