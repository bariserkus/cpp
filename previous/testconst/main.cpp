#include <iostream>
using namespace std;

class MyClass
{
private:
    int a;
public:
    MyClass(int x = 20)
    {
        a = x;

    }

    int geta()
    {
        return a;
    }
};

int main()
{
    MyClass m;
    MyClass n {40};

    cout << "m.a : " << m.geta() << endl;
    cout << "n.a : " << n.geta() << endl;
    cout << "Hello world!" << endl;
    return 0;
}
