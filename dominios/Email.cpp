#include "Email.hpp"

bool ehLetra(char c) {
    return c >= 'a' && c <= 'z';
}

bool ehDigito(char c) {
    return c >= '0' && c <= '9';
}

bool ehAlfanumerico(char c) {
    return ehLetra(c) || ehDigito(c);
}

bool ehEspecial(char c) {
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

    // Cada parte do domínio deve ser válida
    int inicioParte = inicio;

    for (int i = inicio; i <= fim; i++) {

        // Encontrou um ponto ou chegou ao final
        if (email[i] == '.' || i == fim) {

            int tamanhoParte = i - inicioParte;

            // Parte vazia
            if (tamanhoParte == 0)
                return false;

            // Parte começa ou termina com caractere inválido
            if (email[inicioParte] == '-' ||
                email[i - 1] == '-')
                return false;

            // Verifica os caracteres da parte
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

    // Descobre tamanho e posição do @
    while (email[tamanho] != '\0') {

        if (email[tamanho] == '@') {
            if (posArroba != -1)
                return false;

            posArroba = tamanho;
        }

        tamanho++;
    }

    // Não existe @, ou @ está no início/fim
    if (posArroba <= 0 || posArroba == tamanho - 1)
        return false;

    if (!validarLocal(email, 0, posArroba))
        return false;

    if (!validarDominio(email, posArroba + 1, tamanho))
        return false;

    return true;
}
