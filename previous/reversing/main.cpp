#include <iostream>

using namespace std;

int main()
{
    char text[] = "hello";

    int nChars = sizeof(text)-1;

    char *pStart = text;
    char *pEnd = text + nChars - 1;
    cout << pEnd-pStart << endl;

    while (pStart < pEnd)
    {
        char save = *pStart;
        *pStart = *pEnd;
        *pEnd = save;
        pStart++;
        pEnd--;

        cout << pEnd-pStart << endl;
    }
    cout << pEnd-pStart << endl;

    cout << text << endl;


    return 0;
}
