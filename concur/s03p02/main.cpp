#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <thread>
#include <chrono>
#include <condition_variable>

bool have_i_arrived = false;
int total_distance = 10;
int distance_coverd = 0;

std::condition_variable cv;
std::mutex m;

bool keep_moving()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        distance_coverd++;

        if (distance_coverd == total_distance)
            cv.notify_one();
    }

    return false;
}

void ask_driver_to_wake_u_up(){
    std::unique_lock<std::mutex> ul(m);
    cv.wait(ul, [](){return distance_coverd == total_distance;});
    std::cout << "Finally I am there. Distance = " << distance_coverd << '\n';
}

void keep_awake_all_night()
{
    while (distance_coverd < total_distance)
    {
        std::cout << "keep check, whether i am there \n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    std::cout << "finally i am there, distance_coverd [awake] = " << distance_coverd << std::endl;;
}

void set_the_alarm_and_take_a_nap()
{
    if (distance_coverd < total_distance)
    {
        std::cout << "let me take a nap \n";
        std::this_thread::sleep_for(std::chrono::milliseconds(15000));
    }
    std::cout << "finally i am there, distance_coverd [nap]= " << distance_coverd << std::endl;;
}

int main()
{
    std::thread driver_thread(keep_moving);
    std::thread passanger_thread(ask_driver_to_wake_u_up);

    driver_thread.join();
    passanger_thread.join();

    //std::thread keep_awake_all_night_thread(keep_awake_all_night);
    //std::thread set_the_alarm_and_take_a_nap_thread(set_the_alarm_and_take_a_nap);
    //keep_awake_all_night_thread.join();
    //set_the_alarm_and_take_a_nap_thread.join();
    //driver_thread.join();

    return 0;
}
