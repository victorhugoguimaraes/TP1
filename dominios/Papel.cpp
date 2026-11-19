#include "Papel.hpp"
#include <stdexcept>
using namespace std;

void Papel::setCargo(Cargo cargo){
    if (cargo != Gestor && cargo != Desenvolvedor)
        throw invalid_argument("Papel invalido: use Gestor ou Desenvolvedor");
    this->cargo = cargo;
}

Papel::Cargo Papel::getCargo() const{
    return cargo;
}
