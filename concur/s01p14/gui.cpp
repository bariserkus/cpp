class commandgui{
private:
    int c;
public:
    commandgui():c(0){}
    void run_clean(){
        std::cout << "Cleaning...\n";
    }
    void run_fullspeed(){
        std::cout << "Full Speed...\n";
    }
    void run_stop(){
        std::cout << "Stopping...\n";
    }
    int  get_command(){
        while(c != 100){
            std::cout << "Select a command:\n";
            std::cout << "1: Cleaning\n";
            std::cout << "2: Full Speed\n";
            std::cout << "2: Stop\n";
            std::cout << "Enter 100 to exit the command center\n";
            std::cin >> c;

            switch (c) {
                case 1:
                    run_clean();
                    break;
                case 2:
                    run_fullspeed();
                    break;
                case 3:
                    run_stop();
                    break;
            }
        }
        std::cout << "Exiting the command center...\n";
    }
    int get_c(){
        return c;
    }


};
