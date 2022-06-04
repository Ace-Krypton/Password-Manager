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
    //Multimap for sorting the password list
    std::multimap<int, std::string> sorted_password_list;
    //Made pair and added all unordered map to vector, so it will be easy to sort
    std::vector<std::pair<int, std::map<std::string, std::string>>> sorted_url_list (AddCategory::passwords_with_url.begin(), AddCategory::passwords_with_url.end());
    std::vector<std::pair<std::string, std::vector<std::string>>> sorted_category_list (AddCategory::categories.begin(), AddCategory::categories.end());

    //Adding elements from password list to multimap
    for (auto &it : AddCategory::passwords) {
        sorted_password_list.insert({ it.first, it.second });
    }

    std::cout << "\tSorted Password List" << std::endl;
    if (sorted_password_list.empty()) {
        std::cout << "[-] Your Password List is empty\n" << std::endl;
    }

    //Printing our multimap
    else {
        for (auto const &it : sorted_password_list) {
            std::cout << it.first << ": " << it.second << std::endl;
        }
        std::cout << '\n';
    }

    //Sorting the URL List vector with using std::sort
    std::sort(sorted_url_list.begin(), sorted_url_list.end());

    std::cout << "\tSorted URL List" << std::endl;
    if (sorted_url_list.empty()) {
        std::cout << "[-] Your URL List is empty\n" << std::endl;
    }

    //Printing the sorted URL List vector
    else {
        for (auto const &it : sorted_url_list) {
            std::cout << "[*] " << it.first << ": ";
            for (auto const &it2 : it.second) {
                std::cout << it2.first << ": " << it2.second << std::endl;
            }
        }
        std::cout << '\n';
    }

    //Sorting the Category List with using std::sort
    std::sort(sorted_category_list.begin(), sorted_category_list.end());

    std::cout << "\tSorted Category List" << std::endl;
    if (sorted_category_list.empty()) {
        std::cout << "[-] Your Category List is empty\n" << std::endl;
    }

    //Printing the sorted Category List
    else {
        for (auto const &it : sorted_category_list) {
            std::cout << "[*] " << it.first << ": ";
            for (auto const &it2 : it.second) {
                std::cout << it2 << std::endl;
            }
        }
        std::cout << '\n';
    }
}
