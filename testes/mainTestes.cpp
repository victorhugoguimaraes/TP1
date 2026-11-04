#include "TesteDominios.h"
#include "TesteEntidade.h"

#include <iostream>
#include <string>

void imprimirResultado(const std::string& nome, int estado) {
    std::cout << (estado == 0 ? "[OK] " : "[X]  ") << nome << std::endl;
}

int main() {
    imprimirResultado("Email", TUEmail().run());
    imprimirResultado("Nome", TUNome().run());
    imprimirResultado("Senha", TUSenha().run());
    imprimirResultado("Texto", TUTexto().run());
    imprimirResultado("Timestamp", TUTimestamp().run());
    imprimirResultado("Identificador", TUIdentificador().run());
    imprimirResultado("Limite", TULimite().run());
    imprimirResultado("Estado", TUEstado().run());
    imprimirResultado("Papel", TUPapel().run());
    imprimirResultado("Prioridade", TUPrioridade().run());
    imprimirResultado("Tamanho", TUTamanho().run());
    imprimirResultado("Pessoa", TUPessoa().run());
    imprimirResultado("Projeto", TUProjeto().run());
    imprimirResultado("Quadro", TUQuadro().run());
    imprimirResultado("CartaoAtividade", TUCartaoAtividade().run());
    return 0;
}
