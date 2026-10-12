#include "Estado.hpp"
#include <stdexcept>

void Estado::setEstado(Status estado){
    if (estado != A_FAZER && estado != FAZENDO && estado != FEITO)
        throw std::invalid_argument("Estado invalido");
    this->estado = estado;
}

Estado::Status Estado::getEstado() const{
    return estado;
}
