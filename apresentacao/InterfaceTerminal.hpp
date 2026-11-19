#ifndef INTERFACE_TERMINAL_H
#define INTERFACE_TERMINAL_H

#include <string>

using namespace std;

class InterfaceTerminal {
public:
    void limpar();
    void cabecalho(const string& titulo, const string& subtitulo);
    void sucesso(const string& mensagem);
    void erro(const string& mensagem);
};

#endif
