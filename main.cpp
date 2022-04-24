#include <iostream>
#include "header.hpp"

auto main() -> int {
    main_menu();  //Calling main_menu function for printing the menu
    
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
}
