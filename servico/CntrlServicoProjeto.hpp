/**
 * @file CntrlServicoProjeto.hpp
 * @brief Declaração da classe controladora de serviço para gerenciamento de projetos.
 */

#ifndef CNTRLSERVICOPROJETO_H
#define CNTRLSERVICOPROJETO_H

#include "../entidades/Pessoa.hpp"
#include "../interfaces/ServicoProjeto.hpp"
#include "ContainerProjeto.hpp"

/**
 * @class CntrlServicoProjeto
 * @brief Implementa as regras de negócio e operações de persistência para projetos.
 * @details Realiza as operações definidas em ServicoProjeto utilizando o ContainerProjetos
 * associado e o contexto da pessoa autenticada na sessão atual (como gestor ou participante).
 */
class CntrlServicoProjeto : public ServicoProjeto {
  private:
    /**
     * @brief Referência ao container onde os projetos estão armazenados.
     */
    ContainerProjetos &container;

    /**
     * @brief Referência constante para o usuário autenticado na sessão atual.
     */
    const Pessoa &usuario;

  public:
    /**
     * @brief Constrói a controladora associando o container de projetos e o usuário autenticado.
     * @param container Referência ao container responsável pelo armazenamento dos projetos.
     * @param usuario Referência constante para a pessoa autenticada na sessão atual.
     */
    CntrlServicoProjeto(ContainerProjetos &container, const Pessoa &usuario);

    bool criar(const Projeto &projeto) override;
    vector<Projeto> listar() const override;
    bool consultar(const Identificador &identificador, Projeto &projeto) override;
    bool editar(const Projeto &projeto) override;
    bool excluir(const Identificador &identificador) override;
    bool adicionarPessoa(const Identificador &projeto, const Email &pessoa) override;
    bool removerPessoa(const Identificador &projeto, const Email &pessoa) override;
    vector<Email> listarPessoas(const Identificador &projeto) const override;
};

#endif
