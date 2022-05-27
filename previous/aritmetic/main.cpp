#include <iostream>

using namespace std;

/*

*/


int main()
{
    double value1 = (double) 7/2;
    cout << value1 << endl;

    int value2 = (int)7.3;

    cout << value2 << endl;

    int value3 = 8;



    int value5 = 12%5;
    cout << value5 << endl;

    value3 += 1; // value3 + value3 + 1; value++;
    cout << "value3: " << value3 << endl;

    int value4 = value3++;
    cout << "value4 :" << value4 << endl;
    cout << "value3 :" << value3 << endl;

    int value6 = ++value3;
    cout << "value6 :" << value6 << endl;
    cout << "value3 :" << value3 << endl;


    return 0;
}
