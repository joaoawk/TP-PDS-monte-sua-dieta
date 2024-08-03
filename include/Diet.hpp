#ifndef DIET_HPP_
#define DIET_HPP_
#include "usuario.hpp"
#include <vector>

class Diet{
    public:
    double daily_water(Usuario user);
    double calc_metabolism(Usuario user);
};

#endif