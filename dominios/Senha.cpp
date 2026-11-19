#include "Senha.hpp"
#include "Utilitario.hpp"
#include <stdexcept>

using namespace std;

string Senha::getValor() const {
    return senha;
}

bool Senha::validar(const string &senha) const {
    int tamanho = senha.length();
    int digito = 0;
    int letra = 0;

    if (tamanho != TAMANHO_SENHA) {
        return false;
    }

    for (int i = 0; i < TAMANHO_SENHA; i++) {
        if (Utilitario::ehLetra(senha[i])) {
            letra = letra + 1;
        } else if (Utilitario::ehDigito(senha[i])) {
            digito = digito + 1;
        } else {
            return false;
        }
    }

    if ((letra == 0) || (digito == 0)) {
        return false;
    }
    return true;
}

bool Senha::setValor(string senha) {
    if (senha.length() != TAMANHO_SENHA)
        throw invalid_argument("Senha invalida: deve ter exatamente 5 caracteres");
    int letras = 0;
    int digitos = 0;
    for (char caractere : senha) {
        if (Utilitario::ehLetra(caractere))
            ++letras;
        else if (Utilitario::ehDigito(caractere))
            ++digitos;
        else
            throw invalid_argument("Senha invalida: use somente letras e numeros");
    }
    if (letras == 0)
        throw invalid_argument("Senha invalida: deve conter pelo menos uma letra");
    if (digitos == 0)
        throw invalid_argument("Senha invalida: deve conter pelo menos um numero");
    this->senha = senha;
    return true;
}
