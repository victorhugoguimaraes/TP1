#include "Texto.hpp"
#include <stdexcept>

using namespace std;

bool Texto::ehMaius(char c) const {
    return (c >= 'A' && c <= 'Z');
}

bool Texto::ehLetra(char c) const {
    return (c >= 'a' && c <= 'z') || ehMaius(c);
}

bool Texto::ehDigito(char c) const {
    return c >= '0' && c <= '9';
}

bool Texto::ehAlfanumerico(char c) const {
    return ehLetra(c) || ehDigito(c);
}

bool Texto::ehPontuacao(char c) const {
    std::string pontuacao = ",;.:?!";
    return pontuacao.find(c) != std::string::npos;
}

string Texto::getTexto() const{
    return texto;
}

bool Texto::validar(const string& texto) const{
    int tamanho = texto.length();

    if ((tamanho > 30)||(tamanho == 0)){
        return false;
    }

    if ((texto[tamanho-1]!='.')||(!ehMaius(texto[0]))) {
        return false;
    }

    for(int i = 0; i < tamanho; i++){
        if (ehPontuacao(texto[i])){
            if (ehPontuacao(texto[i+1])){
                return false;
            }
        }
        else if ((!ehAlfanumerico(texto[i]))&&(texto[i]!=' ')){
            return false;
        }
    }
    return true;
    }

bool Texto::setTexto(string texto){
    if (!validar(texto))
        return false;
    this->texto = texto;
    return true;
}
