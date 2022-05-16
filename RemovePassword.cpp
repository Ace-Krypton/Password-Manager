#include <iostream>
#include "header.hpp"

auto RemovePassword::remove_password_from_list() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "Removes selected password(s) from password list" << std::endl;

}

auto RemovePassword::remove_password_from_category() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "Removes selected password(s) from categories" << std::endl;

}

auto RemovePassword::remove_password_menu() -> void {
    std::cout << "+-----------------------------------------------------------------------------------+\n" << std::endl;
    std::cout << "[1] Remove password(s) from password list" << std::endl;
    std::cout << "[2] Remove password(s) from categories\n" << std::endl;
    std::cout << "[0] Back" << std::endl;
}
