#include <iostream>

using namespace std;

void manip(double value)
{
    cout << "3. Value : " << value << endl;
    value = 10.0;
    cout << "4. Value : " << value << endl;
}

void manipptr(double *value)
{
    cout << "3. Value : " << *value << endl;
    *value = 10.0;
    cout << "4. Value : " << *value << endl;
}

int main()
{
    int nValue = 9;

    int *ptrValue = &nValue;

    cout << "Int Value: " << nValue << endl;
    cout << "Pointer to address: " << ptrValue << endl;

    *ptrValue = 10;
    cout << "Int Value: " << nValue << endl;

    int * ptrRandom;
    cout << "Random Pointer : " <<  ptrRandom << endl;
    cout << "Random Pointer to Value : " <<  *ptrRandom << endl;

    double dValue = 123.4;

    cout << "1. dValue :" << dValue << endl;
    manip(dValue);
    cout << "4. dValue :" << dValue << endl;

    cout << "1. dValue :" << dValue << endl;
    manipptr(&dValue);
    cout << "4. dValue :" << dValue << endl;

    return 0;
}

