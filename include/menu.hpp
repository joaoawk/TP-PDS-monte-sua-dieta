#ifndef MENU_HPP_
#define MENU_HPP_
#include <string>

class Menu {
    private:
    
    std::string nome;
    int opcao_menu;

    public:

    Menu();

    void iniciarLogin();
    
    void menuInicial();

    void mostrarOpcoes();

    
};

#endif