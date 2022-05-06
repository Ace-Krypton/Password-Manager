#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include "header.hpp"

/**
 * Password searching
 * @return void
 */
auto PassSearch::pass_search() -> void {
    std::string category_input;  //User input
    std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
    std::cout << "        Password search will return passwords matching the specified criteria\n" << std::endl;
//    std::cout << "Enter the category: ";
//    std::cin >> category_input;

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine engine(seed);
    std::uniform_int_distribution<int> distr(0, 5);
    std::cout << distr(engine) << std::endl;
}
