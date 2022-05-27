// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)

struct Person
{
    //char c;
    char name[50];
    int age;
    double height;
};

#pragma pack(pop)

int main()
{
    Person someone = {"Frodo", 220, 0.8};
    string fileName = "testing.bin";

    // Write Binary File
    ofstream outputFile;

    outputFile.open(fileName, ios::binary);

    if(outputFile.is_open())
    {
        //outputFile.write((char *)&someone, sizeof(Person));
        outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

        outputFile.close();
    }
    else
    {
        cout << "Could not create " + fileName << endl;
    }
////////////////////////////////////////////////////////////////////////

    // Read Binary File
    ifstream inputFile;

    Person newperson = {};

    inputFile.open(fileName, ios::binary);

    if(inputFile.is_open())
    {
        //outputFile.write((char *)&someone, sizeof(Person));
        inputFile.read(reinterpret_cast<char *>(&newperson), sizeof(Person));

        inputFile.close();
    }
    else
    {
        cout << "Could not read " + fileName << endl;
    }

    cout << newperson.name << endl;
    cout << newperson.age << endl;
    cout << newperson.height << endl;
    return 0;
}
