#include <iostream>
#include <string>
#include "header.hpp"

auto main() -> int {
    std::string user_input_str;  //User input (string)
    int user_input_int;  //User input (integer)
    bool main_loop = true;  //Boolean for main loop

    while (main_loop) {  //Main loop
        main_menu();  //Calling main_menu function for printing the menu
        std::cout << "> ";
        std::cin >> user_input_int;

        switch (user_input_int) {  //Main switch
            case 0:  //Exit
                std::cout << "Exiting..." << std::endl;
                main_loop = false;
                break;

            case 1:  //Search for passwords
                PassSearch::pass_search();
                break;

            case 2:  //Sort passwords
                break;

            case 3:  //Add a password
                break;

            case 4:  //Edit a password
                break;

            case 5:  //Remove a password
                break;

            case 6:  //Add a category

                break;

            case 7:  //Remove a category
                break;

            default:
                std::cout << "Invalid command, Please try again";
        }
    }

    return 0;
}

/**
 * Main menu of program
 * @return void
 */
auto main_menu() -> void {
    std::cout << "[1] Search for passwords" << std::endl;
    std::cout << "[2] Sort passwords" << std::endl;
    std::cout << "[3] Add a password" << std::endl;
    std::cout << "[4] Edit a password" << std::endl;
    std::cout << "[5] Remove a password" << std::endl;
    std::cout << "[6] Add a category" << std::endl;
    std::cout << "[7] Remove a category" << std::endl;
    std::cout << "[0] Exit" << std::endl;
}
