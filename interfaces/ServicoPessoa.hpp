/**
 * @file ServicoPessoa.hpp
 * @brief Declaração da interface de serviço para gerenciamento de pessoas.
 */

#ifndef SERVICOPESSOA_H
#define SERVICOPESSOA_H

#include <vector>

#include "../dominios/Email.hpp"
#include "../entidades/Pessoa.hpp"

using namespace std;

/**
 * @class ServicoPessoa
 * @brief Define a interface de operações de negócio sobre pessoas (usuários).
 * @details Permite que a camada de apresentação realize operações de cadastro,
 * listagem, consulta, edição e exclusão de pessoas sem depender da implementação
 * concreta do armazenamento.
 */
class ServicoPessoa {
  public:
    /**
     * @brief Cadastra uma nova pessoa no sistema.
     * @param pessoa Objeto Pessoa contendo os dados da pessoa a ser cadastrada.
     * @return true se o cadastro for realizado com sucesso; false caso contrário.
     */
    virtual bool criar(const Pessoa &pessoa) = 0;

    /**
     * @brief Lista todas as pessoas cadastradas no sistema.
     * @return Vetor contendo os objetos Pessoa armazenados.
     */
    virtual vector<Pessoa> listar() const = 0;

    /**
     * @brief Consulta uma pessoa específica pelo seu endereço de e-mail.
     * @param email Objeto Email identificador da pessoa buscada.
     * @param pessoa Referência para o objeto Pessoa onde os dados encontrados serão armazenados.
     * @return true se a pessoa for encontrada; false caso contrário.
     */
    virtual bool consultar(const Email &email, Pessoa &pessoa) = 0;

    /**
     * @brief Atualiza os dados de uma pessoa já cadastrada.
     * @param pessoa Objeto Pessoa contendo os dados atualizados.
     * @return true se a edição for realizada com sucesso; false caso contrário.
     */
    virtual bool editar(const Pessoa &pessoa) = 0;

    /**
     * @brief Remove o cadastro de uma pessoa do sistema pelo seu e-mail.
     * @param email Objeto Email identificador da pessoa a ser excluída.
     * @return true se a exclusão for realizada com sucesso; false caso contrário.
     */
    virtual bool excluir(const Email &email) = 0;

    /**
     * @brief Permite destruir uma implementação por meio da interface.
     */
    virtual ~ServicoPessoa() = default;
};

#endif
