#include <iostream>

using namespace std;

int main()
{
    int values[3];
    values[0] = 5;
    //values[1] = 4;
    values[2] = 6;
    cout << "Values 0: " << values[0] << endl;
    cout << "Values 1: " << values[1] << endl;
    cout << "Values 2: " << values[2] << endl;

    double numbers[4] = {3.4, 2.7, 9.12, 29.2};

    for (int i = 0; i<4; i++){
        cout << "index of " << i << ": " << numbers[i] << endl;
    }

    double vals[4] = {}; // initialize o zeros

    for (int i = 0; i<4; i++){
        cout << "index of " << i << ": " << vals[i] << endl;
    }

    string names[] = {"baris", "emek", "leyla"};

    for (int i = 0; i<3; i++){
        cout << "index of " << i << ": " << names[i] << endl;
        cout << "index of " << i << ": " << names[i][2] << endl;
    }

    cout << *(values+2) << endl;

    return 0;
}
