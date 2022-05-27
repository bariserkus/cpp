#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float fVal = 123.456789;

    cout << fixed << fVal << endl;
    cout << scientific << fVal << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << setprecision(20) << fixed << fVal << endl;

    double dVal = 123.456789;
    cout << setprecision(20) << fixed << dVal << endl;
    cout << "Size of double: " <<  sizeof(double) << endl;

    return 0;
}
