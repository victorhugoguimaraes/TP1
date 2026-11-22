/**
 * @file SqliteUtil.hpp
 * @brief Declaração de funções utilitárias para extração de dados de consultas SQLite.
 */

#ifndef SQLITEUTIL_H
#define SQLITEUTIL_H

#include "../sqlite/sqlite3.h"
#include <string>

using namespace std;

/**
 * @brief Extrai o valor textual de uma coluna específica de uma instrução SQLite preparada.
 * @details Converte o ponteiro retornado por sqlite3_column_text para uma std::string,
 * retornando uma string vazia caso o valor armazenado na coluna seja nulo (NULL).
 * @param comando Ponteiro para a instrução preparada (sqlite3_stmt*) em execução.
 * @param coluna Índice inteiro (baseado em zero) da coluna a ser lida.
 * @return String contendo o texto da coluna ou string vazia se o campo for nulo.
 */
inline string obterTexto(sqlite3_stmt *comando, int coluna) {
    const unsigned char *valor = sqlite3_column_text(comando, coluna);
    string resultado;

    if (valor == nullptr)
        return resultado;

    while (*valor != '\0') {
        resultado += static_cast<char>(*valor);
        ++valor;
    }

    return resultado;
}

#endif
