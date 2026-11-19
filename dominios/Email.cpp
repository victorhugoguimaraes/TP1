#include "Email.hpp"
#include "Utilitario.hpp"
#include <stdexcept>
using namespace std;

bool Email::validarLocal(const string& email, int inicio, int fim) const {
    int tamanho = fim - inicio;
    if (tamanho == 0 || tamanho > TAMANHO_MAXIMO_LOCAL)
        return false;
    if (Utilitario::ehEspecial(email[inicio]) || Utilitario::ehEspecial(email[fim - 1]))
        return false;
    for (int i = inicio; i < fim; i++) {
        if ((!Utilitario::ehLetraMinuscula(email[i]) && !Utilitario::ehDigito(email[i])) && !Utilitario::ehEspecial(email[i]))
            return false;
        if (Utilitario::ehEspecial(email[i]) && i + 1 < fim) {
            if (!Utilitario::ehLetraMinuscula(email[i + 1]) && !Utilitario::ehDigito(email[i + 1]))
                return false;
        }
    }
    return true;
}

bool Email::validarDominio(const string& email, int inicio, int fim) const {
    int tamanho = fim - inicio;
    if (tamanho == 0 || tamanho > TAMANHO_MAXIMO_DOMINIO)
        return false;
    int inicioParte = inicio;
    for (int i = inicio; i <= fim; i++) {
        if (i == fim || email[i] == '.') {
            int tamanhoParte = i - inicioParte;
            if (tamanhoParte == 0)
                return false;
            if (email[inicioParte] == '-' || email[i - 1] == '-')
                return false;
            for (int j = inicioParte; j < i; j++) {
            if (!Utilitario::ehLetraMinuscula(email[j]) && !Utilitario::ehDigito(email[j]) && email[j] != '-')
                    return false;
            }
            inicioParte = i + 1;
        }
    }
    return true;
}

bool Email::validar(const string& email) const {
    int tamanho = email.length();
    int posArroba = -1;
    for (int i = 0; i < tamanho; i++) {
        if (email[i] == '@') {
            if (posArroba != -1)
                return false;
            posArroba = i;
        }
    }
    if (posArroba <= 0 || posArroba == tamanho - 1)
        return false;
    if (!validarLocal(email, 0, posArroba))
        return false;
    if (!validarDominio(email, posArroba + 1, tamanho))
        return false;
    return true;
}

void Email::setValor(string valor) {
    size_t posicaoArroba = valor.find('@');
    if (posicaoArroba == string::npos || posicaoArroba != valor.rfind('@'))
        throw invalid_argument("Email invalido: deve possuir um unico @");
    int arroba = static_cast<int>(posicaoArroba);
    if (arroba == 0 || arroba == static_cast<int>(valor.length()) - 1)
        throw invalid_argument("Email invalido: informe a parte antes e depois do @");
    if (!validarLocal(valor, 0, arroba))
        throw invalid_argument("Email invalido: a parte antes do @ deve usar letras minusculas, numeros e . ou -");
    if (!validarDominio(valor, arroba + 1, valor.length()))
        throw invalid_argument("Email invalido: dominio invalido; use letras minusculas, numeros, pontos e hifens");
    this->valor = valor;
}

string Email::getValor() const {
    return valor;
}
