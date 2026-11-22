/**
 * @file TesteServicos.h
 * @brief Declaração da classe de teste de integração para a camada de serviços e persistência.
 */

#ifndef TESTE_SERVICOS_H
#define TESTE_SERVICOS_H

#include "../persistencia/BancoDados.hpp"
#include "../servico/CntrlServicoCartao.hpp"
#include "../servico/CntrlServicoProjeto.hpp"
#include "../servico/CntrlServicoQuadro.hpp"
#include "../servico/CntrlServicoRelatorio.hpp"
#include "../servico/ContainerCartao.hpp"
#include "../servico/ContainerPessoa.hpp"
#include "../servico/ContainerProjeto.hpp"
#include "../servico/ContainerQuadro.hpp"

/**
 * @class TUServicos
 * @brief Teste de integração para validação das regras de negócio e persistência das controladoras de serviço.
 * @details Inicializa um banco de dados e os containers associados para verificar cenários de sucesso
 * e falha (como permissões entre gestor e desenvolvedor) nas operações de Projeto, Quadro, CartaoAtividade
 * e geração de relatórios.
 */
class TUServicos {
  private:
    BancoDados *banco;
    ContainerPessoas *pessoas;
    ContainerProjetos *projetos;
    ContainerQuadros *quadros;
    ContainerCartoes *cartoes;
    Pessoa *gestor;
    Pessoa *desenvolvedor;
    CntrlServicoProjeto *servicoProjetoGestor;
    CntrlServicoProjeto *servicoProjetoDesenvolvedor;
    CntrlServicoQuadro *servicoQuadroGestor;
    CntrlServicoQuadro *servicoQuadroDesenvolvedor;
    CntrlServicoCartao *servicoCartaoGestor;
    CntrlServicoCartao *servicoCartaoDesenvolvedor;
    CntrlServicoRelatorio *servicoRelatorioGestor;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    Pessoa criarPessoa(const string &email, Papel::Cargo cargo);
    Projeto criarProjeto();
    Quadro criarQuadro();
    CartaoAtividade criarCartao(const string &identificador);

  public:
    static const int SUCESSO = 0; ///< Código de retorno indicando que todos os cenários passaram.
    static const int FALHA = -1;  ///< Código de retorno indicando falha em algum cenário de teste.

    /**
     * @brief Executa os cenários de teste das controladoras de serviço.
     * @return SUCESSO (0) se os testes passarem; FALHA (-1) caso contrário.
     */
    int run();
};

#endif
