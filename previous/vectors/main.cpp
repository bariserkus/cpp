#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> strings(5);

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    strings[3] = "Baris Erkus";

    cout << strings[3] << endl;

    cout << strings.size() << endl;

    vector<string> stringsnew;

    stringsnew.push_back("one");
    stringsnew.push_back("two");
    stringsnew.push_back("three");

    cout << stringsnew[1] << endl;

    cout << stringsnew.size() << endl;


    for (int i=0; i<stringsnew.size(); i++)
    {
        cout << stringsnew[i] << endl;
    }

    vector<string>::iterator it = stringsnew.begin();

    it++;

    cout << *it << endl;

    for(vector<string>::iterator ita = stringsnew.begin(); ita !=strings.end(); ita++)
    {
        cout << *ita << endl;
    }

    return 0;
}
