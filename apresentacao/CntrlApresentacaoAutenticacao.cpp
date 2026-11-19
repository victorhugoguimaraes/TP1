#include "CntrlApresentacaoAutenticacao.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

CntrlApresentacaoAutenticacao::CntrlApresentacaoAutenticacao(ServicoAutenticacao &servico, ServicoPessoa &pessoas)
    : servico(servico), pessoas(pessoas) {
}

bool CntrlApresentacaoAutenticacao::autenticar(Email &emailAutenticacao) {
    string entradaEmail;
    string entradaSenha;

    Email email;
    Senha senha;

    while (true) {
        cout << "Email: ";
        if (!getline(cin, entradaEmail))
            return false;
        try {
            email.setValor(entradaEmail);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << '\n';
        }
    }

    while (true) {
        cout << "Senha: ";
        if (!getline(cin, entradaSenha))
            return false;
        try {
            senha.setValor(entradaSenha);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << '\n';
        }
    }

    if (!servico.autenticar(email, senha)) {
        Pessoa pessoa;
        if (!pessoas.consultar(email, pessoa))
            cout << "Nao foi possivel entrar: email nao cadastrado.\n";
        else
            cout << "Nao foi possivel entrar: senha incorreta.\n";
        return false;
    }

    emailAutenticacao = email;
    cout << "Autenticação realizada com sucesso!\n";
    return true;
}
