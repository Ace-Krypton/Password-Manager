#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "header.hpp"

/**
 * Add Category
 * @return void
 */
auto AddCategory::add_category() -> void {
    //Unordered map for storing categories and their passwords
    std::unordered_map<std::string, std::vector<std::string>> categories;
    std::string category_input;  //User input
    std::vector<std::string> passwords {"1l1k3l1nux", "ramiz852"};
    std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
    std::cout << "      Adds a new category to be used with creating new passwords\n"
                 "                      For stop adding type \"quit\"\n" << std::endl;

    while (category_input != "quit") {  //If user input different from quit, it adds
        std::cout << "Enter the category name: ";
        std::cin >> category_input;
        categories[category_input];  //Adding categories to the map
        std::cout << std::endl;
    }

    std::cout << "Category(s) added successfully\n" << std::endl;
}
