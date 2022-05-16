#pragma once
#include <map>
#include <vector>
#include <unordered_map>
#include <string>

auto main_menu() -> void;
class PassSearch {
public:
    static auto pass_search() -> void;
};

class AddCategory {
public:
    inline static std::map<int, std::string> passwords {};
    inline static std::unordered_map<int, std::map<std::string, std::string>> passwords_with_url;
    inline static std::map<std::string, std::string> passwords_with_url_map;
    inline static std::unordered_map<std::string, std::vector<std::string>> categories {};
    static auto add_category() -> void;
};

class AddPassword {
public:
    static auto print_password_with_url(const std::unordered_map<int, std::map<std::string, std::string>> &passwords_with_url) -> void;
    static auto print_password(const std::map<int, std::string>& passwords) -> void;
    static auto create_password_with_url() -> void;
    static auto create_password() -> void;
    static auto add_password() -> void;
    static auto add_password_menu() -> void;
    static auto generate_password() -> void;
    static auto generate_password_menu() -> void;
};

class RemoveCategory {
public:
    static auto remove_category() -> void;
};
