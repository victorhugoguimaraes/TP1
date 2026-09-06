#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include <string>

class Nome {
private:
    bool ehLetra(char c) const;
    bool ehDigito(char c) const;
    std::string nome;
    bool validar(const std::string&) const;
public:
    bool setNome(std::string);
    std::string getNome() const;
};


#endif // NOME_HPP_INCLUDED
