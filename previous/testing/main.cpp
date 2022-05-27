#include <iostream>

using namespace std;

int main()
{
    int nVals[] = {0, 1, 2, 3, 4, 5};

    int *pVals = &nVals[0];

    int oVal = *(nVals+2);

    cout << nVals << endl;
    cout << pVals << endl;
    cout << oVal << endl;
    return 0;
}
