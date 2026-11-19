#include "Nome.hpp"
#include "Utilitario.hpp"
#include <stdexcept>

using namespace std;

string Nome::getNome() const{
    return nome;
}

bool Nome::validar(const string& nome) const{
    int tamanho = nome.length();

    if ((tamanho > TAMANHO_MAXIMO_NOME)||(tamanho == 0)){
        return false;
    }

    if ((nome[0]==' ')||(nome[tamanho-1]==' ')) {
        return false;
    }

    for(int i = 0; i < tamanho; i++){
        if (nome[i]==' '){
            if (i + 1 >= tamanho || !Utilitario::ehLetra(nome[i+1])){
                return false;
            }
        }
        else if (!Utilitario::ehLetra(nome[i])){
            return false;
            }
        }
    return true;
    }

bool Nome::setNome(string nome){
    if (nome.empty())
        throw invalid_argument("Nome invalido: nao pode ser vazio");
    if (nome.length() > TAMANHO_MAXIMO_NOME)
        throw invalid_argument("Nome invalido: limite maximo de 15 caracteres");
    if (nome[0] == ' ' || nome[nome.length() - 1] == ' ')
        throw invalid_argument("Nome invalido: nao pode comecar ou terminar com espaco");
    for (int i = 0; i < static_cast<int>(nome.length()); ++i) {
        if (nome[i] == ' ' && (i + 1 >= static_cast<int>(nome.length()) || nome[i + 1] == ' '))
            throw invalid_argument("Nome invalido: nao use espacos consecutivos");
        if (nome[i] != ' ' && !Utilitario::ehLetra(nome[i]))
            throw invalid_argument("Nome invalido: use somente letras e espacos");
    }
    this->nome = nome;
    return true;
}
