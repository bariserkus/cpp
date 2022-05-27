#include <iostream>

using namespace std;

int main()

{
    string animals[][3] = {
        {"cat", "dog", "mouse"} ,
        {"squirrel", "parrot", "lion"},
    };
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            cout << animals[i][j] << "(" << sizeof(animals[i][j]) << ")" << " " << flush;
            cout << animals[i][j][2] << "(" << sizeof(animals[i][j][1]) << ")" << " "  << flush;
        }
        cout << endl;
    }

    int values[] = {4, 7, 3, 4};

    cout << sizeof(values) << endl;
    cout << sizeof(int) << endl;

    for (int i = 0; i<4; i++){
        cout << values[i] << " " << flush;
    }

    cout << endl;

    cout << sizeof(animals[1][0]) << endl;

    cout << sizeof(string) << endl;
    return 0;
}
