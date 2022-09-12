#include <iostream>

int main(){
    int size = 10;

    //Dynamic array initialization
    int * dynamicArray = new int[size];
    for(int i = 0 ; i< size; i++){
        dynamicArray[i] = i;
    }

    //Static array initialization
    int staticArray[size] = {1,2,3,4,5,6,7,8,9,10};
    float staticArray2[] = {2.3, 7.9, 5.6, 4.2, 9.1};

    //Printing an static Array
    std::cout << "Static Array: ";
    for(int i = 0 ; i< size; i++){
        std::cout << staticArray[i] << " ";
    }
    std::cout << std::endl;

    //Printing an static Array
    std::cout << "Static Array 2:  ";
    for(int i = 0 ; i< 5; i++){
        std::cout << staticArray2[i] << "  ";
    }
    std::cout << std::endl;

    //Printing an Dynamic Array
    std::cout << "Dynamic Array: ";
    for(int i = 0 ; i< size; i++){
        std::cout << dynamicArray[i] << " ";
    }

    // deleting allocated memory
    delete[] dynamicArray;
}