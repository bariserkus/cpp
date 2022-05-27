#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
    Person baris;
    baris.SetName("Baris");

    cout << baris.GetName() << endl;
    return 0;
}
