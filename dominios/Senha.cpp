#include "Senha.hpp"

string Senha::getValor() const{
    return valor;}

bool Senha::validar(const string& senha) const{
    return (senha.length() == LIMITE);
}

bool Senha::setValor(string valor){
    if (!validar(senha))
        return false;
    this->valor = valor;
    return true;
}
