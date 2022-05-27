#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream f("data.in");
ofstream g("data.out");


int main()
{
    int a, b, sum;

    f >> a >> b;
    sum = a + b;

    g << sum;

    a =5 , b = 8;
    int maximum;

    maximum = max(a,b);

    swap(a,b);

    cout << "a: " << a << ", b: " << b << endl;
    cout << "Max: " << maximum << endl;

    cout << "Hello world!" << endl;

    int number = 2;
    double cubicRoot;

    cubicRoot = pow((double)number, 1.0/3);

    cout << setprecision(10) << "Cubic Root: " << cubicRoot << endl;
    cout << "Cubic Root: " << cubicRoot << endl;
    return 0;
}
