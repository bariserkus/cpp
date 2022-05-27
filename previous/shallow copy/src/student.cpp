#include "student.h"
#include <cstring>

student::student(int idn, const char* nm):id(idn), idref(id)
{
    int sl = strlen(nm);
    name = new char[sl + 1];
    for (int i=0; i < sl; ++i)
    {
        name[i] = nm[i];
    }
    name[sl+1] = '\0';
}

student::student(const student &s): id(s.id), idref(s.idref)
{
    int sl = strlen(s.name);
    name = new char[sl + 1];
    for (int i=0; i < sl; ++i)
    {
        name[i] = s.name[i];
    }
    name[sl+1] = '\0';
}

student::~student()
{
    delete [] name;
}

int student::getid()const
{
    return id;
}

int student::getidref()const
{
    return idref;
}

const char* student::getname()const
{
    return name;
}
