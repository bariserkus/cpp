#include <iostream>

using namespace std;

int number = 10;

class integer
{
private:
    int number;
public:
    void setnum(int);
    int getnum(void);
};

void integer::setnum(int a)
{
    int number = 6;
    integer::number = a;
}

int integer::getnum(void)
{
    return number;
}

int main()
{
    integer aaa;
    integer * bbb = new integer;
    aaa.setnum(5);
    (&aaa)->setnum(6);
    bbb->setnum(14);
    cout << aaa.getnum() << endl;
    cout << &aaa << endl;
    cout << bbb << endl;
    cout << bbb->getnum() << endl;
    cout << sizeof(integer) << endl;
    cout << sizeof(integer*) << endl;
    delete(&aaa);
    delete(bbb);
    return 0;
}
