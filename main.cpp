#include <iostream>
#include <string>
#include "header.hpp"

auto main() -> int {
    std::string user_input_str;  //User input (string)
    int user_input_int;  //User input (integer)
    bool main_loop = true;  //Boolean for main loop

    MAINLOOP:
    while (main_loop) {  //Main loop
        main_menu();  //Calling main_menu function for printing the menu
        std::cout << "\n> ";
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
                while (true)
                {
                    AddPassword::add_password_menu();
                    int user_input_for_add_pass;
                    std::cout << "\n> ";
                    std::cin >> user_input_for_add_pass;
                    switch (user_input_for_add_pass)
                    {
                        case 1:  //Create password
                            AddPassword::create_password();
                            break;

                        case 2:  //Generate password
                            AddPassword::generate_password();
                            break;

                        case 3:  //Add password
                            AddPassword::add_password();
                            break;

                        case 0:  //Back
                            goto MAINLOOP;

                        default:
                            std::cout << "Invalid command, Please try again" << std::endl;
                    }
                }

            case 4:  //Edit a password
                AddPassword::custom_key_generator(AddCategory::passwords);
                break;

            case 5:  //Remove a password
                break;

            case 6:  //Add a category
                AddCategory::add_category();
                break;

            case 7:  //Remove a category
                break;

            default:
                std::cout << "Invalid command, Please try again" << std::endl;
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
    std::cout << "[7] Remove a category\n" << std::endl;
    std::cout << "[0] Exit" << std::endl;
}
