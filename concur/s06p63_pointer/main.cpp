#include <iostream>
#include <atomic>

int main() {

    int i[20];

    int * ptri2 = &(i[2]);
    int * ptri0 = &(i[0]);

    for(int j = 0; j < 20; ++j){
        i[j] = j * 2;
    }

    std::atomic<int*> ptri = i;

    std::cout << "Pointer: " << ptri << '\n';
    std::cout << "Pointer 2: " << ptri2<< '\n';

    auto r = ptri.compare_exchange_weak(ptri2, i+5);

    std::cout << "Pointer: " << ptri << '\n';
    std::cout << "Pointer 2: " << ptri2<< '\n';

    r = ptri.compare_exchange_weak(ptri0, i+5);

    std::cout << "Pointer: " << ptri << '\n';
    std::cout << "Pointer 2: " << ptri2<< '\n';

    std::cout << *ptri;



    return 0;
}
