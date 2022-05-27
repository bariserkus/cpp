#include <iostream>
#include "MyString.h"

using namespace std;

MyString::MyString(const char* ptr)
{
    int i = 0;
    while(ptr[i] != '\0')
    {
        name[i] = ptr[i];
        ++i;
    }
    name[i] = '\0';
}

MyString::~MyString() {}

bool MyString::operator==(const MyString& S)
{
    int i = 0;
    while(name[i]==S.name[i])
    {
        cout << name << ":" << name[i] << ", " << S.name << ":" << S.name[i] << endl;
        if(name[i] == '\0' || S.name[i] == '\0')
        {
            cout << "break" << endl;
            break;
        }
        cout << "i = " << i << endl;
        ++i;
    }
    if(name[i+1] == '\0' && (S.name[i+1]) == '\0')
    {
        cout << "TRUE" << endl;
        return 1;
    }
    cout << "FALSE" << endl;
    return 0;
}

const void MyString::print()const
{
    cout << name << endl;
}


