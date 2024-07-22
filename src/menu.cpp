#include "../include/menu.hpp"
#include "../include/usuario.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

Menu::Menu() {
    iniciarLogin();
    menuInicial();
    mostrarOpcoes();
}

void Menu::iniciarLogin() {
    std::string nome_usuario;
    std::string senha_usuario;
    Usuario usuario;

    std::cout << "Por favor, digite seu usuário e senha " << std::endl;
    while(std::cin >> nome_usuario >> senha_usuario) {
        if(usuario.validarCredenciais(nome_usuario, senha_usuario)) {
            std::cout << "Conta acessada com sucesso!" << std::endl;
            std::cout << std::endl;
            break;
        } else {
            std::cout << "Usuario ou senha incorretos! Tente novamente" << std::endl;
        }
    }
    nome = nome_usuario;
}

void Menu::menuInicial() {
    std::cout << "Bem-vindo/(a), " << nome << ", ao Monte sua Dieta!" << std::endl;
    std::cout << "Para começar, digite o número à esquerda do item" << std::endl;
}

void Menu::mostrarOpcoes() {
    std::cout << "(1) Calcular seu gasto calórico" << std::endl;
    std::cout << "(2) Calcular quanto de água você precisa beber" << std::endl;
    std::cout << "(3) Sugestão de alimentos saudáveis para consumir" << std::endl;
    std::cout << "(4) Alterar informações físicas" << std::endl;
    std::cout << "(5) Sair" << std::endl;

    while (std::cin >> opcao_menu) {
        switch(opcao_menu) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;

            case 4:
                
                break;
            
            case 5:
                exit(0);
                break;
        }
    }
}