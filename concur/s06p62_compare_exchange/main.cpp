#include <iostream>
#include <atomic>

int main() {

    std::atomic<int> X{10};
    int Y1{10};
    int Y2{5};
    int Z{30};
    std::atomic<bool> R{};

    std::cout <<"\nX: "<< X <<  '\n';
    std::cout <<"Y1: "<< Y1 <<  '\n';
    std::cout <<"Y2: "<< Y2 <<  '\n';
    std::cout <<"Z: "<< Z <<  '\n';
    std::cout <<"R: "<< R <<  '\n';

    R = X.compare_exchange_weak(Y1, Z);

    std::cout <<"\nX: "<< X <<  '\n';
    std::cout <<"Y1: "<< Y1 <<  '\n';
    std::cout <<"Y2: "<< Y2 <<  '\n';
    std::cout <<"Z: "<< Z <<  '\n';
    std::cout <<"R: "<< R <<  '\n';

    R = X.compare_exchange_weak(Y2, Z);

    std::cout <<"\nX: "<< X <<  '\n';
    std::cout <<"Y1: "<< Y1 <<  '\n';
    std::cout <<"Y2: "<< Y2 <<  '\n';
    std::cout <<"Z: "<< Z <<  '\n';
    std::cout <<"R: "<< R <<  '\n';



    return 0;
}
