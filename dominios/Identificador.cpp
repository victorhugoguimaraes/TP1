#include "Identificador.hpp"
#include "Utilitario.hpp"
#include <stdexcept>

bool Identificador::validacaoIdentificador() const {
    int tamanho = identificador.length();
    if (tamanho != TAMANHO_IDENTIFICADOR) {
        return false;
    }

    for (int i = 0; i < QUANTIDADE_LETRAS; i++) {
        if (!Utilitario::ehLetra(identificador[i])) {
            return false;
        }
    }

    for (int i = 3; i < tamanho; i++) {
        if (!Utilitario::ehDigito(identificador[i])) {
            return false;
        }
    }

    return true;
}
void Identificador::setIdentificador(string identificador) {
    if (identificador.length() != TAMANHO_IDENTIFICADOR)
        throw invalid_argument("Identificador invalido: use 3 letras seguidas de 3 numeros");
    for (int i = 0; i < QUANTIDADE_LETRAS; ++i)
        if (!Utilitario::ehLetra(identificador[i]))
            throw invalid_argument("Identificador invalido: os 3 primeiros caracteres devem ser letras");
    for (int i = QUANTIDADE_LETRAS; i < TAMANHO_IDENTIFICADOR; ++i)
        if (!Utilitario::ehDigito(identificador[i]))
            throw invalid_argument("Identificador invalido: os 3 ultimos caracteres devem ser numeros");
    this->identificador = identificador;
}

string Identificador::getIdentificador() const {
    return identificador;
}
