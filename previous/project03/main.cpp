#include <iostream>
#include "Customer.h"
#include "Admin.h"

int main() {

    Customer Baris{"Baris", "bariserkus", "bariserkus@gmail.com", 46 };

    Admin Ahmet{"Ahmet", "ahmet", "ahmet@gmail.com", 40 };

    Baris.PrintProfile();

    Ahmet.PrintProfile();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
