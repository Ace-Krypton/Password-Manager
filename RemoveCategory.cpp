#include <iostream>
#include "header.hpp"

/**
 * Removes category
 * @return void
 */
auto RemoveCategory::remove_category() -> void {
    std::string removal_input;  //User input

    if (AddCategory::categories.empty()) {  //If key is empty, then print info
        std::cout << "You don't have any categories yet. Please, create one\n" << std::endl;
        return;
    }

    std::cout << "\t\t\t\tPlease choose a category\n" << std::endl;
    for (auto &category : AddCategory::categories) {  //Prints out categories
        std::cout << "[+] " << category.first << std::endl;
    }

    std::cout << "\nEnter the category: ";
    std::cin >> removal_input;

    AddCategory::categories.erase(removal_input);
    std::cout << removal_input << " successfully removed!" << std::endl;
}
