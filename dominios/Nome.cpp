#include "Nome.hpp"
#include <stdexcept>

using namespace std;

bool Nome::ehLetra(char c) const {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');;
}

string Nome::getNome() const{
    return nome;
}

bool Nome::validar(const string& nome) const{
    int tamanho = nome.length();

    if ((tamanho > 15)||(tamanho == 0)){
        return false;
    }

    if ((nome[0]==' ')||(nome[tamanho-1]==' ')) {
        return false;
    }

    for(int i = 0; i < tamanho; i++){
        if (nome[i]==' '){
            if (!ehLetra(nome[i+1])){
                return false;
            }
        }
        else if (!ehLetra(nome[i])){
            return false;
            }
        }
    return true;
    }

bool Nome::setNome(string nome){
    if (!validar(nome))
        return false;
    this->nome = nome;
    return true;
}
