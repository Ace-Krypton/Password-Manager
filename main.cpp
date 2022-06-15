#include <iostream>
#include "header.hpp"

/**
 * @author Ramiz Abbasov
 */

auto main() -> int {
    int user_input_int;
    bool main_loop = true;

    MAINLOOP:
    while (main_loop) {
        main_menu();
        std::cout << "\n> ";
        std::cin >> user_input_int;

        switch (user_input_int) {  //Main switch
            case 1:  //Search for passwords
                PassSearch::search_pass();
                break;

            case 2:  //Sort passwords
                SortPassword::sort_password();
                break;

            case 3:  //Add/Print passwords
                while (true) {
                    AddPassword::add_password_menu();

                    int user_input_for_add_pass;
                    std::cout << "\n> ";
                    std::cin >> user_input_for_add_pass;

                    switch (user_input_for_add_pass) {
                        case 1:  //Create password(s)
                            AddPassword::create_password();
                            break;

                        case 2:  //Generate password(s)
                            AddPassword::generate_password();
                            break;

                        case 3:  //Generate password(s) with url
                            AddPassword::create_password_with_url();
                            break;

                        case 4:  //Print password(s)
                            AddPassword::print_password();
                            AddPassword::print_password_with_url();
                            break;

                        case 5:  //Print categories with passwords
                            AddPassword::print_categories_with_passwords();
                            break;

                        case 6:  //Add password
                            AddPassword::add_password();
                            break;

                        case 0:  //Back
                            goto MAINLOOP;

                        default:
                            std::cout << "[-] Invalid command, Please try again" << std::endl;
                    }
                }

            case 4:  //Edit a password
                while (true) {
                    EditPassword::edit_password_menu();

                    int user_input_for_edit_pass;
                    std::cout << "\n> ";
                    std::cin >> user_input_for_edit_pass;

                    switch (user_input_for_edit_pass) {
                        case 1:  //Edit password from Password List
                            EditPassword::edit_password_from_password_list();
                            break;

                        case 2:  //Edit password from Categories List
                            EditPassword::edit_password_from_category_list();
                            break;

                        case 3:  //Edit password from Passwords with URl List
                            EditPassword::edit_password_from_url_list();
                            break;

                        case 0:  //Back
                            goto MAINLOOP;

                        default:
                            std::cout << "[-] Invalid command, Please try again" << std::endl;
                    }
                }

            case 5:  //Remove a password
                while (true) {
                    RemovePassword::remove_password_menu();
                    int user_input_for_remove_pass;
                    std::cout << "\n> ";
                    std::cin >> user_input_for_remove_pass;

                    switch (user_input_for_remove_pass) {
                        case 1:  //Remove password(s) from password
                            RemovePassword::remove_password_from_list();

                        case 2:  //Remove password(s) from categories
                            RemovePassword::remove_password_from_category();

                        case 0:  //Back
                            goto MAINLOOP;

                        default:
                            std::cout << "[-] Invalid command, Please try again" << std::endl;
                    }
                }

            case 6:  //Add a category
                AddCategory::add_category();
                break;

            case 7:  //Remove a category
                RemoveCategory::remove_category();
                break;

            case 8:  //Encryptor testing
                Encryptor::encryption_generator();
                break;

            case 9:  //Decryptor testing
                Decryptor::decryptor();
                break;

            case 10:  //Guide
                Documentation::guide();
                break;

            case 0:  {  //Exit
                std::cout << "Have you wrote the changes to the file (encryption) \"Yes/No\": ";
                std::string user_confirm;
                std::cin >> user_confirm;
                if (user_confirm == "No" || user_confirm =="no") goto MAINLOOP;
                std::cout << "Exiting..." << std::endl;
                main_loop = false;
                break;
            }

            default:
                std::cout << "[-] Invalid command, Please try again" << std::endl;
        }
    }
    return 0;
}

/**
 * Main menu of program
 * @return void
 */
auto main_menu() -> void {
    std::cout << "[1] Search for password(s)" << std::endl;
    std::cout << "[2] Sort passwords" << std::endl;
    std::cout << "[3] Add/Print password(s)" << std::endl;
    std::cout << "[4] Edit password(s)" << std::endl;
    std::cout << "[5] Remove password(s)" << std::endl;
    std::cout << "[6] Add category(s)" << std::endl;
    std::cout << "[7] Remove category(s)" << std::endl;
    std::cout << "[8] Encrypt the file" << std::endl;
    std::cout << "[9] Decrypt the file\n" << std::endl;
    std::cout << "[10] Tutorial" << std::endl;
    std::cout << "[0] Exit" << std::endl;
}
