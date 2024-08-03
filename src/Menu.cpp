#include "../include/Login.hpp"
#include "../include/Menu.hpp"
#include <iostream>
#include <cstdlib>

void Menu::clear() {
    std::cout << "\033[2J\033[1;1H";
}

void Menu::options() {
    clear();
    option_ = 0;
    std::cout << "Esta é a parte inicial do Monte sua Dieta. Para acessar a opcao, digite: \n\n";
    std::cout << "(1) Calcular seu gasto calórico\n";
    std::cout << "(2) Calcular quanto de água você precisa beber\n";
    std::cout << "(3) Calcular macros\n";
    
    std::cout << "(4) Sair\n";
    while(option_ > 4 || option_ < 1) {
        std::cin >> option_;
        switch(option_) {
            case 1:
            // TODO

            break;

            case 2:
            // TODO
            break;

            case 3:
            // TODO
            break;

            case 4:
            exit(0);
            break;
        }
    }
}

void Menu::initialize() {
    Login login;
    clear();
    std::cout << "Bem-vindo ao Monte sua dieta!\n";
    std::cout << "Digite o número para acessar a devida opção\n";
    std::cout << std::endl;
    std::cout << "[1] Login\n";
    std::cout << "[2] Registro\n";
    std::cout << "[3] Encerrar\n";

    std::cin >> option_;

    if(option_ == 1) {
        login.login();
        options();
    } else if (option_ == 2) {
        clear();
        login.insert();
    } else {
        exit(0);
    }
}