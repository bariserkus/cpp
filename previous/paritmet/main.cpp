#include <iostream>

using namespace std;

int main()
{
    const int NSTRINGS = 5;
    string texts[NSTRINGS] = {"one", "two", "three", "four", "five"};

    string *pTexts = texts;

    cout << *pTexts << endl;

    pTexts++;

    cout << *pTexts << endl;

    pTexts--;

    cout << *pTexts << endl;

    string *pEnd = &texts[NSTRINGS-1];

    cout << *pEnd << endl;

    *pEnd = "Baris";

    cout << *pEnd << endl;

    int elements = pEnd - pTexts;

    cout << "Elements : " << elements << endl;

    pTexts += NSTRINGS/2;

    cout << *pTexts << endl;

    return 0;
}
