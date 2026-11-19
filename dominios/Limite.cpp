#include "Limite.hpp"
#include <stdexcept>

void Limite::setLimite(int limite) {
    if(limite < 1 || limite > LIMITE_MAXIMO)
    {
        throw invalid_argument("Limite invalido: deve estar entre 1 e 25");
    }
    this->limite = limite;
}

int Limite::getLimite() const {
    return limite;
}
