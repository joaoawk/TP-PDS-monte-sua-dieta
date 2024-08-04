#ifndef DIETPROFILES_HPP_
#define DIETPROFILES_HPP_

#include "Login.hpp"

class DietProfiles {
    private:
    int calories_;

    public:
    Login::User user_;

    DietProfiles(const Login::User &user);

    void set_basal_metabolism(int weight, int height, char gender, int birth_year);

    int get_basal_metabolism();

    int get_daily_water();

    int get_needed_calories();
};

#endif