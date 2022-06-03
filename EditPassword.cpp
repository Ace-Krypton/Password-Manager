#include <iostream>
#include <algorithm>
#include "header.hpp"

/**
 * @author Ramiz Abbasov
 */

/**
 * Edits selected password(s) from password list
 * @return void
 */
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
        std::cout << "\n[*] " << it->second << " selected!" << std::endl;
        std::cout << "\n\t\t\t\tEnter the edited password" << std::endl;
        std::cout << "\n> ";
        std::string new_edited_password;
        std::cin >> new_edited_password;
        it->second = new_edited_password;
    }

    else std::cout << "[-] Password not found, ID is incorrect!" << std::endl;
}

/**
 * Edits selected password(s) from category list
 * @return void
 */
auto EditPassword::edit_password_from_category_list() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "\t\t\t\tEdits selected password(s) from category list" << std::endl;

    //Prints categories with passwords
    AddPassword::print_categories_with_passwords();

    std::string user_input;
    std::string user_input_for_password;
    std::string new_edited_password;

    std::cout << "\t\t\t\tEnter the category name" << std::endl;
    std::cout << "\n> ";
    std::cin >> user_input;

    if (AddCategory::categories.contains(user_input)) {
        std::cout << "[*] " << user_input << " selected!" << std::endl;
        for (auto &category : AddCategory::categories) {
            if (category.first == user_input) {
                //Printing the values(passwords)
                for (auto const &password : category.second) {
                    std::cout << "\n" << "[*] " << password;
                }

                while (true) {
                    std::cout << "\n\t\t\t\tEnter the password you wanna edit" << std::endl;
                    std::cout << "\n> ";
                    std::cin >> user_input_for_password;

                    if (std::count(category.second.begin(), category.second.end(), user_input_for_password)) {
                        break;
                    }
                    else std::cout << "[-] You don't have any password like that" << std::endl;
                }

                std::cout << "\n[*] " << user_input_for_password << " selected!" << std::endl;

                std::cout << "\t\t\t\tEnter the edited password" << std::endl;
                std::cout << "\n> ";
                std::cin >> new_edited_password;

                std::replace(category.second.begin(), category.second.end(), user_input_for_password, new_edited_password);
            }
        }
    }
    else std::cout << "[-] You don't have any category named like that!" << std::endl;
}

/**
 * Edits selected password(s) from URL list
 * @return void
 */
auto EditPassword::edit_password_from_url_list() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "\t\t\t\tEdits selected password(s) from URL list" << std::endl;

    AddPassword::print_password_with_url();

    std::string new_edited_password;
    std::string user_input;
    int id;

    std::cout << "\n\t\t\t\t\tEnter the ID" << std::endl;
    std::cout << "\n> ";
    std::cin >> id;

    if (AddCategory::passwords_with_url.contains(id)) {
        std::cout << "\t\t\t\tEnter the password you wanna change" << std::endl;
        std::cout << "\n> ";
        std::cin >> user_input;

        for (auto &password_with_url : AddCategory::passwords_with_url) {
            for (auto &url_map : password_with_url.second) {
                if (url_map.second == user_input) {
                    std::cout << "\n> ";
                    std::cin >> new_edited_password;
                    url_map.second = new_edited_password;
                }
                else std::cout << "[-] Password was not found" << std::endl;
            }
        }
    }
    else std::cout << "[-] Key is invalid" << std::endl;
}

/**
 * Menu for editing password(s)
 * @return void
 */
auto EditPassword::edit_password_menu() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "[1] Edit password(s) from Password List" << std::endl;
    std::cout << "[2] Edit password(s) from Categories List" << std::endl;
    std::cout << "[3] Edit password(s) from Passwords with URl List\n" << std::endl;
    std::cout << "[0] Back" << std::endl;
}
