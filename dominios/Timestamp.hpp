#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

#include <string>
using namespace std;

/**
 * @class Timestamp
 * @brief Representa e valida um carimbo de data e hora com formato textual específico.
 *
 * Esta classe encapsula um registro de data e hora, aplicando regras rígidas de validação
 * no calendário (incluindo cálculo de ano bissexto) para garantir que apenas
 * carimbos válidos e bem formatados sejam gravados.
 */
class Timestamp {
private:
    /**
     * @brief Armazena a string do carimbo de data e hora validado.
     */
    string valor;

    /**
     * @brief Realiza a validação estrutural e cronológica da string do timestamp.
     *
     * Formatos aceitos: "D-MMM-AAAA-HH:MM" (16 caracteres) ou "DD-MMM-AAAA-HH:MM" (17 caracteres).
     *
     * Critérios detalhados de validação:
     * - O mês deve ser uma abreviação de 3 letras maiúsculas em português (ex: "JAN", "FEV").
     * - O ano deve possuir 4 dígitos e estar obrigatoriamente entre os anos 2000 e 2099.
     * - O dia deve ser válido para o respectivo mês, com um ou dois digitos, validando anos bissextos para fevereiro (29 dias).
     * - As horas devem variar de 00 a 23 e os minutos de 00 a 59.
     *
     * @param timestamp A string completa a ser submetida aos testes.
     * @return true se a string respeitar rigorosamente todas as regras cronológicas, false caso contrário.
     */
    bool validar(const string& timestamp) const;

public:
    /**
     * @brief Valida e define o carimbo de data e hora.
     *
     * Interface de mutação primária. Caso a string fornecida falte com qualquer um dos
     * critérios cronológicos ou estruturais, a alteração é abortada e uma exceção é lançada.
     *
     * @param timestamp A string do carimbo proposto.
     * @throws std::invalid_argument Se a string falhar nos critérios de validação ("Timestamp invalido").
     */
    void setTimestamp(const string& timestamp);

    /**
     * @brief Recupera o carimbo de data e hora atualmente armazenado.
     * @return Uma referência constante para a string do timestamp.
     */
    const string& getTimestamp() const;

    /**
     * @brief Método alternativo (alias) para definir o valor do timestamp.
     * @param timestamp A string do carimbo proposto.
     * @throws std::invalid_argument Se a string falhar nos critérios de validação ("Timestamp invalido").
     */
    void setValor(const string& timestamp);

    /**
     * @brief Método alternativo (alias) para recuperar o valor do timestamp.
     * @return Uma referência constante para a string do timestamp.
     */
    const string& getValor() const;
};

#endif
