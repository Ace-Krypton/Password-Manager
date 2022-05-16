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

    while (category_input != "quit") {  //If user input different from quit, it adds
        std::cout << "Enter the category name: ";
        std::cin >> category_input;
        categories[category_input];  //Adding categories to the map
        std::cout << std::endl;
    }

    categories.erase("quit");  //Somehow, it adds "quit" to the list I don't know why
    std::cout << "Category(s) added successfully!\n" << std::endl;
}
