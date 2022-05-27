#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string filename = "data.txt";
    ifstream input;

    input.open(filename);

    if(!input.is_open())
    {
        return 1;
    }

    while(input)
    {
        string line;
        getline(input, line);

        cout << line;

        int population = 1;
        //input >> population;

        //input.get();
        input >> ws;

        if(!input)
        {
            break;
        }

        cout << "'" << line << "'" << "--'" << population << "'" << endl;
    }
    input.close();

    cout << "Hello world!" << endl;
    return 0;
}
