#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int val = 21318;
    cout << val << endl;
    cout << "Max int value:" << INT_MAX << endl;
    cout << "Min int value:" << INT_MIN << endl;

    long int longVal = 242342709;
    cout << longVal << endl;
    cout << "Max long int value:" << LONG_MAX << endl;
    cout << "Min long int value:" << LONG_MIN << endl;

    long long int longlongVal = 242342709769;
    cout << longlongVal << endl;
    cout << "Max long long int value:" << LLONG_MAX << endl;
    cout << "Min long long int value:" << LLONG_MIN << endl;

    cout << "Size of int: " << sizeof(int) << endl;

    return 0;
}
