#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    cout << strings[2] << endl;

    cout << strings.size() << endl;

    for (int i=0; i<strings.size(); i++)
    {
        cout << strings[i] << endl;
    }

    for(vector <string>::iterator it = strings.begin(); it !=strings.end(); it++)
    {
        cout << *it << endl;
    }

    vector <string>::iterator it = strings.end();
    cout << *it << endl;



    return 0;
}
