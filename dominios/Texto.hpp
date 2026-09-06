#ifndef TEXTO_HPP_INCLUDED
#define TEXTO_HPP_INCLUDED

#include <string>

class Texto {
private:
    bool ehLetra(char c) const;
    bool ehDigito(char c) const;
    bool ehMaius(char c) const;
    bool ehAlfanumerico(char c) const;
    bool ehPontuacao(char c) const;
    std::string texto;
    bool validar(const std::string&) const;
public:
    bool setTexto(std::string);
    std::string getTexto() const;
};

#endif // TEXTO_HPP_INCLUDED
