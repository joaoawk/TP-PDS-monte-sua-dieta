#ifndef DIET_HPP_
#define DIET_HPP_
#include "usuario.hpp"
#include <vector>

class Diet{
    private:
    vector<double> diet_; // [0] = Kcal total, [1] = gde proteinas, [2] = g de gorduras, [3] = g de carboidratos
    double calc_protein(); //qtd proteinas em g
    double calc_fats(); //qtd gorduras em g
    double calc_carbs(); //qtd carboidratos em g
    public:
    vector<double> Diet(Usuario user);
    double daily_water(Usuario user);
    double calc_metabolism(Usuario user);

};

#endif