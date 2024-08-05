#include "../include/Login.hpp"
#include "../include/Menu.hpp"
#include "../include/DietProfiles.hpp"
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <limits>

void Menu::clear() {
    std::cout << "\033[2J\033[1;1H";
}

void Menu::options(Login &L) {
    DietProfiles D(L.user_);
    std::unordered_map<std::string, float> macro_list;
    while (true) {
        option_ = 0;
        clear();
        std::cout << L.user_.name_ << ", seja bem-vindo!\n";
        std::cout << "Esta é a parte inicial do Monte sua Dieta. Para acessar a opção, digite: \n\n";
        std::cout << "(1) Calcular seu gasto calórico\n";
        std::cout << "(2) Calcular quanto de água você precisa beber\n";
        std::cout << "(3) Alterar perfil\n";
        std::cout << "(4) Sair\n\n> ";
        std::cin >> option_;
        clear();
        switch(option_) {
            case 1:
                std::cout << "--- Calorias ---\n\n";
                std::cout << "Suas calorias de manutenção são: " << D.get_basal_metabolism() << "kcal \n";
                std::cout << "A quantidade de calorias que você precisa comer é: " << D.get_needed_calories() << "kcal \n";
                macro_list = D.get_macros();
                std::cout << "\n--- Macros ---\n\n";
                std::cout << "Carboidratos: " << static_cast<int>(macro_list["carbs"]) << "g\n";
                std::cout << "Proteinas: " << static_cast<int>(macro_list["proteins"]) << "g\n";
                std::cout << "Gorduras: " << static_cast<int>(macro_list["fats"]) << "g\n\n";

                std::cout << "Para uma alimentação saudável, é recomendável que: \n";
                std::cout << "Coma alimentos ricos em proteínas e carboidratos, além de gorduras boas, como a do abacate.\n";
                std::cout << "Pães, macarrão, arroz, cereais e legumes são ótimas fontes de carboidratos.\n";
                std::cout << "Já leites, fermentados, ovos, soja e carnes em geral são ótimas fontes de proteínas, gorduras e vitaminas.\n";
                break;

            case 2:
                std::cout << "Sua quantidade de água diária é " << D.get_daily_water() << " mL\n";
                std::cout << "Você pode dividir a sua quantidade de água diária em 8x ao dia\n";
                std::cout << "Horários, como antes do almoço e antes da janta são ótimos para saciar a fome.\n";
                std::cout << "Lembre-se de se hidratar constantemente para atingir seus objetivos!\n\n";
                break;

            case 3: {
                int profile_option;

                std::cout << "O que você deseja alterar?\n\n";
                std::cout << "[1] Nome\n";
                std::cout << "[2] Senha\n";
                std::cout << "[3] Altura\n";
                std::cout << "[4] Peso\n";
                std::cout << "[5] Objetivo\n";
                std::cout << "[6] Nível de atividade física\n";
                std::cout << "[7] Voltar\n> ";

                std::cin >> profile_option;
                clear();
                
                switch(profile_option) {
                    case 1:
                        std::cout << "Novo nome: ";
                        std::cin >> L.user_.name_;
                        break;
                    case 2:
                        std::cout << "Nova senha: ";
                        std::cin >> L.user_.password_;
                        break;
                    case 3:
                        std::cout << "Sua altura atual (em cm): ";
                        while (!(std::cin >> L.user_.height_) || L.user_.height_ <= 0) {
                            std::cout << "Valor inválido. Insira uma altura válida: ";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        break;
                    case 4:
                        std::cout << "Seu peso atual (em kg): ";
                        while (!(std::cin >> L.user_.weight_) || L.user_.weight_ <= 0) {
                            std::cout << "Valor inválido. Insira um peso válido: ";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        break;
                    case 5: {
                        int objective_option;
                        std::cout << "Novo objetivo:\n";
                        std::cout << "[1] Ganhar músculo\n";
                        std::cout << "[2] Perder gordura\n";
                        std::cout << "[3] Manutenção calórica\n";
                        std::cin >> objective_option;

                        switch (objective_option) {
                            case 1:
                                L.user_.objective_ = "bulking";
                                break;
                            case 2:
                                L.user_.objective_ = "cutting";
                                break;
                            case 3:
                            default:
                                L.user_.objective_ = "maintenance";
                                break;
                        }
                        break;
                    }
                    case 6:
                        std::cout << "Novo nível de atividade física (1-5): ";
                        while (!(std::cin >> L.user_.level_) || L.user_.level_ < 1 || L.user_.level_ > 5) {
                            std::cout << "Valor inválido. Insira um valor entre 1 e 5: ";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        break;
                    case 7:
                        continue;
                    default:
                        std::cout << "Opção inválida. Tente novamente.\n";
                        break;
                }
                L.update();
                break;
            }

            case 4:
                exit(0);

            default:
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
        }
        std::cout << "\n\nAperte enter para voltar...\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if(option_ == 1) {
            login.login();
            options(login);
        } else if (option_ == 2) {
            clear();
            login.insert();
        } else if (option_ == 3) {
            exit(0);
        } else {
            std::cout << "Opção inválida. Tente novamente.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
