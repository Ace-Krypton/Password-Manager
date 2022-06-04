#include <iostream>
#include <string>
#include "header.hpp"

/**
* @author Ramiz Abbasov
*/

/**
 * TODO 1. Ask: could we use multimap to sort?
 */

/**
 * Returns list of all passwords, sorted
 * @return void
 */
auto SortPassword::sort_password() -> void {
    std::multimap<int, std::string> sorted_password_list;

    for (auto &it : AddCategory::passwords) {
        sorted_password_list.insert({ it.first, it.second });
    }

    for (auto const &it : sorted_password_list) {
        std::cout << it.first << ": " << it.second << std::endl;
    }
}
