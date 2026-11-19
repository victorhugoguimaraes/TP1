#include "Tamanho.hpp"
#include <stdexcept>
using namespace std;

void Tamanho::setTamanho(Nivel tamanho){
    if (tamanho != GRANDE && tamanho != MEDIO && tamanho != PEQUENO)
        throw invalid_argument("Tamanho invalido: use Grande, Medio ou Pequeno");
    this->tamanho = tamanho;
}

Tamanho::Nivel Tamanho::getTamanho() const{
    return tamanho;
}
