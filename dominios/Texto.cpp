#include "Texto.hpp"
#include "Utilitario.hpp"
#include <stdexcept>

using namespace std;

string Texto::getTexto() const {
    return texto;
}

bool Texto::validar(const string &texto) const {
    int tamanho = texto.length();

    if ((tamanho > TAMANHO_MAXIMO_TEXTO) || (tamanho == 0)) {
        return false;
    }

    if ((texto[tamanho - 1] != '.') || (!Utilitario::ehMaiuscula(texto[0]))) {
        return false;
    }

    for (int i = 0; i < tamanho; i++) {
        if (Utilitario::ehPontuacao(texto[i])) {
            if (i + 1 < tamanho && Utilitario::ehPontuacao(texto[i + 1])) {
                return false;
            }
        } else if ((!Utilitario::ehAlfanumerico(texto[i])) && (texto[i] != ' ')) {
            return false;
        }
    }
    return true;
}

bool Texto::setTexto(string texto) {
    if (texto.empty())
        throw invalid_argument("Texto invalido: nao pode ser vazio");
    if (texto.length() > TAMANHO_MAXIMO_TEXTO)
        throw invalid_argument("Texto invalido: limite maximo de 30 caracteres");
    if (!Utilitario::ehMaiuscula(texto[0]))
        throw invalid_argument("Texto invalido: deve comecar com letra maiuscula");
    if (texto[texto.length() - 1] != '.')
        throw invalid_argument("Texto invalido: deve terminar com ponto");
    for (int i = 0; i < static_cast<int>(texto.length()); ++i) {
        if (Utilitario::ehPontuacao(texto[i]) && i + 1 < static_cast<int>(texto.length()) &&
            Utilitario::ehPontuacao(texto[i + 1]))
            throw invalid_argument("Texto invalido: nao use sinais de pontuacao consecutivos");
        if (!Utilitario::ehAlfanumerico(texto[i]) && texto[i] != ' ' && !Utilitario::ehPontuacao(texto[i]))
            throw invalid_argument("Texto invalido: use letras, numeros, espacos e pontuacao");
    }
    this->texto = texto;
    return true;
}
