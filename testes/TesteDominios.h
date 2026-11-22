/**
 * @file TesteDominios.h
 * @brief Declaração das classes de teste unitário para os domínios do sistema.
 * @details Todas as classes deste arquivo seguem a mesma convenção de execução:
 * - `SUCESSO` (0): todos os cenários de validação foram aprovados.
 * - `FALHA` (-1): ocorreu erro em ao menos um cenário de teste.
 * - `run()`: executa a sequência `setUp()`, `testarCenarioSucesso()`, `testarCenarioFalha()` e `tearDown()`.
 */

#ifndef TESTE_DOMINIOS_H
#define TESTE_DOMINIOS_H

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

/**
 * @class TUEmail
 * @brief Teste unitário para validação dos cenários de sucesso e falha da classe Email.
 */
class TUEmail {
  private:
    Email *email;
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
 * @class TUNome
 * @brief Teste unitário para validação dos cenários de sucesso e falha da classe Nome.
 */
class TUNome {
  private:
    Nome *nome;
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
 * @class TUSenha
 * @brief Teste unitário para validação dos cenários de sucesso e falha da classe Senha.
 */
class TUSenha {
  private:
    Senha *senha;
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
 * @class TUTexto
 * @brief Teste unitário para validação dos cenários de sucesso e falha da classe Texto.
 */
class TUTexto {
  private:
    Texto *texto;
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
 * @class TUTimestamp
 * @brief Teste unitário para validação dos cenários de sucesso e falha da classe Timestamp.
 */
class TUTimestamp {
  private:
    Timestamp *timestamp;
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
 * @class TUIdentificador
 * @brief Teste unitário para validação dos cenários de sucesso e falha da classe Identificador.
 */
class TUIdentificador {
  private:
    Identificador *identificador;
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
 * @class TULimite
 * @brief Teste unitário para validação dos cenários de sucesso e falha da classe Limite.
 */
class TULimite {
  private:
    Limite *limite;
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
 * @class TUEstado
 * @brief Teste unitário para validação dos cenários de sucesso e falha da classe Estado.
 */
class TUEstado {
  private:
    Estado *estado;
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

/**
 * @class TUPapel
 * @brief Teste unitário para validação dos cenários de sucesso e falha da classe Papel.
 */
class TUPapel {
  private:
    Papel *papel;
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
 * @class TUPrioridade
 * @brief Teste unitário para validação dos cenários de sucesso e falha da classe Prioridade.
 */
class TUPrioridade {
  private:
    Prioridade *prioridade;
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
 * @class TUTamanho
 * @brief Teste unitário para validação dos cenários de sucesso e falha da classe Tamanho.
 */
class TUTamanho {
  private:
    Tamanho *tamanho;
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
