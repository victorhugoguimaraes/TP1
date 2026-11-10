#ifndef CNTRLSERVICOAUTENTICACAO_H
#define CNTRLSERVICOAUTENTICACAO_H

#include "../interfaces/ServicoAutenticacao.hpp"
#include "ContainerPessoa.hpp"

/**
 * @class CntrlServicoAutenticacao
 * @brief Implementa a autenticacao de pessoas armazenadas no container.
 *
 * Consulta o cadastro pelo email e compara a senha cadastrada com a informada.
 * Nao realiza entrada ou saida de dados pelo terminal.
 */
class CntrlServicoAutenticacao : public ServicoAutenticacao {
    private: 
      /**
       * @brief Referencia ao container consultado durante a autenticacao.
       */
      const ContainerPessoas& container;
    public: 
      /**
       * @brief Associa o servico ao container de pessoas.
       * @param container Container que deve permanecer existente durante o uso do servico.
       */
      explicit CntrlServicoAutenticacao(const ContainerPessoas& container);
      /**
       * @brief Busca uma pessoa e verifica a correspondencia da senha.
       * @param email Email do cadastro a ser consultado.
       * @param senha Senha informada para comparacao.
       * @return true se a pessoa existir e a senha corresponder; false caso contrario.
       */
      bool autenticar(const Email& email, const Senha& senha) override;
  
};

#endif
