#include <iostream>

using namespace std;

int main()
{
    bool bVal = false;
    cout << bVal << endl;

    char cVal = 'c';
    char cVal2 = 'X';
    int testX =cVal2;

    cout << cVal << endl;
    cout << (int)cVal2 << endl;
    cout << (char)88 << endl;
    cout << testX << endl;

    wchar_t wVal = 'k';
    cout << (char)wVal << endl;

    return 0;
}
