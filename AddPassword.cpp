#include <iostream>
#include <string>
#include <cstdlib>
#include <set>
#include <ctime>
#include "header.hpp"

/**
 * TODO 1. Randomizer  [X]
 *      2. Options for generation  [X]
 *      3. Create Password
 *      4. Print those created/generated password in add_password  [X]
 *      5. Finish up with the add_password
 */

/**
 * Add password
 * @return void
 */
auto AddPassword::add_password() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
    std::cout << "                      Adds a new password to the encrypted file\n" << std::endl;

    std::cout << "Please choose category" << std::endl;
    for (auto &category : AddCategory::categories) {
        std::cout << category.first << std::endl;
    }

    std::string category_name;
    std::cout << "> ";
    std::cin >> category_name;

    std::vector<std::string> matched_passwords;

    if (AddCategory::categories.contains(category_name)) {  //If categories contains user input
        std::cout << "Key found!" << std::endl;

        for (auto &password : AddCategory::passwords) {  //Printing passwords
            std::cout << "{ " << password.first << ": " << password.second << " }" << std::endl;
        }

        std::cout << "Which password you wanna add?" << std::endl;
        int password_id;

        while (password_id != -1) {
            std::cout << "> ";
            std::cin >> password_id;
            auto it = AddCategory::passwords.find(password_id);  //Returns an iterator pointing to the element

            if (it->second.empty()) {  //If the value is empty it returns
                std::cout << "You don't have any password with that key!" << std::endl;
            }

            else {
                std::cout << "Password added!" <<std::endl;
                matched_passwords.emplace_back(it->second);
            }
        }

        for (auto &vec : matched_passwords) {
            std::cout << vec << std::endl;
        }

        AddCategory::categories[category_name] = matched_passwords;  //Adding value to the key of the category
        std::cout << "Password added!" << std::endl;

//        for (auto &matched : matched_passwords) {
//            AddCategory::passwords.erase(matched);  //After adding, removing the key from passwords
//        }

        matched_passwords.clear();  //Emptying our vector after adding

        for (auto &category : AddCategory::categories) {  //Printing categories
            std::cout << "{ " << category.first << ": ";
            for (auto &matched : category.second) {
                std::cout << matched << ", ";
            }
            std::cout << " }" << std::endl;
        }

        std::cout << "-------------------------------------------------------" << std::endl;
        for (auto &password : AddCategory::passwords) {  //Printing passwords
            std::cout << "{ " << password.first << ": " << password.second << " }" << std::endl;
        }
    }

    else std::cout << "Category name does not exist! Try again" << std::endl;
}

