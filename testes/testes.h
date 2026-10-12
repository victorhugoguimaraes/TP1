#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "../dominios/Email.hpp"
#include "../dominios/Estado.hpp"
#include "../dominios/Identificador.hpp"
#include "../dominios/Limite.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Papel.hpp"
#include "../dominios/Prioridade.hpp"
#include "../dominios/Senha.hpp"
#include "../dominios/Tamanho.hpp"
#include "../dominios/Texto.hpp"
#include "../dominios/Timestamp.hpp"
#include "../entidades/CartaoAtividade.hpp"
#include "../entidades/Pessoa.hpp"
#include "../entidades/Projeto.hpp"
#include "../entidades/Quadro.hpp"

class TUEmail {
private:
    Email* email;
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

class TUNome {
private:
    Nome* nome;
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

class TUSenha {
private:
    Senha* senha;
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

class TUTexto {
private:
    Texto* texto;
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

class TUTimestamp {
private:
    Timestamp* timestamp;
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

class TUIdentificador {
private:
    Identificador* identificador;
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

class TULimite {
private:
    Limite* limite;
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

class TUEstado {
private:
    Estado* estado;
    int resultado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
public:
    static const int SUCESSO = 0;
    static const int FALHA = -1;
    int run();
};

class TUPapel {
private:
    Papel* papel;
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

class TUPrioridade {
private:
    Prioridade* prioridade;
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

class TUTamanho {
private:
    Tamanho* tamanho;
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
    void testarCenarioFalha();
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
    void testarCenarioFalha();
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
    void testarCenarioFalha();
public:
    static const int SUCESSO = 0;
    static const int FALHA = -1;
    int run();
};

#endif
