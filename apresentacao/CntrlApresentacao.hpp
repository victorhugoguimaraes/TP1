#ifndef CNTRLAPRESENTACAO_H
#define CNTRLAPRESENTACAO_H

#include "../interfaces/ServicoCartao.hpp"
#include "../interfaces/ServicoPessoa.hpp"
#include "../interfaces/ServicoProjeto.hpp"
#include "../interfaces/ServicoQuadro.hpp"
#include "../interfaces/ServicoRelatorio.hpp"
#include "CntrlApresentacaoAutenticacao.hpp"
#include "InterfaceTerminal.hpp"

class CntrlApresentacao {
  private:
    ServicoPessoa &pessoas;
    ServicoProjeto &projetos;
    ServicoQuadro &quadros;
    ServicoCartao &cartoes;
    ServicoRelatorio &relatorios;
    CntrlApresentacaoAutenticacao &autenticacao;
    Pessoa &usuario;
    InterfaceTerminal interfaceTerminal;

    bool lerTexto(const string &mensagem, string &valor);
    bool lerInteiro(const string &mensagem, int &valor);
    bool autenticar(Pessoa &usuario);
    bool cadastrarPessoaInicial();
    void menuPessoa();
    void menuProjeto(const Pessoa &usuario);
    void menuQuadro(const Pessoa &usuario);
    void menuCartao(const Pessoa &usuario);
    void menuRelatorio(const Pessoa &usuario);
    bool lerPessoa(Pessoa &pessoa, bool incluirEmail);
    bool lerProjeto(Projeto &projeto);
    bool lerQuadro(Quadro &quadro);
    bool lerCartao(CartaoAtividade &cartao);
    void listarPessoas();
    void listarProjetos(ServicoProjeto &servico);
    void listarQuadros(ServicoQuadro &servico);
    void listarCartoes(ServicoCartao &servico);

  public:
    CntrlApresentacao(ServicoPessoa &pessoas, ServicoProjeto &projetos, ServicoQuadro &quadros, ServicoCartao &cartoes,
                      ServicoRelatorio &relatorios, CntrlApresentacaoAutenticacao &autenticacao, Pessoa &usuario);
    void executar();
};

#endif
