#ifndef FOOD_HPP_
#define FOOD_HPP_

#include <string>

class Food {
    private:
    std::string name_;
    int calories_;
    int carbo_;
    int proteins_;
    int fats_;

    public:
    Food (std::string name, 
    int calories,
    int carbo,
    int proteins,
    int fats)
    : name_(name),
    calories_(calories),
    carbo_(carbo),
    proteins_(proteins),
    fats_(fats) {}

    std::string get_name() const{
        return name_;
    }
    int calories get_calories() const{
        return calories_;
    }
    int carbo get_carbo() const{
        return carbo_;
    }
    int proteins get_proteins() const{
        return proteins_;
    }
    int fats get_fats() const{
        return fats_;
    }

};
#endif
