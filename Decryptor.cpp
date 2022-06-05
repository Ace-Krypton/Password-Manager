#include <iostream>
#include <fstream>
#include "header.hpp"

auto Decryptor::decryptor() -> void {
    auto path = std::string("/home/draco/mySimpleFile");  //Absolute path
    char byte = 0;
    auto read = std::fstream(path);
    std::vector<char> numbers;

    while (read.get(byte)) {
        numbers.emplace_back(byte);
    }

    for (auto const &it : numbers) {
        std::cout << it;
    }
    std::cout << std::endl;

    // split vector into sub-vectors each of size `n`
    int n = 6;

    // determine the total number of sub-vectors of size `n`
    size_t size = (numbers.size() - 1) / n + 1;

    // create an array of vectors to store the sub-vectors
    std::vector<char> vec[size];

    // each iteration of this loop process the next set of `n` elements
    // and store it in a vector at k'th index in `vec`
    for (int k = 0; k < size; ++k) {
        // get range for the next set of `n` elements
        auto start_itr = std::next(numbers.cbegin(), k*n);
        auto end_itr = std::next(numbers.cbegin(), k*n + n);

        // allocate memory for the sub-vector
        vec[k].resize(n);

        // code to handle the last sub-vector as it might
        // contain fewer elements
        if (k*n + n > numbers.size()) {
            end_itr = numbers.cend();
            vec[k].resize(numbers.size() - k*n);
        }

        // copy elements from the input range to the sub-vector
        std::copy(start_itr, end_itr, vec[k].begin());
    }

    // print the sub-vectors
    for (int i = 0; i < size; i++) {
        print(vec[i]);
        Decryptor::decrypted.emplace_back(i);
    }
    
    for (auto const &it : Decryptor::decrypted) {
        std::cout << it << std::endl;
    }
}

// Utility function to print a vector
template<typename T>
auto Decryptor::print(std::vector<T> const &v) -> void  {
    for ([[maybe_unused]] auto &i: v) {
        std::cout << i;
    }
    std::cout << std::endl;
}
