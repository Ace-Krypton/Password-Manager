#pragma once

auto main_menu() -> void;

class PassSearch {
    public:
        static auto pass_search() -> void;
};

class AddCategory {
    public:
        static auto add_category() -> void;
};

class AddPassword {
    public:
        static auto add_password() -> void;
        static auto add_password_menu() -> void;
        static auto generate_password() -> void;
        static auto generate_password_menu() -> void;
};
