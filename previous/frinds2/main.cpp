#include <iostream>

class integ;
class integer
{
    friend int sum(const integer&, const integ&);
    public:
        /** Default constructor */
        integer(int = 0);
        /** Default destructor */
        virtual ~integer();
    private:
        int number;
};
integer::integer(int x): number(x){}
integer::~integer(){}

class integ
{
    friend int sum(const integer&, const integ&);
    public:
        /** Default constructor */
        integ(int = 0);
        /** Default destructor */
        virtual ~integ();
    private:
        int numb;
};
integ::integ(int x): numb(x){}
integ::~integ(){}

inline int sum(const integer& i1, const integ& i2)
{
    return i1.number + i2.numb;
}

using namespace std;

int main()
{
    integer i1=10;
    integ i2=5;
    cout << sum(i1,i2)<< endl;
    return 0;
}
