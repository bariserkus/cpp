#include <iostream>

using namespace std;

class Test
{
private:
    int one{1};
    int two{2};

public:
    void run()
    {
        int three{3};
        int four{4};

        auto plamb = [&, this]()
        {
            one = 110;
            cout << one << endl;
            cout << three << endl;
            cout << four << endl;
        };
        plamb();
    }

};

int main()
{
    Test test;
    test.run();
    cout << "Hello world!" << endl;
    return 0;
}
