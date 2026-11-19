#include "Timestamp.hpp"
#include "Utilitario.hpp"

#include <stdexcept>

using namespace std;

namespace {

bool todosDigitos(const string& texto, int inicio, int quantidade) {
    for (int i = inicio; i < inicio + quantidade; ++i) {
        if (!Utilitario::ehDigito(texto[i]))
            return false;
    }
    return true;
}

bool todasLetrasMaiusculas(const string& texto, int inicio, int quantidade) {
    for (int i = inicio; i < inicio + quantidade; ++i) {
        if (texto[i] < 'A' || texto[i] > 'Z')
            return false;
    }
    return true;
}

int numero(const string& texto, int inicio, int quantidade) {
    int resultado = 0;
    for (int i = inicio; i < inicio + quantidade; ++i)
        resultado = resultado * 10 + (texto[i] - '0');
    return resultado;
}

bool anoBissexto(int ano) {
    return ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0);
}

}

bool Timestamp::validar(const string& timestamp) const {
    const int tamanho = static_cast<int>(timestamp.size());
    if (tamanho != TAMANHO_TIMESTAMP_CURTO && tamanho != TAMANHO_TIMESTAMP_LONGO)
        return false;

    const int separadorMes = static_cast<int>(timestamp.find('-'));
    if (separadorMes == -1 ||
        (separadorMes != 1 && separadorMes != 2))
        return false;
    const int separadorAno = static_cast<int>(timestamp.find('-', separadorMes + 1));
    const int separadorHorario = static_cast<int>(timestamp.find('-', separadorAno + 1));
    if (separadorAno == -1 || separadorHorario == -1)
        return false;
    if (separadorAno != separadorMes + 4 || separadorHorario != separadorAno + 5)
        return false;
    if (timestamp[separadorHorario + 3] != ':')
        return false;

    const int inicioHorario = separadorHorario + 1;
    if (tamanho != inicioHorario + 5 ||
        !todosDigitos(timestamp, 0, separadorMes) ||
        !todasLetrasMaiusculas(timestamp, separadorMes + 1, 3) ||
        !todosDigitos(timestamp, separadorAno + 1, 4) ||
        !todosDigitos(timestamp, inicioHorario, 2) ||
        !todosDigitos(timestamp, inicioHorario + 3, 2))
        return false;

    static const char* const meses[] = {
        "JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
        "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"
    };
    const string mes = timestamp.substr(separadorMes + 1, 3);
    int numeroMes = 0;
    while (numeroMes < QUANTIDADE_MESES && mes != meses[numeroMes])
        ++numeroMes;
    if (numeroMes == QUANTIDADE_MESES)
        return false;

    const int dia = numero(timestamp, 0, separadorMes);
    const int ano = numero(timestamp, separadorAno + 1, 4);
    const int hora = numero(timestamp, inicioHorario, 2);
    const int minuto = numero(timestamp, inicioHorario + 3, 2);
    int diasFevereiro = 28;

    if (anoBissexto(ano))
        diasFevereiro = 29;

    const int diasPorMes[] = {
        31, diasFevereiro, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };
    return ano >= ANO_MINIMO && ano <= ANO_MAXIMO &&
           dia >= 1 && dia <= diasPorMes[numeroMes] &&
           hora >= 0 && hora <= 23 && minuto >= 0 && minuto <= 59;
}

void Timestamp::setTimestamp(const string& timestamp) {
    if (timestamp.size() != TAMANHO_TIMESTAMP_CURTO && timestamp.size() != TAMANHO_TIMESTAMP_LONGO)
        throw invalid_argument("Timestamp invalido: use o formato DD-MES-AAAA-HH:MM");
    if (!validar(timestamp))
        throw invalid_argument("Timestamp invalido: verifique dia, mes, ano entre 2000 e 2099 e horario");
    valor = timestamp;
}

const string& Timestamp::getTimestamp() const {
    return valor;
}

void Timestamp::setValor(const string& timestamp) {
    setTimestamp(timestamp);
}

const string& Timestamp::getValor() const {
    return getTimestamp();
}
