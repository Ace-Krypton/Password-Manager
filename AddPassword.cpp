#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "header.hpp"

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

    if (size < 4) {
        std::cout << "Your password must be the minimum length of 4" << std::endl;
    }

    //Character, numbers and special characters
    std::string capital_case_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lower_case_letters = "abcdefghijklmnopqrstuvwxyz";
    std::string special_case_letters = "!@#$";
    std::string numbers = "1234567890";

    //Combinations
    std::string combined_characters_of_all = numbers + special_case_letters + lower_case_letters + capital_case_letters;
    std::string combined_characters_of_num_low = numbers + lower_case_letters;
    std::string combined_characters_of_num_spec_low = numbers + special_case_letters + lower_case_letters;
    std::string combined_characters_of_num_cap = numbers + capital_case_letters;
    std::string combined_characters_of_num_cap_spec = numbers + capital_case_letters + special_case_letters;
    std::string combined_characters_of_low_cap_num = numbers + lower_case_letters + capital_case_letters;

    char password[size];

    srand(time(nullptr));
    password[0] = lower_case_letters[rand() % lower_case_letters.length() + 1];
    password[1] = capital_case_letters[rand() % capital_case_letters.length() + 1];
    password[2] = special_case_letters[rand() % special_case_letters.length() + 1];
    password[3] = numbers[rand() % numbers.length() + 1];

    for (int i = 4; i < size; i++) {
        password[i] = combined_characters_of_all[rand() % combined_characters_of_all.length() + 1];
    }

    std::cout << "Your generated password is: " << password << std::endl;
}

/**
 * Menu of add password option
 * @return void
 */
auto AddPassword::add_password_menu() -> void {
    std::cout << "[1] Create password" << std::endl;
    std::cout << "[2] Generate password" << std::endl;
    std::cout << "[3] Add password\n" << std::endl;
    std::cout << "[0] Back" << std::endl;
}
