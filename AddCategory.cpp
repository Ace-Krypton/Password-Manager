#include <iostream>
#include <string>
#include "header.hpp"

/**
 * Adds a category
 * @return void
 */
auto AddCategory::add_category() -> void {
    //Unordered map for storing categories and their passwords
    std::string category_input;  //User input
    std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
    std::cout << "      Adds a new category to be used with creating new passwords\n"
                 "                      For stop adding type \"quit\"\n" << std::endl;

    //If user input different from quit, it adds
    while (category_input != "quit") {
        std::cout << "Enter the category name: ";
        std::cin >> category_input;
        categories[category_input];  //Adding categories to the map
        std::cout << std::endl;
    }

    categories.erase("quit");  //It adds "quit" also that's why I did that
    std::cout << "Category(s) added successfully!\n" << std::endl;
}
