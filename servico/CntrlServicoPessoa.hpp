/**
 * @file CntrlServicoPessoa.hpp
 * @brief Declaração da classe controladora de serviço para gerenciamento de pessoas.
 */

#ifndef CNTRLSERVICOPESSOA_H
#define CNTRLSERVICOPESSOA_H

#include "../interfaces/ServicoPessoa.hpp"
#include "ContainerPessoa.hpp"

/**
 * @class CntrlServicoPessoa
 * @brief Implementa as regras de negócio e operações de persistência para pessoas.
 * @details Realiza as operações definidas em ServicoPessoa delegando o armazenamento
 * e a recuperação dos cadastros ao ContainerPessoas associado.
 */
class CntrlServicoPessoa : public ServicoPessoa {
  private:
    /**
     * @brief Referência ao container onde as pessoas registradas estão armazenadas.
     */
    ContainerPessoas &container;

  public:
    /**
     * @brief Constrói a controladora associando o container de pessoas.
     * @param container Referência ao container responsável pelo armazenamento das pessoas.
     */
    explicit CntrlServicoPessoa(ContainerPessoas &container);

    /**
     * @brief Cadastra uma nova pessoa no sistema.
     * @param pessoa Objeto Pessoa contendo os dados validados do novo usuário.
     * @return true se o cadastro for realizado com sucesso; false caso contrário (ex.: e-mail já existente).
     */
    bool criar(const Pessoa &pessoa) override;

    /**
     * @brief Lista todas as pessoas cadastradas no sistema.
     * @return Vetor contendo todos os objetos Pessoa registrados no container.
     */
    vector<Pessoa> listar() const override;

    /**
     * @brief Consulta os dados de uma pessoa específica a partir do seu e-mail.
     * @param email Objeto Email usado como chave de busca.
     * @param pessoa Referência para o objeto Pessoa que receberá os dados encontrados.
     * @return true se a pessoa for encontrada; false caso contrário.
     */
    bool consultar(const Email &email, Pessoa &pessoa) override;

    /**
     * @brief Atualiza os dados cadastrais de uma pessoa existente.
     * @param pessoa Objeto Pessoa contendo os novos dados a serem persistidos.
     * @return true se a atualização for concluída com sucesso; false caso contrário.
     */
    bool editar(const Pessoa &pessoa) override;

    /**
     * @brief Remove o cadastro de uma pessoa do sistema pelo seu e-mail.
     * @param email Objeto Email da pessoa a ser excluída.
     * @return true se a remoção for concluída com sucesso; false caso contrário.
     */
    bool excluir(const Email &email) override;
};

#endif
