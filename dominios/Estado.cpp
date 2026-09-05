#include "Estado.hpp"

void Estado::setEstado(Status estado){
    this->estado = estado;
}

Estado::Status Estado::getEstado() const{
    return estado;
}
