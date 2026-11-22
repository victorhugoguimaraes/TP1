/**
 * @file BancoDados.hpp
 * @brief Declaração da classe de gerenciamento da conexão com o banco de dados SQLite.
 */

#ifndef BANCODADOS_H
#define BANCODADOS_H

#include "../sqlite/sqlite3.h"
#include <string>

using namespace std;

/**
 * @class BancoDados
 * @brief Encapsula a abertura, execução de comandos e fechamento de um banco SQLite.
 * @details Gerencia o ciclo de vida da conexão com o arquivo de banco de dados
 * utilizando RAII, abrindo a conexão no construtor e encerrando-a no destrutor.
 */
class BancoDados {
  private:
    sqlite3 *banco;

  public:
    /**
     * @brief Constrói o gerenciador e abre a conexão com o banco de dados SQLite.
     * @param caminho Caminho do arquivo do banco de dados no sistema de arquivos.
     */
    explicit BancoDados(const string &caminho);

    /**
     * @brief Destrói o objeto e fecha a conexão ativa com o banco de dados.
     */
    ~BancoDados();

    /**
     * @brief Obtém o ponteiro bruto para a instância aberta do banco SQLite.
     * @return Ponteiro sqlite3* correspondente à conexão ativa.
     */
    sqlite3 *obterBanco() const;

    /**
     * @brief Executa uma instrução SQL diretamente no banco de dados.
     * @param sql String contendo o comando SQL a ser executado.
     */
    void executar(const string &sql) const;
};

#endif
