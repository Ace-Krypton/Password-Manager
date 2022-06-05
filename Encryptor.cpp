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
    //Absolute path (I will change it to the Relative path after I finish with testing)
    auto path = std::string("/home/draco/mySimpleFile");
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

    //Read Stream
    std::ifstream read(path);
    //Reading char by char
    char byte = 0;

    //If file is not exist or could not open the file it throws error
    if (!read.is_open()) {
        std::cerr << "[-] Could not open the file - '" << path << "'" << std::endl;
    }

    //Combinations that we will check for written data
    std::string combinations = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_+=[]{};:'\",./?,<~>`|\\1234567890";
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();  //Seed
    std::default_random_engine engine(seed);  //Seeded engine
    int key;  //key is the encryption, will contain random numbers between 100000 and 999999

    //Looping through every combination(char) from std::string combinations
    for (auto &combination : combinations) {
        //std::uniform_int_distribution<int> keys(0, INT16_MAX);  //Generates value between 0 and 32767 for key
        std::uniform_int_distribution<int> keys(100000, 999999);  //Generates value between 100000 and 999999 for key
        key = keys(engine);  //Initializing with random value
        Encryptor::encryption[combination] = key;  //Creating our encryption list with chars and random values
    }

    //Writing stream with append flag, we will append the matched data to the file
    auto encrypt = std::fstream(path, std::ios::out | std::ios::app);
    //Reading the file
    while (read.get(byte)) {
        //contains() requires key to check, in this case my key is combination which is char
        if (Encryptor::encryption.contains(byte)) {
            for (auto const &it : Encryptor::encryption) {
                //If the char equals to the read data then we write the value(random int) of our key(char)
                if (it.first == byte) {
                    encrypt << it.second;
                }
            }
        }
        //In order to get rid of last written unencrypted data I opened a new stream and closed it
        //This helped me to remove the unencrypted data
        std::ofstream ofs;
        ofs.open(path, std::ofstream::out | std::ofstream::trunc);
        ofs.close();
    }
    std::cout << std::endl;
}
