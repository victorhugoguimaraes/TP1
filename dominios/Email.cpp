#include "Email.hpp"

string Email::getValor() const{
    return valor;}

bool Email::validar(const string& email) const{
    return true;
}

void Email::setValor(string novoValor){
    valor = novoValor;
}
