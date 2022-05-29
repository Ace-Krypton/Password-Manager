#include <iostream>
#include "header.hpp"

auto EditPassword::edit_password_from_password_list() -> void {

}

/**
 * Menu for editing passwords
 * @return void
 */
auto EditPassword::edit_password_menu() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "[1] Edit password from Password List" << std::endl;
    std::cout << "[2] Edit password from Categories List" << std::endl;
    std::cout << "[3] Edit password from Passwords with URl List" << std::endl;
}
