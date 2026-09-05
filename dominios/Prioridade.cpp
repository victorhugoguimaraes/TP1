#include "Prioridade.hpp"

void Prioridade::setPrioridade(Nivel prioridade){
    this->prioridade = prioridade;
}

Prioridade::Nivel Prioridade::getPrioridade() const{
    return prioridade;
}
