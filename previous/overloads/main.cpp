#include <iostream>

using namespace std;

class ppp
{
    public:
        void print(char)
        {
            cout << "Char" << endl;
        }
        void print(double)
        {
            cout << "Double" << endl;
        }
};

int main()
{
    ppp a;
    float number = 5;
    a.print(number);
    return 0;
}
