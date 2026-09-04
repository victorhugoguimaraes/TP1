#include "Email.hpp"
#include <stdexcept>
using namespace std;

bool Email::ehLetra(char c) const {
    return c >= 'a' && c <= 'z';
}
bool Email::ehDigito(char c) const {
    return c >= '0' && c <= '9';
}
bool Email::ehAlfanumerico(char c) const {
    return ehLetra(c) || ehDigito(c);
}
bool Email::ehEspecial(char c) const {
    return c == '.' || c == '-';
}

bool Email::validarLocal(const char email[], int inicio, int fim) const {
    int tamanho = fim - inicio;
    if (tamanho == 0 || tamanho > 64)
        return false;
    if (ehEspecial(email[inicio]) || ehEspecial(email[fim - 1]))
        return false;
    for (int i = inicio; i < fim; i++) {
        if (!ehAlfanumerico(email[i]) && !ehEspecial(email[i]))
            return false;
        if (ehEspecial(email[i]) && i + 1 < fim) {
            if (!ehAlfanumerico(email[i + 1]))
                return false;
        }
    }
    return true;
}

bool Email::validarDominio(const char email[], int inicio, int fim) const {
    int tamanho = fim - inicio;
    if (tamanho == 0 || tamanho > 255)
        return false;
    int inicioParte = inicio;
    for (int i = inicio; i <= fim; i++) {
        if (email[i] == '.' || i == fim) {
            int tamanhoParte = i - inicioParte;
            if (tamanhoParte == 0)
                return false;
            if (email[inicioParte] == '-' || email[i - 1] == '-')
                return false;
            for (int j = inicioParte; j < i; j++) {
                if (!ehAlfanumerico(email[j]) && email[j] != '-')
                    return false;
            }
            inicioParte = i + 1;
        }
    }
    return true;
}

bool Email::validar(const char email[]) const {
    int tamanho = 0;
    int posArroba = -1;
    while (email[tamanho] != '\0') {
        if (email[tamanho] == '@') {
            if (posArroba != -1)
                return false;
            posArroba = tamanho;
        }
        tamanho++;
    }
    if (posArroba <= 0 || posArroba == tamanho - 1)
        return false;
    if (!validarLocal(email, 0, posArroba))
        return false;
    if (!validarDominio(email, posArroba + 1, tamanho))
        return false;
    return true;
}

void Email::setValor(const char novoValor[]) {
    if (!validar(novoValor)) {
        throw invalid_argument("Email invalido");
    }
    int i = 0;
    while (novoValor[i] != '\0') {
        valor[i] = novoValor[i];
        i++;
    }
    valor[i] = '\0';
}

const char* Email::getValor() const {
    return valor;
}
