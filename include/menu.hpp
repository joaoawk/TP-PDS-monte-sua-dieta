#ifndef MENU_HPP_
#define MENU_HPP_
#include <string>

class Menu {
    private:
    
    public:
    std::string nome;
    int selecao_menu;

    Menu();

    void iniciarLogin();
    
    void menuInicial();

    void mostrarOpcoes();
};

#endif