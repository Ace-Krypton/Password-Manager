cmake_minimum_required(VERSION 3.22)
project(PasswordManager)

set(CMAKE_CXX_STANDARD 20)

add_executable(PasswordManager main.cpp header.hpp SearchPassword.cpp AddCategory.cpp AddPassword.cpp RemoveCategory.cpp RemovePassword.cpp EditPassword.cpp SortPassword.cpp Encryptor.cpp Decryptor.cpp Documentation.cpp)
