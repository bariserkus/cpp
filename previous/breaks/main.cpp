#include <iostream>

using namespace std;

int main()
{
    /*    for (int i = 0; i < 5; i++){
            cout << "i is: "  << i << endl;
            if (i == 3){
                break;
            }
        }
    */
    for (int i = 0; i < 5; i++){

        if (i == 3){
            continue;
        }
        cout << "i is: "  << i << endl;
    }

    return 0;
}
