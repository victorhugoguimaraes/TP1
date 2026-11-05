#ifndef NOME_HPP
#define NOME_HPP

#include <string>

class Nome {
private:
    bool ehLetra(char c) const;
    std::string nome;
    bool validar(const std::string&) const;
public:
    bool setNome(std::string);
    std::string getNome() const;
};


#endif // NOME_HPP
