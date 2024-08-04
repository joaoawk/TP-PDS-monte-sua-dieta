#ifndef DIETPROFILES_HPP_
#define DIETPROFILES_HPP_

#include "Login.hpp"

class DietProfiles {
    private:
    int calories_;

    public:
    Login::User user_;

    DietProfiles(const Login::User &user);

    void set_calories(int weight, int height, char gender, int birth_year);

    int get_carlories();
};

#endif