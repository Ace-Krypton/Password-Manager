#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
    std::vector<std::pair<int, std::map<std::string, std::string>>> elems(AddCategory::passwords_with_url.begin(), AddCategory::passwords_with_url.end());
    std::vector<std::pair<std::string, std::vector<std::string>>> elems2(AddCategory::categories.begin(), AddCategory::categories.end());

    for (auto &it : AddCategory::passwords) {
        sorted_password_list.insert({ it.first, it.second });
    }

    for (auto const &it : sorted_password_list) {
        std::cout << it.first << ": " << it.second << std::endl;
    }

    std::sort(elems.begin(), elems.end());

    for (auto const &it : elems) {
        std::cout << "[*] " << it.first << ": ";
        for (auto const &it2 : it.second) {
            std::cout << it2.first << ": " << it2.second << std::endl;
        }
    }

    std::sort(elems2.begin(), elems2.end());

    for (auto const &it : elems2) {
        std::cout << "[*] " << it.first << ": ";
        for (auto const &it2 : it.second) {
            std::cout << it2 << std::endl;
        }
    }
}
