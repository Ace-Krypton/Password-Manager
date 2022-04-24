#include <iostream>
#include <string>
#include <unordered_map>
#include "header.hpp"

/**
 * Add Category
 * @return void
 */
auto AddCategory::add_category() -> void {
    std::unordered_map<int, std::string> categories;  //Unordered map for storing categories and their IDs
    std::string category_input;  //User input
    int count = 0;  //Category ID or we can say "Key"
    std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
    std::cout << "      Adds a new category to be used with creating new passwords\n"
                 "                      For stop adding type \"quit\"\n" << std::endl;

    while (category_input != "quit") {
        std::cout << "Enter the category name: ";
        std::cin >> category_input;
        categories[count++] = category_input;
    }

    std::cout << "Category(s) added successfully" << std::endl;
}
