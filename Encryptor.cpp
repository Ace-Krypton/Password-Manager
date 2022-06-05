#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <chrono>
#include "header.hpp"

/**
 * @author Ramiz Abbasov
 */

/**
 * Encryptor
 * @return void
 */
auto Encryptor::encryption_generator() -> void {
    auto path = std::string("/home/draco/mySimpleFile");  //Absolute path
    auto write = std::fstream(path, std::ios::out | std::ios::trunc);

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
    }

    std::ifstream read(path);
    char byte = 0;

    if (!read.is_open()) {
        std::cerr << "[-] Could not open the file - '" << path << "'" << std::endl;
    }

    std::string combinations = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_+=[]{};:'\",./?,<~>`|\\1234567890";
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();  //Seed
    std::default_random_engine engine(seed);  //Seeded engine
    int key;

    for (auto &comb : combinations) {
        //std::uniform_int_distribution<int> keys(0, INT16_MAX);  //Generates value between 0 and 32767 for key
        std::uniform_int_distribution<int> keys(100000, 999999);  //Generates value between 0 and 32767 for key
        key = keys(engine);
        Encryptor::encryption[comb] = key;
    }

    auto encrypt = std::fstream(path, std::ios::out | std::ios::app);
    while (read.get(byte)) {
        if (Encryptor::encryption.contains(byte)) {
            for (auto const &it : Encryptor::encryption) {
                if (it.first == byte) {
                    encrypt << it.second;
                }
            }
        }
        std::ofstream ofs;
        ofs.open(path, std::ofstream::out | std::ofstream::trunc);
        ofs.close();
    }
    std::cout << std::endl;
}
