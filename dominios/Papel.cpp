#include "Papel.hpp"
#include <stdexcept>

void Papel::setCargo(Cargo cargo){
    if (cargo != Gestor && cargo != Desenvolvedor)
        throw std::invalid_argument("Papel invalido");
    this->cargo = cargo;
}

Papel::Cargo Papel::getCargo() const{
    return cargo;
}
