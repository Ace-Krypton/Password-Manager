#include <iostream>
#include <vector>
#include "header.hpp"

auto RemovePassword::remove_password_from_list() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "Removes selected password(s) from password list" << std::endl;

    AddPassword::print_password();  //Prints our passwords
    AddPassword::print_password_with_url();  //Prints our passwords with URL

    int user_input_for_rem_pass;

    std::vector<int> removal;

    while (user_input_for_rem_pass != -1) {
        std::cout << "\n> ";
        std::cin >> user_input_for_rem_pass;

        auto it_pass = AddCategory::passwords.find(user_input_for_rem_pass);
        auto it_url = AddCategory::passwords_with_url.find(user_input_for_rem_pass);

        if (it_pass->second.empty() && it_url->second.empty()) {
            std::cout << "[-] You don't have any password with that key!" << std::endl;
        }

        else {
            removal.emplace_back(it_pass->first);
            std::cout << "Password added to removal list" << std::endl;

            removal.emplace_back(it_url->first);
            std::cout << "Password added to removal list" << std::endl;
        }
    }

    if (removal.size() > 2) {
        std::cout << "Confirm that you want to delete that passwords" << std::endl;
        std::cout << "\"y/N\": ";
        std::string yes_or_no;
        std::cin >> yes_or_no;

        if (yes_or_no == "N" || yes_or_no == "n") {
            std::cout << "[-] Password removal unsuccessful" << std::endl;
            return;
        }

        else {
            for (int const key : removal) {
                AddCategory::passwords.erase(key);
            }
        }
    }

    else {
        for (int const key : removal) {
            AddCategory::passwords.erase(key);
        }
    }
}

auto RemovePassword::remove_password_from_category() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "Removes selected password(s) from categories" << std::endl;

}

auto RemovePassword::remove_password_menu() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "[1] Remove password(s) from password list" << std::endl;
    std::cout << "[2] Remove password(s) from categories\n" << std::endl;
    std::cout << "[0] Back" << std::endl;
}
