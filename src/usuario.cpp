#include "../include/usuario.hpp"
#include <unordered_map>
#include <fstream>

std::unordered_map<std::string, std::string> Usuario::listaUsuarioSenha() {
    std::ifstream arquivoDeLogin("login-lista.txt");
    std::unordered_map<std::string, std::string> logins_;
    std::string temp_nome;
    std::string temp_senha;
    while(arquivoDeLogin >> temp_nome >> temp_senha) {
        logins_[temp_nome] = temp_senha;
    }
    return logins_;
}

bool Usuario::validarCredenciais(std::string nome_, std::string senha_) {
    std::unordered_map<std::string, std::string> logins_ = listaUsuarioSenha();
    return (logins_[nome_] == senha_);
}

void Usuario::acessarConta(std::string nome_, std::string senha_) {
    if(validarCredenciais(nome_, senha_)) {
        // TODO implementar entrada do usuário
    }
}

void Usuario::registrarUsuario() {
        // TODO Registrar o usuário na base de dados "login-lista.txt"
}
