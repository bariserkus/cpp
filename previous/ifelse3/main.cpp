#include <iostream>

using namespace std;

int main()
{
    cout << "1.\tAdd new record" << endl;
    cout << "2.\tDelete record" << endl;
    cout << "3.\tView record" << endl;
    cout << "4.\tSearch record" << endl;
    cout << "5.\tQuit" << endl;

    cout << "Enter your selection > " << flush;

    int val;
    cin >> val;

    if(val == 1)
    {
        cout << "Adding new record ..." << endl;
    }
    else if(val == 2)
    {
        cout << "Deleting record ..." << endl;
    }
    else if(val == 3)
    {
        cout << "Viewing record ..." << endl;
    }
    else if(val == 4)
    {
        cout << "Searching record ..." << endl;
    }
    else if(val == 5)
    {
        cout << "Quitting ..." << endl;
    }
    else
    {
        cout << "Invalid Option!" << endl;
    }
    return 0;
}
