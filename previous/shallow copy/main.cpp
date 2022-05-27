#include <iostream>
#include "student.h"

using namespace std;

int main()
{
    student Baris(15,"Baris Erkus");
    cout << Baris.getname() << endl;
    cout << Baris.getidref() << endl;
    cout << Baris.getid() << endl;

    student Emek(15,"Baris Erkus");
    cout << Emek.getname() << endl;
    cout << Emek.getidref() << endl;
    cout << Emek.getid() << endl;
    cout << "Hello world!" << endl;

    student Leyla(Baris);
    cout << Leyla.getname() << endl;
    return 0;
}
