#ifndef USUARIO_HPP_
#define USUARIO_HPP_
#include <string>
#include <unordered_map>

class Usuario {
    private:

    std::string nome;
    std::string senha;

    public:

    std::unordered_map<std::string, std::string> listaUsuarioSenha();

    bool validarCredenciais(std::string nome_, std::string senha_);

    void acessarConta(std::string nome_, std::string senha_);

    void registrarUsuario();
    
};

#endif