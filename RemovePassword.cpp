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
    std::cout << "\t\t\tRemoves selected password(s) from password list" << std::endl;

    //Prints our passwords
    AddPassword::print_password();
    //Prints our passwords with URL
    AddPassword::print_password_with_url();

    bool loop = true;
    int user_input;

    //Removal list that contains keys that will be removed from lists
    std::vector<int> removal;

    while (loop) {
        std::cout << "\n> ";
        std::cin >> user_input;

        //If the user enter something different from -1
        if (user_input == -1) {
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
    std::cout << "\t\t\t\tRemoves selected password(s) from categories" << std::endl;

    std::string user_input;
    std::string user_input_for_password;
    bool loop = true;

    //Removal list that contains values that will be removed from lists
    std::vector<std::string> removal;

    LOOP:
    while (loop) {
        //Prints categories with passwords
        AddPassword::print_categories_with_passwords();
        std::cout << "\n> ";
        std::cin >> user_input;

        //If user enters "quit" it exits from loop
        if (user_input == "quit") {
            loop = false;
        }

        else {
            if (user_input != "quit") {
                //Checks if category contains user entered category
                if (AddCategory::categories.contains(user_input)) {
                    std::cout << "[*] " << user_input << " selected!" << std::endl;
                    //Going through categories and printing the user entered category with its passwords
                    //Not const because, we will modify it
                    for (auto &category : AddCategory::categories) {
                        if (category.first == user_input) {
                            //Printing the values(passwords)
                            for (auto const &password : category.second) {
                                std::cout << "\n" << "[*] " << password;
                            }
                            std::cout << "\n> ";
                            std::cin >> user_input_for_password;

                            //Finding the iterator position of user entered password
                            auto it = std::find(category.second.begin(), category.second.end(), user_input_for_password);

                            //category.second.end() means the element was not found
                            if (it != category.second.end()) {
                                category.second.erase(it);  //Deleting the element
                                std::cout << "Deleted!" << std::endl;
                                goto LOOP;  //After deleting go to the loop
                            }
                            else std::cout << "[-] You don't have this password" << std::endl;
                        }
                    }
                }
                else std::cout << "[-] You don't have any category name like that!" << std::endl;
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
