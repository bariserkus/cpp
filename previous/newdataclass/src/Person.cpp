#include <iostream>
#include "Person.h"

using namespace std;

Person::Person()
{
    name = "George";
    //ctor
}


string Person::GetName()
{
    return "Person's name is: " + name;
}
