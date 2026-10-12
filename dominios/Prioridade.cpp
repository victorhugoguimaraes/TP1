#include "Prioridade.hpp"
#include <stdexcept>

void Prioridade::setPrioridade(Nivel prioridade){
    if (prioridade != ALTA && prioridade != MEDIA && prioridade != BAIXA)
        throw std::invalid_argument("Prioridade invalida");
    this->prioridade = prioridade;
}

Prioridade::Nivel Prioridade::getPrioridade() const{
    return prioridade;
}
