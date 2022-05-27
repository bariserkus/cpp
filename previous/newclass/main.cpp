#include <iostream>
#include <Cats.h>

using namespace std;

int main()
{
    cout << "Starting Program ..." << endl;
    {
        Cats catA;
        //catA.name = "Mirnaw";
        catA.makeHappy();
        catA.speak();

        catA.makeSad();
        catA.speak();
    }

    cout << "Ending Program ..." << endl;

    return 0;


}
