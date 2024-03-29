#include <iostream>
#include "header.hpp"

/**
 * @author Ramiz Abbasov
 */

/**
 * Removes category
 * @return void
 */
auto RemoveCategory::remove_category() -> void {
    std::string removal_input;

    //If key is empty, then print info
    if (AddCategory::categories.empty()) {
        std::cout << "[-] You don't have any categories yet. Please, create one\n" << std::endl;
        return;
    }

    std::cout << "\t\t\t\tPlease choose a category\n" << std::endl;

    //Prints out categories
    for (auto &category : AddCategory::categories) {
        std::cout << "[+] " << category.first << std::endl;
    }

    std::cout << "\nEnter the category: ";
    std::cin >> removal_input;

    //If user entered category is present do this
    if (AddCategory::categories.contains(removal_input)) {
        AddCategory::categories.erase(removal_input);
        std::cout << removal_input << " successfully removed!" << std::endl;
    }

    else std::cout << "[-] Category name does not exist! Try again\n" << std::endl;
}
