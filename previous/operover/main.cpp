#include <iostream>
#include <MyString.h>

using namespace std;

int main()
{
    int i = 15;
    int j = 15;
    char str[20];

    cout << "Size of : " << sizeof(str) << endl;

    //MyString S1("Baris");
    MyString S2("Baris Erkus");

    cout << "Enter string: ";
    cin.getline(str,sizeof(str));

    cout << "The string is: " << str << endl;

    MyString S1(str);


    if(i == j)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    if(S1 == S2)  //if(S1.operator==(S2))
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    return 0;
}
