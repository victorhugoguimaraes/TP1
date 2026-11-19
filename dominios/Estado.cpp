#include "Estado.hpp"
#include <stdexcept>
using namespace std;

void Estado::setEstado(Status estado){
    if (estado != A_FAZER && estado != FAZENDO && estado != FEITO)
        throw invalid_argument("Estado invalido: use A_FAZER, FAZENDO ou FEITO");
    this->estado = estado;
}

Estado::Status Estado::getEstado() const{
    return estado;
}
