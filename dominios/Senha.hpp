#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include <string>

class Senha {
    private:
        bool ehLetra(char c) const;
        bool ehDigito(char c) const;
        std::string senha;
        bool validar(const std::string&) const;
    public:
        bool setValor(std::string);
        std::string getValor() const;
    };

#endif // SENHA_HPP_INCLUDED
