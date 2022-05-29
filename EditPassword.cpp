#include <iostream>
#include "header.hpp"

auto EditPassword::edit_password_from_password_list() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "\t\t\t\tEdits selected password(s) from password list" << std::endl;

    //Prints our passwords
    AddPassword::print_password();

    std::cout << "\n\t\t\t\tEnter the ID of the password you wanna change" << std::endl;
    std::cout << "\n> ";
    int user_input;
    std::cin >> user_input;

    auto it = AddCategory::passwords.find(user_input);

    if (it != AddCategory::passwords.end()) {
        std::cout << "\n[*] " << it->second << " selected" << std::endl;
        std::cout << "\n\t\t\t\tEnter the edited password" << std::endl;
        std::cout << "\n> ";
        std::string new_edited_password;
        std::cin >> new_edited_password;
        it->second = new_edited_password;
    }

    else std::cout << "[-] Password not found, ID is incorrect!" << std::endl;
}

/**
 * Menu for editing passwords
 * @return void
 */
auto EditPassword::edit_password_menu() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "[1] Edit password(s) from Password List" << std::endl;
    std::cout << "[2] Edit password(s) from Categories List" << std::endl;
    std::cout << "[3] Edit password(s) from Passwords with URl List\n" << std::endl;
    std::cout << "[0] Back" << std::endl;

}