/**
 * Generates passwords automatically
 * @return void
 */
 auto AddPassword::generate_password() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
    std::cout << "          Generates password that meets requirements specified by the user\n" << std::endl;

    //Character, numbers and special characters
    std::string const CAPITAL_CASE_LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string const LOWER_CASE_LETTERS = "abcdefghijklmnopqrstuvwxyz";
    std::string const SPECIAL_CASE_LETTERS = "!@#$";
    std::string const NUMBERS = "1234567890";

    //Combinations
    std::string const COMBINED_CHARACTERS_OF_ALL = NUMBERS + SPECIAL_CASE_LETTERS + LOWER_CASE_LETTERS + CAPITAL_CASE_LETTERS;
    std::string const COMBINED_CHARACTERS_OF_NUM_LOW = NUMBERS + LOWER_CASE_LETTERS;
    std::string const COMBINED_CHARACTERS_OF_NUM_SPEC_LOW = NUMBERS + SPECIAL_CASE_LETTERS + LOWER_CASE_LETTERS;
    std::string const COMBINED_CHARACTERS_OF_NUM_CAP = NUMBERS + CAPITAL_CASE_LETTERS;
    std::string const COMBINED_CHARACTERS_OF_NUM_CAP_SPEC = NUMBERS + CAPITAL_CASE_LETTERS + SPECIAL_CASE_LETTERS;
    std::string const COMBINED_CHARACTERS_OF_LOW_CAP_NUM = NUMBERS + LOWER_CASE_LETTERS + CAPITAL_CASE_LETTERS;

    bool is_special = false;
    bool is_contain_both_cap = false;
    bool is_contain_all = false;
    bool loop = true;

    int size = 0x0;  //Size of the password
    std::cout << "Please enter the size of the password: ";
    std::cin >> size;

    while (size < 4) {  //Password should not be less than 4
        std::cout << "Your password must be the minimum length of 4" << std::endl;
        std::cout << "Please enter the size of the password: ";
        std::cin >> size;
    }

    while (loop) {
        generate_password_menu();
        int user_input_for_pass_menu;
        std::cout << "\n> ";
        std::cin >> user_input_for_pass_menu;

        switch (user_input_for_pass_menu) {
            case 1:  //Lowercase, Uppercase and Numbers
                is_contain_both_cap = true;
                loop = false;
                break;

            case 2:  //Lowercase, Special Character and Numbers
                is_special = true;
                loop = false;
                break;

            case 3:  //Lowercase, Uppercase, Special Character and Numbers
                is_contain_all = true;
                loop = false;
                break;

            case 4:  //Lowercase and Numbers
                loop = false;
                break;

            default:
                std::cout << "Invalid command, Please try again" << std::endl;
        }
    }

    char password[size];  //Password array
    int num = rand() % 100 + 1;

    if (is_special) {
        srand(time(nullptr));
        password[0] = LOWER_CASE_LETTERS[rand() % LOWER_CASE_LETTERS.length() + 1];
        password[1] = SPECIAL_CASE_LETTERS[rand() % SPECIAL_CASE_LETTERS.length() + 1];
        password[2] = NUMBERS[rand() % NUMBERS.length() + 1];

        for (int i = 3; i < size; i++) {
            password[i] = COMBINED_CHARACTERS_OF_ALL[rand() % COMBINED_CHARACTERS_OF_ALL.length() + 1];
        }
    }

    else if (is_contain_both_cap) {
        srand(time(nullptr));
        password[0] = LOWER_CASE_LETTERS[rand() % LOWER_CASE_LETTERS.length() + 1];
        password[1] = CAPITAL_CASE_LETTERS[rand() % CAPITAL_CASE_LETTERS.length() + 1];
        password[2] = NUMBERS[rand() % NUMBERS.length() + 1];

        for (int i = 3; i < size; i++) {
            password[i] = COMBINED_CHARACTERS_OF_LOW_CAP_NUM[rand() % COMBINED_CHARACTERS_OF_LOW_CAP_NUM.length() + 1];
        }
    }

    else if (is_contain_all) {
        srand(time(nullptr));
        password[0] = LOWER_CASE_LETTERS[rand() % LOWER_CASE_LETTERS.length() + 1];
        password[1] = CAPITAL_CASE_LETTERS[rand() % CAPITAL_CASE_LETTERS.length() + 1];
        password[2] = NUMBERS[rand() % NUMBERS.length() + 1];

        for (int i = 3; i < size; i++) {
            password[i] = COMBINED_CHARACTERS_OF_ALL[rand() % COMBINED_CHARACTERS_OF_ALL.length() + 1];
        }
    }

    else {
        srand(time(nullptr));
        password[0] = LOWER_CASE_LETTERS[rand() % LOWER_CASE_LETTERS.length() + 1];
        password[1] = NUMBERS[rand() % NUMBERS.length() + 1];

        for (int i = 2; i < size; i++) {
            password[i] = COMBINED_CHARACTERS_OF_NUM_LOW[rand() % COMBINED_CHARACTERS_OF_NUM_LOW.length() + 1];
        }
    }

    std::string password_as_string;  //Converting password[] to std::string
    for (int i = 0; i < size; i++) {  //Adding elements to our std::string
        password_as_string.push_back(password[i]);
    }

    std::cout << "Your password is: " << password_as_string << std::endl;
    std::cout << "Do you want to add " << password_as_string << " to the passwords?" << std::endl;
    std::cout << "\"y/N\": ";
    std::string user_input;
    std::cin >> user_input;

    if (user_input == "y") {  //If user enters "y", this will add generated password to the vector
        AddCategory::passwords[num] = password_as_string;
        std::cout << "Password added successfully!" << std::endl;
    }
}

/**
 * Menu of add password option
 * @return void
 */
auto AddPassword::add_password_menu() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "[1] Create password" << std::endl;
    std::cout << "[2] Generate password" << std::endl;
    std::cout << "[3] Add password\n" << std::endl;
    std::cout << "[0] Back" << std::endl;
}

/**
 * Menu of generate password option
 * @return void
 */
auto AddPassword::generate_password_menu() -> void {
    std::cout << "[1] Lowercase, Uppercase and Numbers" << std::endl;
    std::cout << "[2] Lowercase, Special Character and Numbers" << std::endl;
    std::cout << "[3] Lowercase, Uppercase, Special Character and Numbers" << std::endl;
    std::cout << "[4] Lowercase and Numbers" << std::endl;
}
