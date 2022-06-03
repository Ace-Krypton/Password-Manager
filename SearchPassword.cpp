#include <iostream>
#include <string>
#include "header.hpp"

/**
 * @author Ramiz Abbasov
 */

/**
 * Password searching from category list
 * @return void
 */
auto PassSearch::search_pass() -> void {
    std::string user_input;
    std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
    std::cout << "\t\tPassword search will return passwords matching the specified criteria\n" << std::endl;

    if (AddCategory::passwords.empty() && AddCategory::passwords_with_url.empty() && AddCategory::categories.empty()) {
        std::cout << "[-] You don't have any passwords on your lists or categories\n" << std::endl;
        return;
    }

    std::cout << "Enter the password: ";
    std::cin >> user_input;

    for (auto const &password : AddCategory::passwords) {
        if (password.second == user_input) {
            std::cout << "[*] It is present in password list" << std::endl;
            std::cout << "[*] " << password.first << ": " << password.second << '\n' << std::endl;
        }

        else {
            for (auto const &passwords_w_url : AddCategory::passwords_with_url) {
                for (auto const &pass : passwords_w_url.second) {
                    if (pass.second == user_input) {
                        std::cout << "[*] It is present in password URL list" << std::endl;
                        std::cout << "[*] " << pass.first << ": " << pass.second << '\n' << std::endl;
                    }

                    else {
                        for (auto const &category : AddCategory::categories) {
                            for (auto const &vec : category.second) {
                                if (vec == user_input) {
                                    std::cout << "[*] It is present in category list\n" << std::endl;
                                    std::cout << "[*] " << vec << '\n' << std::endl;
                                }
                            }
                        }
                    }
                }
            }
            std::cout << "[-] Password is not present in the list\n" << std::endl;
        }
    }
}
