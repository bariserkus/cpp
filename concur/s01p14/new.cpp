#include <iostream>
#include "common.h"

void run_clean(){
    std::cout << "Cleaning...\n";
}
void run_fullspeed(){
    std::cout << "Full Speed...\n";
}
void run_stop(){
    std::cout << "Stopping...\n";
}


int main() {
    int c{0};

    std::thread t_clean(run_clean);
//    thread_guard tgc(t_clean);

    std::thread t_fspeed(run_fullspeed);
//    thread_guard tgf(t_fspeed);

    std::thread t_stop(run_stop);
//    thread_guard tgs(t_stop);

/*    while(c != 100){
        std::cout << "Select a command:\n";
        std::cout << "1: Cleaning\n";
        std::cout << "2: Full Speed\n";
        std::cout << "3: Stop\n";
        std::cout << "Enter 100 to exit the command center\n";
        std::cin >> c;

        switch (c) {
            case 1:
//                t_clean.detach();
                break;
            case 2:
//                t_fspeed.join();
                break;
            case 3:
//                t_stop.join();
                break;
        }
    }
    std::cout << "Exiting the command center...\n"; */

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

