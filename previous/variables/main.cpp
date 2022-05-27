#include <iostream>

using namespace std;

int main()
{

    int numberCats = 5;
    int numberDogs = 7;
    int numberAnimals = numberCats + numberDogs;

    cout << "Number of Cats is " << numberCats << endl;

    cout << "Number of Dogs is " << numberDogs << endl;

    cout << "Total number of animals is " << numberCats + numberDogs << endl;
    cout << "Total number of animals is " << numberAnimals << endl;

    cout << "New dog acquired ! " << endl;

    numberDogs = numberDogs + 1;

    cout << "Number of Dogs is " << numberDogs << endl;


    return 0;
}
