/**
 * @file CntrlServicoQuadro.hpp
 * @brief Declaração da classe controladora de serviço para gerenciamento de quadros de atividades.
 */

#ifndef CNTRLSERVICOQUADRO_H
#define CNTRLSERVICOQUADRO_H

#include "../entidades/Pessoa.hpp"
#include "../interfaces/ServicoQuadro.hpp"
#include "ContainerQuadro.hpp"

/**
 * @class CntrlServicoProjeto
 * @brief Implementa as regras de negócio e operações de persistência para projetos.
 * @details Realiza as operações definidas em ServicoProjeto utilizando o ContainerProjetos
 * associado e o contexto da pessoa autenticada na sessão atual (como gestor ou participante).
 */
class CntrlServicoQuadro : public ServicoQuadro {
  private:
    /**
     * @brief Referência ao container onde os quadros estão armazenados.
     */
    ContainerQuadros &container;

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
    CntrlServicoQuadro(ContainerQuadros &container, const Pessoa &usuario);

    bool criar(const Quadro &quadro) override;
    vector<Quadro> listar() const override;
    bool consultar(const Identificador &identificador, Quadro &quadro) override;
    bool editar(const Quadro &quadro) override;
    bool excluir(const Identificador &identificador) override;
};

#endif
