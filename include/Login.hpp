#ifndef LOGIN_HPP_
#define LOGIN_HPP_

#include <string>
#include <vector>
#include <unordered_map>

class Login {
    private:

    bool is_there_space(std::string str);

    struct User {
        std::string username_;
        std::string password_;
        std::string name_;
        int birth_year_;
        int height_;
        int weight_;
        std::string objective_;
        int nivel_;
    };

    User user_;

    std::unordered_map<std::string, Login::User> user_data_list;

    public:

    Login();

    void login();

    void insert();

    void test_login();

    bool verify(const std::string &usr, const std::string &pwd);
};

#endif