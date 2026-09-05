#include "Papel.hpp"

void Papel::setCargo(Cargo cargo){
    this->cargo = cargo;
}

Papel::Cargo Papel::getCargo() const{
    return cargo;
}
