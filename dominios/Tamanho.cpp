#include "Tamanho.hpp"
#include <stdexcept>

void Tamanho::setTamanho(Nivel tamanho){
    if (tamanho != GRANDE && tamanho != MEDIO && tamanho != PEQUENO)
        throw std::invalid_argument("Tamanho invalido");
    this->tamanho = tamanho;
}

Tamanho::Nivel Tamanho::getTamanho() const{
    return tamanho;
}
