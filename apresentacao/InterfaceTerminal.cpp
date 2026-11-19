#include "InterfaceTerminal.hpp"

#include <iostream>

using namespace std;

void InterfaceTerminal::limpar() {
    cout << "\033[2J\033[H";
}

void InterfaceTerminal::cabecalho(const string &titulo, const string &subtitulo) {
    cout << "\033[1;36m";
    cout << "+------------------------------------------------------------+\n";
    cout << "| " << titulo;
    for (int i = static_cast<int>(titulo.length()); i < 58; ++i)
        cout << ' ';
    cout << " |\n";
    cout << "+------------------------------------------------------------+\n";
    cout << "\033[0m";
    if (!subtitulo.empty())
        cout << "\033[1;33m" << subtitulo << "\033[0m\n";
}

void InterfaceTerminal::sucesso(const string &mensagem) {
    cout << "\033[1;32m[OK] " << mensagem << "\033[0m\n";
}

void InterfaceTerminal::erro(const string &mensagem) {
    cout << "\033[1;31m[ERRO] " << mensagem << "\033[0m\n";
}
