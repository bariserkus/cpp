#include <iostream>
using namespace std;

class Animal {
private:
    string name;

public:
    Animal() {cout << "Animal Created." << endl;}
    Animal(const Animal &other):name((&other)->name) {cout << "Animal Created by copying" << endl;}
	void setName(string name) { this->name = name; };
	void speak() const { cout << "My name is: " << name << endl; }
};

int main() {

    Animal Anim1;

    Anim1.setName("Freddy");

    //Animal * pAnim1 = &Anim1; make name public for these 3 lines to work
    //cout << pAnim1->name << endl;
    //cout << (&Anim1)->name << endl;

    Animal Anim2 = Anim1;  // invokes a different constructor: "copy" constructor
    Anim2.speak();

    Anim2.setName("Bob");

    Anim1.speak();
    Anim2.speak();

    Animal animal3(Anim1);
    animal3.speak();

    Animal *pCat = new Animal();
    pCat->setName("Mirnaw");



	return 0;
}
