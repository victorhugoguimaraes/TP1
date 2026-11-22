/**
 * @file Schema.hpp
 * @brief Declaração da função de inicialização da estrutura (schema) do banco de dados.
 */

#ifndef SCHEMA_H
#define SCHEMA_H

#include "BancoDados.hpp"

/**
 * @brief Cria as tabelas necessárias para o funcionamento do sistema no banco de dados.
 * @details Executa as instruções DDL (CREATE TABLE IF NOT EXISTS) para estruturar
 * as tabelas de entidades e relacionamentos caso ainda não existam.
 * @param banco Referência para o objeto BancoDados onde as tabelas serão criadas.
 */
void criarTabelas(BancoDados &banco);

#endif
