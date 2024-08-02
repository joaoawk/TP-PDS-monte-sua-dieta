#ifndef DIETA_HPP_
#define DIETA_HPP_
#include "usuario.hpp"
#include <vector>

class Dieta{
    private:
    
    void Retorna_alimetos(); //responsavel pela recomendação dos pratos. A SER DEFINIDA.
                             // deve levar em consideração Kcal e macronutrientes.
    public:
    double Calcula_metabolismo(Usuario user);//calcula e retorna o metabolismo basal de user em Kcal
    double Calcula_agua_diaria(Usuario user);//calcula e retorna a quantidade de agua diaria a 
                                             //ser ingerida por user em Litros

};
#endif