#include <iostream>
#include <fstream>
#include "header.hpp"

// Utility function to print a vector
template<typename T>
auto Decryptor::print(std::vector<T> const &v) -> void {
    for ([[maybe_unused]] auto &i: v) {
        std::cout << i;
    }
    std::cout << std::endl;
}

auto Decryptor::decryptor() -> void {
    //Absolute path (I will change it to the Relative path after I finish with testing)
    auto path = std::string("/home/draco/mySimpleFile");
    //Reading char by char
    char byte = 0;
    //Read stream
    auto read = std::fstream(path);
    //Will store chars that we read from file
    std::vector<char> numbers;

    //Reading and pushing them to the vector
    while (read.get(byte)) {
        numbers.emplace_back(byte);
    }

    //Printing the char vector
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
    }
}
