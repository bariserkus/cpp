#include <iostream>
#include <queue>
#include "common.h"


int rc{0};
int fs{0};
int ss{0};

void run_clean(){
    ++rc;
    std::cout << "\n*Note* Cleaning has started... ID: " << rc << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "\n*Note* Cleaning has ended. ID: " << rc << "\n";
}
void run_fullspeed(){
    ++fs;
    std::cout << "\n*Note* Full speed forward has started... ID: " << fs << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "\n*Note* Full speed forward has ended. ID: " << fs << "\n";
}
void run_stop(){
    ++ss;
    std::cout << "\n*Note* Stop ship has started... ID: " << ss << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "\n*Note* Stop ship has ended has ended. ID: " << ss << "\n";
}

void cleaning(std::queue<int> & v){
    while(v.front() != 100)
    {
        if (!v.empty()){
            if (v.front() == 1)
                run_clean();
            else  if (v.front() != 100)
                std::cout << "Invalid cleaning code in the que: " << v.front() << "\n";
            v.pop();
        }
    }
    std::cout << "Cleaning tasks are finished. \n";
}

void engining(std::queue<int> & v){
    while(v.front() != 100)
    {
        if (!v.empty()) {
            if (v.front() == 2)
                run_fullspeed();
            else if (v.front() == 3)
                run_stop();
            else if (v.front() != 100)
                std::cout << "Invalid enginer work code in the que: " << v.front() << "\n";
            v.pop();
        }
    }
    std::cout << "Engine tasks are finished. \n";
}



int main() {
    std::queue<int> cleantasks;
    std::queue<int> enginetasks;

    std::thread thread_clean(cleaning, std::ref(cleantasks));
    std::thread thread_engine(engining, std::ref(enginetasks));

    int c{0};
    while(c != 100){
        std::cout << "\n" << "Ship Command Center - Select a command:\n";
        std::cout << "1: Cleaning\n";
        std::cout << "2: Full Speed\n";
        std::cout << "3: Stop\n";
        std::cout << "Enter 100 to exit the command center\n" << "Your Command:";
        std::cin >> c;

        if (c == 1)
            cleantasks.push(c);
        else if (c == 2 || c == 3)
            enginetasks.push(c);
        else if (c == 100) {
            cleantasks.push(c);
            enginetasks.push(c);
            break;
        }
    }

    std::cout << "Exiting the command center...\n";

    thread_clean.join();
    thread_engine.join();

    return 0;
}
