#include <iostream>
#include "utils.h"

using namespace std;

int main()
{
    int myVal = 5;
    showMenu();
    myVal = getVal(myVal);
    cout << "MyValue: " << myVal << endl;
    return 0;
}


void showMenu()
{
    cout << "Show Menu" << endl;
}

int getVal(int val)
{
    val = val * 2;
    return val;
}
