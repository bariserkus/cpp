#include <iostream>

using namespace std;

int main()
{
    int one = 1;
    int two = 2;
    int three = 3;

    //Capture one and two by value
    [one, two](){ cout << one << "," << two << "Hello" << endl;}();

    //Capture all local varibles by values
    [=](){ cout << one << "," << two << "Hello" << endl;}();

    //Capture all local varibles by value but capture three by reference...
    [=, &three](){three=7; cout << one << "," << two << "Hello" << endl;}();
    cout << three << endl;

    //Capture all local varibles by reference...
    [&](){three=7; two=8; cout << one << "," << two << "Hello" << endl;}();
    cout << two << endl;

    //Capture all local varibles by reference...
    [&, two, three](){one=10; cout << one << "," << two << "Hello" << endl;}();
    cout << one << endl;

    cout << "Hello world!" << endl;
    return 0;
}
