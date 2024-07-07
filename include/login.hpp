#ifndef LOGIN_HPP_
#define LOGIN_HPP_
#include <string>
#include <unordered_map>

class Usuario {
    public:

    std::string nome;
    std::string senha;

    std::unordered_map<std::string, std::string> listaUsuarioSenha();

    bool validarCredenciais(std::string nome_, std::string senha_);

    void acessarConta(std::string nome_, std::string senha_);

    void registrarUsuario();
    
};

#endif