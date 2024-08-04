#ifndef MENU_HPP_
#define MENU_HPP_

#include "../include/Menu.hpp"
#include "../include/Login.hpp"

class Menu {
    private:
    int option_;
    void clear();

    void options(const Login &L);

    public:

    void initialize();
};

#endif