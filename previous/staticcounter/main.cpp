#include<stdio.h>
class integer
// container class definition
{
    int num;
    int nummm;
public:
    integer(int=0);
    integer& increment();
    int get()const;
};
class keep_count
{
    static integer counter;
// contained class instance
public:
    keep_count();
    int print()const;
};
integer keep_count :: counter = 0;
// static data member definition
integer::integer(int x): num(x)
{
    printf("Integer constructor\n");
}
integer& integer :: increment()
{
    ++num;
    return *this;
}
int integer :: get()const
{
    return num;
}
keep_count :: keep_count()
// constructor
{
    printf("Keep Count constructor\n");
    counter.increment();
}
int keep_count :: print()const
{
    return counter.get();
}
int main()
{
    integer aa=5;
    printf("%d\n",aa.get());

    printf("Size of the class = %d\n",sizeof(integer));


    keep_count kc1;
// class instantiation
    keep_count kc2,kc3;
    printf("%d\n",kc1.print());
    return 0;
}
