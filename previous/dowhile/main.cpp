#include <iostream>

using namespace std;

int main()
{
    const string passcode = "mypass";
    string input;
    bool check;

    do{
        cout << "Enter passcode > " << flush;
        cin >> input;

        check = (input != passcode);
        if (check){ cout << "Pass rejected" << endl;}

    } while(check);

    cout << "Pass accepted" << endl;

    return 0;
}
