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

class TUServicos {
private:
    BancoDados* banco;
    ContainerPessoas* pessoas;
    ContainerProjetos* projetos;
    ContainerQuadros* quadros;
    ContainerCartoes* cartoes;
    Pessoa* gestor;
    Pessoa* desenvolvedor;
    CntrlServicoProjeto* servicoProjetoGestor;
    CntrlServicoProjeto* servicoProjetoDesenvolvedor;
    CntrlServicoQuadro* servicoQuadroGestor;
    CntrlServicoQuadro* servicoQuadroDesenvolvedor;
    CntrlServicoCartao* servicoCartaoGestor;
    CntrlServicoCartao* servicoCartaoDesenvolvedor;
    CntrlServicoRelatorio* servicoRelatorioGestor;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    Pessoa criarPessoa(const string& email, Papel::Cargo cargo);
    Projeto criarProjeto();
    Quadro criarQuadro();
    CartaoAtividade criarCartao(const string& identificador);

public:
    static const int SUCESSO = 0;
    static const int FALHA = -1;
    int run();
};

#endif
