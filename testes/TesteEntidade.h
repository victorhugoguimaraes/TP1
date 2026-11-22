/**
 * @file TesteEntidade.h
 * @brief Declaração das classes de teste unitário para as entidades do sistema.
 * @details Todas as classes deste arquivo seguem a mesma convenção de execução:
 * - `SUCESSO` (0): todos os cenários de teste da entidade foram aprovados.
 * - `FALHA` (-1): ocorreu erro em ao menos um cenário de teste.
 * - `run()`: executa a sequência `setUp()`, os cenários de teste da entidade e `tearDown()`.
 */

#ifndef TESTE_ENTIDADE_H
#define TESTE_ENTIDADE_H

#include "../entidades/CartaoAtividade.hpp"
#include "../entidades/Pessoa.hpp"
#include "../entidades/Projeto.hpp"
#include "../entidades/Quadro.hpp"

/**
 * @class TUPessoa
 * @brief Teste unitário para validação dos cenários de uso da entidade Pessoa.
 */
class TUPessoa {
  private:
    Pessoa *pessoa;
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

/**
 * @class TUProjeto
 * @brief Teste unitário para validação dos cenários de uso da entidade Projeto.
 */
class TUProjeto {
  private:
    Projeto *projeto;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();

  public:
    static const int SUCESSO = 0;
    static const int FALHA = -1;
    int run();
};

/**
 * @class TUQuadro
 * @brief Teste unitário para validação dos cenários de uso da entidade Quadro.
 */
class TUQuadro {
  private:
    Quadro *quadro;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();

  public:
    static const int SUCESSO = 0;
    static const int FALHA = -1;
    int run();
};

/**
 * @class TUCartaoAtividade
 * @brief Teste unitário para validação dos cenários de uso da entidade CartaoAtividade.
 */
class TUCartaoAtividade {
  private:
    CartaoAtividade *cartao;
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
