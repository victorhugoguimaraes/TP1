#ifndef TESTE_ENTIDADE_H_INCLUDED
#define TESTE_ENTIDADE_H_INCLUDED

#include "../entidades/CartaoAtividade.hpp"
#include "../entidades/Pessoa.hpp"
#include "../entidades/Projeto.hpp"
#include "../entidades/Quadro.hpp"

class TUPessoa {
private:
    Pessoa* pessoa;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
public:
    static const int SUCESSO = 0;
    static const int FALHA = -1;
    int run();
};

class TUProjeto {
private:
    Projeto* projeto;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
public:
    static const int SUCESSO = 0;
    static const int FALHA = -1;
    int run();
};

class TUQuadro {
private:
    Quadro* quadro;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
public:
    static const int SUCESSO = 0;
    static const int FALHA = -1;
    int run();
};

class TUCartaoAtividade {
private:
    CartaoAtividade* cartao;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
public:
    static const int SUCESSO = 0;
    static const int FALHA = -1;
    int run();
};

#endif
