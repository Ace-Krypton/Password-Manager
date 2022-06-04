#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>
#include "header.hpp"

/**
 * @author Ramiz Abbasov
 */

/**
 * TODO 1. Take user choices for ::app or ::trunc or whatever
 */

auto Encryptor::encryption_generator() -> void {
    auto path = std::string("/home/draco/mySimpleFile");  //Absolute path
    //auto write = std::fstream(path, std::ios::out | std::ios::trunc);

    /*auto write = std::fstream(path, std::ios::out | std::ios::trunc);

    //Writing Password List
    if (!(AddCategory::passwords.empty())) {
        write << "\t\t\t\tPassword List" << std::endl;
        for (const auto &pass: AddCategory::passwords) {
            write << "[*] " << pass.first << " : " << pass.second << std::endl;
        }
        write << "\n";
    }

    //Writing URL List
    if (!(AddCategory::passwords_with_url.empty())) {
        write << "\t\t\t\t  URL List" << std::endl;
        for (const auto &password_with_url : AddCategory::passwords_with_url) {
            write << "[*] " << password_with_url.first << " : ";
            for (const auto &url_map : password_with_url.second) {
                write << "URL: " << url_map.first << " : " << "Password: " << url_map.second << std::endl;
            }
        }
        write << '\n';
    }

    //Writing Category List
    if (!(AddCategory::categories.empty())) {
        write << "\t\t\t\tCategory List" << std::endl;
        for (auto &category : AddCategory::categories) {
            auto value = AddCategory::categories.find(category.first);
            write << '\n' << category.first << ": " << std::endl;
            for (auto const &matched : category.second) {
                write << "[*] " << matched;
            }
            if (value->second.empty()) write << "\nNo passwords found";
            write << "\n------------------------" << std::endl;
        }
    }*/  //Writing to file

    std::ifstream input_file(path);
    char byte = 0;
    if (!input_file.is_open()) {
        std::cerr << "[-] Could not open the file - '"
             << path << "'" << std::endl;
    }

    std::map<char, int> encryption;
    std::string combinations = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_+=[]{};:'\",./?,<~>`|\\1234567890";
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();  //Seed
    std::default_random_engine engine(seed);  //Seeded engine
    int key;

    for (auto &comb : combinations) {
        std::uniform_int_distribution<int> keys(0, INT16_MAX);  //Generates value between 0 and 32767 for key
        key = keys(engine);
        encryption[comb] = key;
    }

//    for (auto const &it : encryption) {
//        std::cout << it.first << " : " << it.second << std::endl;
//    }

    while (input_file.get(byte)) {
        if (encryption.contains(byte)) {
            for (auto const &it : encryption) {
                if (it.first == byte) {
                    std::cout << it.second;
                }
            }
        }
    }
    std::cout << std::endl;
}
