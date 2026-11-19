#include "Prioridade.hpp"
#include <stdexcept>
using namespace std;

void Prioridade::setPrioridade(Nivel prioridade){
    if (prioridade != ALTA && prioridade != MEDIA && prioridade != BAIXA)
        throw invalid_argument("Prioridade invalida: use Alta, Media ou Baixa");
    this->prioridade = prioridade;
}

Prioridade::Nivel Prioridade::getPrioridade() const{
    return prioridade;
}
