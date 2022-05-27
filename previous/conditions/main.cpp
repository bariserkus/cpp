#include <iostream>

using namespace std;

int main()
{
    int val1 = 5;
    int val2 = 7;
    cout << "Hello world!" << endl;

    if (val1 == 5 || val2 == 8){
        cout << "Cond is satisfied" << endl;
    } else {
        cout << "Cond is not satisfied" << endl;
    }

    bool cond1 = val1 != val2;
    bool cond2 = val2 == val2;

    cout << "Cond1 = " << cond1 << endl;

    if (cond1 || cond2){
        cout << "Test condition" << endl;
    }

    return 0;
}
