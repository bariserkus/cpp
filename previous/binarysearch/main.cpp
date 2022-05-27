#include <bits/stdc++.h>
#include <iostream>
using namespace std;

ifstream f("data.in");
ofstream g("data.out");

int A[1000], nElements;

int BinSearch(int X)
{
    int Left = 1, Right = nElements, mid;

    while (Left <= Right)
    {
        mid = (Left + Right)/2;
        if (X == A[mid]) return mid;
        else if(X < A[mid]) Right = mid - 1;
        else if(X > A[mid]) Left = mid + 1;
    }
    return -1;
}

int main()
{
    int myNum = 5;
    f >> nElements;

    cout << nElements << endl;

    for (int i=1; i<=nElements; ++i)
    {
        f >> A[i];
        cout << A[i]<< endl;
    }

    cout << "Binary Search of " << myNum << " is : " << BinSearch(myNum) << endl;


    return 0;
}
