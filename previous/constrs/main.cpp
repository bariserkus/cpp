#include <iostream>
#include <student.h>

using namespace std;

student f(20, 100);

int main()
{
    student a(1, 10);
    student b(2, 15);

    student c(5, 20), d(6, 25), e(7, 30);

    student arr[]={student(10, 40), student(11, 50), student(12,55)};
    {
        student aaa(50,60);

    }

    student *atheap = new student(100, 70);

    std::cout << "Hello world!" << std::endl;
    delete atheap;

    a.copyinst({4, 80});

    cout << a.giveidno() << endl;
    cout << b.giveidno() << endl;

    cout << a.givegrade() << endl;
    cout << b.givegrade() << endl;

    b.copyinst(a);

    cout << a.giveidno() << endl;
    cout << b.giveidno() << endl;

    cout << a.givegrade() << endl;
    cout << b.givegrade() << endl;

    student dd;
    student ee(77);
    student ff(88,99);

    cout << dd.giveidno() << endl;
    cout << ee.giveidno() << endl;
    cout << ff.giveidno() << endl;

    cout << dd.givegrade() << endl;
    cout << ee.givegrade() << endl;
    cout << ff.givegrade() << endl;


    return 0;
}
