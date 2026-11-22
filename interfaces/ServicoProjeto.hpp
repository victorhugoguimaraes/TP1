/**
 * @file ServicoProjeto.hpp
 * @brief Declaração da interface de serviço para gerenciamento de projetos.
 */

#ifndef SERVICOPROJETO_H
#define SERVICOPROJETO_H

#include <vector>

#include "../dominios/Email.hpp"
#include "../dominios/Identificador.hpp"
#include "../entidades/Projeto.hpp"

using namespace std;

/**
 * @class ServicoProjeto
 * @brief Define a interface de operações de negócio sobre projetos.
 * @details Permite que a camada de apresentação realize operações de criação,
 * listagem, consulta, edição e exclusão de projetos, além do gerenciamento
 * de participantes vinculados a cada projeto, sem depender da implementação concreta.
 */
class ServicoProjeto {
  public:
    /**
     * @brief Cria e armazena um novo projeto no sistema.
     * @param projeto Objeto Projeto contendo os dados do projeto a ser criado.
     * @return true se o projeto for criado com sucesso; false caso contrário.
     */
    virtual bool criar(const Projeto &projeto) = 0;

    /**
     * @brief Lista todos os projetos cadastrados no sistema.
     * @return Vetor contendo os objetos Projeto armazenados.
     */
    virtual vector<Projeto> listar() const = 0;

    /**
     * @brief Consulta um projeto específico pelo seu identificador.
     * @param identificador Objeto Identificador do projeto buscado.
     * @param projeto Referência para o objeto Projeto onde os dados encontrados serão armazenados.
     * @return true se o projeto for encontrado; false caso contrário.
     */
    virtual bool consultar(const Identificador &identificador, Projeto &projeto) = 0;

    /**
     * @brief Atualiza os dados de um projeto já cadastrado.
     * @param projeto Objeto Projeto contendo os dados atualizados.
     * @return true se a edição for realizada com sucesso; false caso contrário.
     */
    virtual bool editar(const Projeto &projeto) = 0;

    /**
     * @brief Remove um projeto do sistema pelo seu identificador.
     * @param identificador Objeto Identificador do projeto a ser excluído.
     * @return true se a exclusão for realizada com sucesso; false caso contrário.
     */
    virtual bool excluir(const Identificador &identificador) = 0;

    /**
     * @brief Vincula uma pessoa à equipe participante de um projeto.
     * @param projeto Objeto Identificador do projeto ao qual a pessoa será adicionada.
     * @param pessoa Objeto Email identificador da pessoa a ser vinculada.
     * @return true se a associação for realizada com sucesso; false caso contrário.
     */
    virtual bool adicionarPessoa(const Identificador &projeto, const Email &pessoa) = 0;

    /**
     * @brief Remove o vínculo de uma pessoa com um projeto.
     * @param projeto Objeto Identificador do projeto do qual a pessoa será removida.
     * @param pessoa Objeto Email identificador da pessoa a ser desvinculada.
     * @return true se a remoção for realizada com sucesso; false caso contrário.
     */
    virtual bool removerPessoa(const Identificador &projeto, const Email &pessoa) = 0;

    /**
     * @brief Lista os e-mails de todas as pessoas vinculadas a um projeto.
     * @param projeto Objeto Identificador do projeto cujos participantes serão listados.
     * @return Vetor contendo os objetos Email das pessoas associadas ao projeto.
     */
    virtual vector<Email> listarPessoas(const Identificador &projeto) const = 0;

    /**
     * @brief Permite destruir uma implementação por meio da interface.
     */
    virtual ~ServicoProjeto() = default;
};

#endif
