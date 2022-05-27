#include <iostream>
#include "common.h"

int rc{0};
int fs{0};
int ss{0};

void run_clean(){
    ++rc;
    std::cout << "\n*Note* Cleaning has started... ID: " << rc << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "\n*Note* Cleaning has ended. ID: " << rc << "\n";
}
void run_fullspeed(){
    ++fs;
    std::cout << "\n*Note* Full speed forward has started... ID: " << fs << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "\n*Note* Full speed forward has ended. ID: " << fs << "\n";
}
void run_stop(){
    ++ss;
    std::cout << "\n*Note* Stop ship has started... ID: " << ss << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "\n*Note* Stop ship has ended has ended. ID: " << ss << "\n";
}


int main() {
    std::vector<std::thread> t;
    int c{0};
    while(c != 100){
        std::cout << "\n" << "Ship Command Center - Select a command:\n";
        std::cout << "1: Cleaning\n";
        std::cout << "2: Full Speed\n";
        std::cout << "3: Stop\n";
        std::cout << "Enter 100 to exit the command center\n" << "Your Command:";
        std::cin >> c;

        switch (c) {
            case 1:
                t.push_back(std::thread(run_clean));
                t.back().detach();
                t.pop_back();
                break;
            case 2:
                t.push_back(std::thread(run_fullspeed));
                t.back().join();
                t.pop_back();
                break;
            case 3:
                t.push_back(std::thread(run_stop));
                t.back().join();
                t.pop_back();
                break;
        }
    }
    std::cout << "Exiting the command center...\n";

    return 0;
}
