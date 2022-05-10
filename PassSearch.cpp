#include <iostream>
#include <string>
#include "header.hpp"

/**
 * Password searching
 * @return void
 */
auto PassSearch::pass_search() -> void {
    std::string category_input;  //User input
    std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
    std::cout << "        Password search will return passwords matching the specified criteria\n" << std::endl;
    std::cout << "Enter the category: ";
    std::cin >> category_input;
}
