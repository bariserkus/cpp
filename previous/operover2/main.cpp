#include <iostream>

using namespace std;

class integer
{
protected:
    int number;
public:
    integer(int = 0);
    integer(const integer&);
    friend integer operator+(const integer&, const integer&);
};
inline integer::integer(int n) : number(n){}
inline integer::integer(const integer& in):number(in.number){}
inline integer operator+(const integer& in1, const integer& in2)
{
    return in1.number + in2.number;
}

class integer_print : public integer
{
public:
    integer_print(const integer&);
    integer_print(int=0);
    void print();
};

inline integer_print::integer_print(const integer& in): integer(in){}
inline integer_print::integer_print(int n) : integer(n){}
inline void integer_print::print()
{
    cout << "number = " << number << endl;
}


int main()
{
    integer_print ip1(1), ip2(2);
    integer_print ip3 = ip1 + ip2;
    ip3.print();

    cout << "Hello world!" << endl;
    return 0;
}
