#include <iostream>
#include<cstdlib>
#include <ctime>
using namespace std;
class Animal
{
public:
    virtual void makeSound()
    {
        cout << "Animallllll" << endl;
    }
};
class cat : public Animal
{
public:
    void makeSound()
    {
        cout << "Meow...Meow" << endl;
    }
};
class dog : public Animal
{
public:
    void makeSound()
    {
        cout << "Bau Bau" << endl;
    }
};
class duck : public Animal
{
public:
    void makeSound()
    {
        cout << "Quack Quack" << endl;
    }
};
int main()
{
    srand(time(0));
    Animal* animal;
    switch(rand()%3)
    {
    case 0:
        animal = new cat;
        break;
    case 1:
        animal = new dog;
        break;
    case 2:
        animal = new duck;
        break;
    }
    animal->makeSound();
    delete animal;
    return 0;
}
