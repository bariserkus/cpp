#include <iostream>
using namespace std;

class base
{
private:
    int num;
public:
    void incnum()
    {
        num++;
    }
};

class derived : public base
{
    private
public:
    void test_numa()
    {
        numa++;
    }
};

int main()
{
    derived obj;
    obj.num = 7;
    cout << "Derived : " <<  obj.num << endl;

    return 0;
}
