#include "Identificador.hpp"
#include <stdexcept>

bool Identificador::ehLetra(char c) const {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool Identificador::ehDigito(char c) const {
    return c >= '0' && c <= '9';
}

bool Identificador::validacaoIdentificador() const {
    int tamanho = identificador.length();
    if(tamanho != 6)
    {
        return false;
    }

    for(int i = 0; i < 3; i++)
    {   
        if(!ehLetra(identificador[i]))
        {
            return false;
        }
    }

    for(int i = 3; i < tamanho; i++)
    {
        if(!ehDigito(identificador[i] ))
        {
            return false;
        }
    }

    return true;

}
void Identificador::setIdentificador(string identificador) {
    this->identificador = identificador;

    if (!validacaoIdentificador()) {
        throw invalid_argument("Identificador invalido");
    }
}

string Identificador::getIdentificador() const {
    return identificador;
}