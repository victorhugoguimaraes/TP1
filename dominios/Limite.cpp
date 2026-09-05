#include "Limite.hpp"
#include <stdexcept>

void Limite::setLimite(int limite) {
    if(limite > limiteMax)
    {
        throw invalid_argument("Limite máximo atingido");
    }
    this->limite = limite;
}

int Limite::getLimite() const {
    return limite;
}

