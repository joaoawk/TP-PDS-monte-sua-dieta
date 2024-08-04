#ifndef LOGIN_HPP_
#define LOGIN_HPP_

#include <string>
#include <vector>
#include <unordered_map>

class Login {
    public:

    struct User {
        std::string username_;
        std::string password_;
        std::string name_;
        char gender_;
        int birth_year_;
        int height_;
        int weight_;
        int level_;
        std::string objective_;
    };

    Login();

    void login();

    void insert();

    bool verify(const std::string &usr, const std::string &pwd);
    
    User user_;

    private:

    std::unordered_map<std::string, Login::User> user_data_list;

};

#endif