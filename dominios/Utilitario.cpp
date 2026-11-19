#include "Utilitario.hpp"

bool Utilitario::ehLetra(char caractere) {
    return (caractere >= 'a' && caractere <= 'z') || (caractere >= 'A' && caractere <= 'Z');
}

bool Utilitario::ehLetraMinuscula(char caractere) {
    return caractere >= 'a' && caractere <= 'z';
}

bool Utilitario::ehDigito(char caractere) {
    return caractere >= '0' && caractere <= '9';
}

bool Utilitario::ehAlfanumerico(char caractere) {
    return ehLetra(caractere) || ehDigito(caractere);
}

bool Utilitario::ehMaiuscula(char caractere) {
    return caractere >= 'A' && caractere <= 'Z';
}

bool Utilitario::ehEspecial(char caractere) {
    return caractere == '.' || caractere == '-';
}

bool Utilitario::ehPontuacao(char caractere) {
    string pontuacao = ",;.:?!";
    return pontuacao.find(caractere) != string::npos;
}
