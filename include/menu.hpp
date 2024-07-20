#ifndef MENU_HPP_
#define MENU_HPP_
#include <string>

class Menu {
    private:
    
    public:
    std::string nome;
    int opcao_menu;

    Menu();

    void iniciarLogin();
    
    void menuInicial();

    void mostrarOpcoes();
};

#endif