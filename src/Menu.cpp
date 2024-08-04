#include "../include/Login.hpp"
#include "../include/Menu.hpp"
#include "../include/DietProfiles.hpp"
#include <iostream>
#include <cstdlib>
#include <unordered_map>

void Menu::clear() {
    std::cout << "\033[2J\033[1;1H";
}

void Menu::options(const Login &L) {
    DietProfiles D(L.user_);
    std::unordered_map<std::string, float> macro_list;
    while (true) {
    option_ = 0;
        clear();
        std::cout << L.user_.name_ << ", seja bem-vindo!\n";
        std::cout << "Esta é a parte inicial do Monte sua Dieta. Para acessar a opcao, digite: \n\n";
        std::cout << "(1) Calcular seu gasto calórico\n";
        std::cout << "(2) Calcular quanto de água você precisa beber\n";
        std::cout << "(3) Alterar perfil\n";
        std::cout << "(4) Sair\n";
        std::cin >> option_;
        clear();
        switch(option_) {
            case 1:
                std::cout << "--- Calorias ---\n\n";
                std::cout << "Suas calorias de manutenção são: " << D.get_basal_metabolism() << "kcal \n";
                std::cout << "A quantidade de calorias que você precisa comer é: " << D.get_needed_calories() << "kcal \n";
                macro_list = D.get_macros();
                std::cout << "\n--- Macros ---\n\n";
                std::cout << "Carboidratos: " << static_cast<int> (macro_list["carbs"]) << "g\n";
                std::cout << "Proteinas: " << static_cast<int> (macro_list["proteins"]) << "g\n";
                std::cout << "Gorduras: " << static_cast<int>(macro_list["fats"]) << "g\n\n";

                break;

            case 2:
                std::cout << "Sua quantidade de água diária é " << D.get_daily_water() << " mL\n";
                std::cout << "Você pode dividir a sua quantidade de água diária em 8x ao dia\n";
                std::cout << "Horários, como antes do almoço e antes da janta são ótimos para saciar a fome.\n";
                std::cout << "Lembre-se de se hidratar constantemente para atingir seus objetivos!\n\n";
                break;

            case 3:
                std::cout << "Função para alterar perfil ainda não implementada\n";
                break;

            case 4:
                exit(0);

            default:
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
        }
        std::cout << "Aperte enter para voltar...\n";
        std::cin.ignore();
        std::cin.get();
    }
}

void Menu::initialize() {
    Login login;
    while (true) {
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
            options(login);
        } else if (option_ == 2) {
            clear();
            login.insert();
        } else {
            exit(0);
        }
    }
}
