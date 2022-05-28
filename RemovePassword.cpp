#include <iostream>
#include <vector>
#include <algorithm>
#include "header.hpp"

/**
 * Removes password from password list or URL
 * @return void
 */
auto RemovePassword::remove_password_from_list() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "Removes selected password(s) from password list" << std::endl;

    AddPassword::print_password();  //Prints our passwords
    AddPassword::print_password_with_url();  //Prints our passwords with URL

    bool loop = true;
    int user_input;

    std::vector<int> removal;  //Removal list that contains keys that will be removed from lists

    while (loop) {
        std::cout << "\n> ";
        std::cin >> user_input;

        if (user_input == -1) {  //If the user enter something different from -1
            loop = false;
        }

        else {
            if (user_input != -1) {
                //It checks if the lists contains that password
                if (AddCategory::passwords.contains(user_input) || AddCategory::passwords_with_url.contains(user_input)) {
                    //Finds the user entered passwords from lists
                    auto it_pass = AddCategory::passwords.find(user_input);
                    auto it_url = AddCategory::passwords_with_url.find(user_input);

                    //After making sure they are not empty
                    //It pushes the corresponding key to the list
                    if (!(it_pass->second.empty())) {
                        removal.emplace_back(it_pass->first);
                        std::cout << "Password added to removal list" << std::endl;
                    }

                    else if (!(it_url->second.empty())) {
                        removal.emplace_back(it_url->first);
                        std::cout << "Password added to removal list" << std::endl;
                    }
                }
                else std::cout << "[-] You don't have any password with that key!" << std::endl;
            }
        }
    }

    //If removal size is bigger than 2, it requires a user confirmation
    if (removal.size() > 2) {
        std::cout << "Confirm that you want to delete that passwords" << std::endl;
        std::cout << "\"y/N\": ";
        std::string yes_or_no;
        std::cin >> yes_or_no;

        if (yes_or_no == "N" || yes_or_no == "n") {
            std::cout << "[-] Password removal unsuccessful" << std::endl;
            return;
        }

        //Removes the keys from the passwords and urls
        else {
            for (int key : removal) {
                AddCategory::passwords.erase(key);
                AddCategory::passwords_with_url.erase(key);
            }

            std::cout << "Successfully deleted password(s)!" << std::endl;
            return;
        }
    }

    //If it is lesser than 2 it removes keys without confirmation
    else {
        for (int key : removal) {
            AddCategory::passwords.erase(key);
            AddCategory::passwords_with_url.erase(key);
            std::cout << "Successfully deleted password(s)!" << std::endl;
            return;
        }
    }
}

/**
 * Removes passwords from categories
 * @return void
 */
auto RemovePassword::remove_password_from_category() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "Removes selected password(s) from categories" << std::endl;

    AddPassword::print_categories_with_passwords();  //Prints categories with passwords

    std::string user_input;
    std::string user_input_for_password;
    bool loop = true;

    std::vector<std::string> removal;

    while (loop) {
        std::cout << "\n> ";
        std::cin >> user_input;

        if (user_input == "quit") {
            loop = false;
        }

        else {
            if (user_input != "quit") {
                if (AddCategory::categories.contains(user_input)) {
                    std::cout << "[*] " << user_input << " selected!" << std::endl;
                    for (auto const &category : AddCategory::categories) {
                        if (category.first == user_input) {
                            for (auto const &password : category.second) {
                                std::cout << "\n" << "[*] " << password;
                            }
                            std::cout << "\n> ";
                            std::cin >> user_input_for_password;

                            auto it = std::find(category.second.begin(), category.second.end(), user_input_for_password);

                            if (it != category.second.end()) {  //category.second.end() means the element was not found
                                category.second.erase(it);
                            }
                        }
                    }
                }
                else std::cout << "[-] You don't have any category with that password!" << std::endl;
            }
        }
    }
}

/**
 * Menu for password removal option
 * @return void
 */
auto RemovePassword::remove_password_menu() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "[1] Remove password(s) from password list" << std::endl;
    std::cout << "[2] Remove password(s) from categories\n" << std::endl;
    std::cout << "[0] Back" << std::endl;
}
