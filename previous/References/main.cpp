#include <iostream>

using namespace std;

void changeSmtg(double &value)
{
    value = 123.4;
}

int main()
{
    int value1 = 8;
    int &value2 = value1;
    value2 = 10;

    cout << "Value1 : " << value1 << endl;
    cout << "Value2 : " << value2 << endl;

    double value = 4.321;
    //double &rValue = value;
    changeSmtg(value);

    cout << value << endl;
    return 0;
}
