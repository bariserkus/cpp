#include <iostream>

using namespace std;

int main()
{
    string texts[] = {"one", "two", "three"};

    int sizT = sizeof(texts)/sizeof(string);
    cout << "Size of texts : " << sizT << endl;

    string *pTexts = texts;
//    string *pTexts = &texts[0];

    for (int i=0; i<sizT; i++ )
    {
        cout << texts[i] << " " << flush;
    }

    cout << endl;

    for (int i=0; i<sizT; i++ )
    {
        cout << pTexts[i] << " " << flush;
    }

     cout << endl;


    for (int i=0; i<sizT; i++ )
    {
        cout << *pTexts++ << " " << flush;
    }

    cout << endl;

    pTexts = &texts[0];

    for (int i=0; i<sizT; i++, pTexts++)
    {
        cout << *pTexts << " " << flush;
    }

    cout << endl;

    string *pElement = &(texts[0]);
    string *pEnd = &(texts[2]);

    while(true)
    {
        cout << *pElement << " " << flush;
        if (pElement == pEnd)
        {
            break;
        }
        pElement++;
    }

    cout << endl;

    pElement = &texts[0];
    pEnd = &(texts[3]);


    while(pElement != pEnd)
    {
        cout << *pElement << " " << flush;
        pElement++;
    }



    return 0;
}
