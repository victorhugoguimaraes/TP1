#include "Senha.hpp"
#include <stdexcept>

using namespace std;

bool Senha::ehLetra(char c) const {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');;
}
bool Senha::ehDigito(char c) const {
    return c >= '0' && c <= '9';
}

string Senha::getValor() const{
    return senha;
}

bool Senha::validar(const string& senha) const{
    int tamanho = senha.length();
    int digito = 0;
    int letra = 0;

    if (tamanho != 5){
        return false;
    }

    for(int i = 0; i < 5; i++){
        if(ehLetra(senha[i])){
            letra = letra + 1;
        }
        else if (ehDigito(senha[i])){
            digito = digito + 1;
        }
        else {
            return false;
        }
    }

    if ((letra==0)||(digito==0)){
        return false;
    }
    return true;
}

bool Senha::setValor(string senha){
    if (!validar(senha))
        return false;
    this->senha = senha;
    return true;
}
