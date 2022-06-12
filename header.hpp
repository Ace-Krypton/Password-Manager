#pragma once
#include <map>
#include <vector>
#include <unordered_map>
#include <string>

auto main_menu() -> void;

class Decryptor {
public:
    static inline std::vector<int> result = {};
    static auto decryptor() -> void;
    template<typename T>
    static auto print([[maybe_unused]] std::vector<T> &v) -> std::vector<int>;
    inline static std::vector<int> decrypted {};
};

struct Encryptor {
public:
    inline static std::map<char, int> encryption {};
    static auto encryption_generator() -> void;
};

struct SortPassword {
public:
    static auto sort_password() -> void;
};

struct PassSearch {
public:
    static auto search_pass() -> void;
};

class AddCategory {
public:
    inline static std::map<int, std::string> passwords {};
    inline static std::unordered_map<int, std::map<std::string, std::string>> passwords_with_url {};
    inline static std::map<std::string, std::string> passwords_with_url_map {};
    inline static std::unordered_map<std::string, std::vector<std::string>> categories {};
    static auto add_category() -> void;
};

class AddPassword {
public:
    static auto print_password_with_url() -> void;
    static auto print_password() -> void;
    static auto print_categories_with_passwords() -> void;
    static auto create_password_with_url() -> void;
    static auto create_password() -> void;
    static auto add_password() -> void;
    static auto add_password_menu() -> void;
    static auto generate_password() -> void;
    static auto generate_password_menu() -> void;
};

struct RemoveCategory {
public:
    static auto remove_category() -> void;
};

class RemovePassword {
public:
    static auto remove_password_from_list() -> void;
    static auto remove_password_from_category() -> void;
    static auto remove_password_menu() -> void;
};

class EditPassword {
public:
    static auto edit_password_menu() -> void;
    static auto edit_password_from_password_list() -> void;
    static auto edit_password_from_category_list() -> void;
    static auto edit_password_from_url_list() -> void;
};
