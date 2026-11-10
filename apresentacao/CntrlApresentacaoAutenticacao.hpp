#ifndef CNTRLAPRESENTACAOAUTENTICACAO_H
#define CNTRLAPRESENTACAOAUTENTICACAO_H

#include "../interfaces/ServicoAutenticacao.hpp"

/**
 * @class CntrlApresentacaoAutenticacao
 * @brief Controla a interacao pelo terminal para autenticar uma pessoa.
 *
 * Solicita email e senha, valida seus formatos usando os dominios e delega
 * a verificacao das credenciais ao servico de autenticacao.
 */
class CntrlApresentacaoAutenticacao{
    private:
      /**
       * @brief Referencia ao servico responsavel por verificar as credenciais.
       */
      ServicoAutenticacao& servico;

   public:
      /**
       * @brief Associa a apresentacao ao servico de autenticacao.
       * @param servico Servico que deve permanecer existente durante o uso da apresentacao.
       */
      explicit CntrlApresentacaoAutenticacao(
      ServicoAutenticacao&  servico
      );

      /**
       * @brief Solicita e valida as credenciais pelo terminal.
       * @param emailAutenticacao Recebe o email em caso de sucesso; permanece inalterado em caso de falha.
       * @return true se autenticada; false para formato invalido, credenciais incorretas ou falha de leitura.
       * @details Exibe o resultado no terminal e trata excecoes de formato dos dominios.
       */
      bool autenticar(Email& emailAutenticacao);
  };

#endif
