#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "header.hpp"

/**
 * TODO 1. Randomizer
 *      2. Options for generation
 *      3. Create Password
 *      4. Print those created/generated password in add_password
 *      5. Finish up with the add_password
 */

/**
 * Add password
 * @return void
 */
auto AddPassword::add_password() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
    std::cout << "                      Adds a new password to the encrypted file\n" << std::endl;

    //Which pass you want to add and prints passwords that you generated/created ...
}

/**
 * Generates passwords automatically
 * @return void
 */
 auto AddPassword::generate_password() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
    std::cout << "          Generates password that meets requirements specified by the user\n" << std::endl;

    int size = 0x0;  //Size of the password
    std::cout << "Please enter the size of the password: ";
    std::cin >> size;

    while (size < 4) {  //Password should not be less than 4
        std::cout << "Your password must be the minimum length of 4" << std::endl;
        std::cout << "Please enter the size of the password: ";
        std::cin >> size;
    }

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

    char password[size];  //Password array

    srand(time(nullptr));
    password[0] = LOWER_CASE_LETTERS[rand() % LOWER_CASE_LETTERS.length() + 1];
    password[1] = CAPITAL_CASE_LETTERS[rand() % CAPITAL_CASE_LETTERS.length() + 1];
    password[2] = SPECIAL_CASE_LETTERS[rand() % SPECIAL_CASE_LETTERS.length() + 1];
    password[3] = NUMBERS[rand() % NUMBERS.length() + 1];

    for (int i = 4; i < size; i++) {
        password[i] = COMBINED_CHARACTERS_OF_ALL[rand() % COMBINED_CHARACTERS_OF_ALL.length() + 1];
    }

    std::cout << "Your password is: ";
    for (int i = 0; i < size; i++) {
        std::cout << password[i];
    }
    std::cout << std::endl;
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

auto AddPassword::generate_password_menu() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "[1] Contains both lower and uppercase" << std::endl;
    std::cout << "[2] Should it contain special characters" << std::endl;
    std::cout << "[0] Back" << std::endl;
}
