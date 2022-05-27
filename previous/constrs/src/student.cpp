#include <iostream>
#include "student.h"


int student::countt = 0;

student::student(int id, int gr )
{
    idno = id;
    grade = gr;
    student::countt++;
    std::cout << "Constructor: " << idno << ", Counter:" << countt << std::endl;
}

student::~student()
{
    std::cout << "Destructor: " << idno <<  ", Counter:" << countt << std::endl;
}

void student::copyinst(const student & s)
{
    idno = s.idno;
    grade = s.grade;
}

int student::giveidno()const
{
    return idno;
}

int student::givegrade()const
{
    return grade;
}
