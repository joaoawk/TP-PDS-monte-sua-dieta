#include "../include/Login.hpp"

#include <fstream>
#include <iostream>

Login::Login() {
    std::ifstream user_data("user-data.txt");
    Login::User temp_user;
    while (user_data >> temp_user.username_
                     >> temp_user.password_
                     >> temp_user.name_
                     >> temp_user.birth_year_
                     >> temp_user.height_
                     >> temp_user.weight_
                     >> temp_user.objective_
                     >> temp_user.nivel_) {
        user_data_list[temp_user.username_] = temp_user;
    }
}

void Login::login() {
    std::string temp_username_;
    std::string temp_password_;

    std::cout << "Por favor, digite seu usuário e senha" << std::endl;
    while (std::cin >> temp_username_ >> temp_password_) {
        if (verify(temp_username_, temp_password_)) {
            user_ = user_data_list[temp_username_];
            break;
        } else {
            std::cout << "Usuário ou senha incorretos! Tente novamente\n";
        }
    }
}

void Login::insert() {
    User temp_user;
    int temp_choice;
    while (true) {
        std::cout << "Username: ";
        std::cin >> temp_user.username_;
        if (user_data_list.find(temp_user.username_) != user_data_list.end()) {
            std::cout << "Usuario já existente no banco de dados ou invalido! Tente outro nickname.\n";
        } else {
            break;
        }
    }

    std::cout << "Senha: ";
    std::cin >> temp_user.password_;

    std::cout << "Seu primeiro nome: ";
    std::cin >> temp_user.name_;

    std::cout << "Seu ano de nascimento: ";
    std::cin >> temp_user.birth_year_;

    std::cout << "Sua altura em centimetros: ";
    std::cin >> temp_user.height_;

    std::cout << "Seu peso: ";
    std::cin >> temp_user.weight_;

    std::cout << "Qual seu objetivo?\n";
    std::cout << "[1] Ganhar musculo\n";
    std::cout << "[2] Perder gordura\n";
    std::cout << "[3] Manutenção calórica\n";
    std::cout << "[any] Qualquer outra tecla será manutenção calórica. Se quiser mudar depois, veja no aplicativo\n";
    std::cin >> temp_choice;
    switch (temp_choice) {
        case 1:
            temp_user.objective_ = "bulking";
            break;
        case 2:
            temp_user.objective_ = "cutting";
            break;
        case 3:
            temp_user.objective_ = "maintenance";
            break;
        default:
            temp_user.objective_ = "maintenance";
    }

    std::cout << "De 1 a 5, qual seu nível de atividade física?\n";
    while (true) {
        std::cin >> temp_user.nivel_;
        if (temp_user.nivel_ < 1 || temp_user.nivel_ > 5) {
            std::cout << "Só são permitidos valores de 1 a 5. Insira outro.\n";
        } else {
            break;
        }
    }

    user_data_list[temp_user.username_] = temp_user;

    std::ofstream user_data("user-data.txt", std::ios::app);
    if (user_data.is_open()) {
        user_data << temp_user.username_ << " "
                  << temp_user.password_ << " "
                  << temp_user.name_ << " "
                  << temp_user.birth_year_ << " "
                  << temp_user.height_ << " "
                  << temp_user.weight_ << " "
                  << temp_user.objective_ << " "
                  << temp_user.nivel_ << std::endl;
        user_data.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de dados do usuário para escrita!" << std::endl;
    }
}

bool Login::verify(const std::string& usr, const std::string& pwd) {
    if (user_data_list.find(usr) != user_data_list.end()) {
        return user_data_list[usr].password_ == pwd;
    }
    return false;
}
