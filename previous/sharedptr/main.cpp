#include <iostream>
#include <memory>
using namespace std;

class Test
{

public:
    Test()
    {
        cout << "Created" << endl;
    }

    void greet()
    {
        cout << "Hello" << endl;
    }

    ~Test()
    {
        cout << "Destroyed" << endl;
    }
};

int main()
{
    //shared_ptr<Test> pTest1(new Test());

    shared_ptr<Test> pTest2(nullptr);
    {
        shared_ptr<Test> pTest1 = make_shared<Test>();
        pTest2 = pTest1;
        auto pTest3 = pTest1;
    }


    //shared_ptr<Test> pTest2 = pTest1;
    cout << "Finished" << endl;
    return 0;
}
