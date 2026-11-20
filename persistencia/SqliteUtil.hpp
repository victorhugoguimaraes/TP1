#ifndef SQLITEUTIL_H
#define SQLITEUTIL_H

#include "../sqlite/sqlite3.h"
#include <string>

using namespace std;

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
