/**
 * @file CntrlServicoCartao.hpp
 * @brief Declaração da classe controladora de serviço para cartões de atividade.
 */

#ifndef CNTRLSERVICOCARTAO_H
#define CNTRLSERVICOCARTAO_H

#include "../entidades/Pessoa.hpp"
#include "../interfaces/ServicoCartao.hpp"
#include "ContainerCartao.hpp"
#include "ContainerQuadro.hpp"

/**
 * @class CntrlServicoCartao
 * @brief Implementa as regras de negócio e operações de persistência para cartões de atividade.
 * @details Gerencia as operações definidas em ServicoCartao utilizando os containers
 * de cartões e quadros no contexto do usuário autenticado.
 */
class CntrlServicoCartao : public ServicoCartao {
  private:
    /**
     * @brief Referência ao container onde os cartões de atividade estão armazenados.
     */
    ContainerCartoes &container;

    /**
     * @brief Referência ao container onde os quadros estão armazenados.
     */
    ContainerQuadros &quadros;

    /**
     * @brief Referência constante para o usuário autenticado na sessão atual.
     */
    const Pessoa &usuario;

  public:
    /**
     * @brief Constrói a controladora associando os containers e o usuário autenticado.
     * @param container Referência ao container responsável pelo armazenamento dos cartões.
     * @param quadros Referência ao container responsável pelo armazenamento dos quadros.
     * @param usuario Referência constante para a pessoa autenticada na sessão atual.
     */
    CntrlServicoCartao(ContainerCartoes &container, ContainerQuadros &quadros, const Pessoa &usuario);

    bool criar(const CartaoAtividade &cartao) override;
    vector<CartaoAtividade> listar() const override;
    bool consultar(const Identificador &identificador, CartaoAtividade &cartao) override;
    bool editar(const CartaoAtividade &cartao) override;
    bool excluir(const Identificador &identificador) override;
    bool mover(const Identificador &identificador, const Estado &estado) override;
};

#endif
