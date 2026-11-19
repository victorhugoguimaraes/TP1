#include "TesteDominios.h"
#include "TesteEntidade.h"
#include "TesteServicos.h"

#include <iostream>
#include <string>
using namespace std;

void imprimirResultado(const string &nome, int estado) {
    if (estado == 0)
        cout << "[OK] " << nome << endl;
    else
        cout << "[X]  " << nome << endl;
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
    imprimirResultado("Servicos", TUServicos().run());
    return 0;
}
