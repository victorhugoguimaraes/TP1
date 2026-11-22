/**
 * @file ServicoCartao.hpp
 * @brief Declaração da interface de serviço para gerenciamento de cartões de atividade.
 */

#ifndef SERVICOCARTAO_H
#define SERVICOCARTAO_H

#include <vector>

#include "../dominios/Estado.hpp"
#include "../dominios/Identificador.hpp"
#include "../entidades/CartaoAtividade.hpp"

using namespace std;

/**
 * @class ServicoCartao
 * @brief Define a interface de operações de negócio sobre cartões de atividade.
 * @details Permite que a camada de apresentação realize operações de criação, consulta,
 * listagem, edição, exclusão e movimentação de estado de cartões sem depender
 * da implementação concreta do armazenamento.
 */
class ServicoCartao {
  public:
    /**
     * @brief Cria e armazena um novo cartão de atividade no sistema.
     * @param cartao Objeto CartaoAtividade contendo os dados do cartão a ser criado.
     * @return true se o cartão for criado com sucesso; false caso contrário.
     */
    virtual bool criar(const CartaoAtividade &cartao) = 0;

    /**
     * @brief Lista todos os cartões de atividade cadastrados.
     * @return Vetor contendo os objetos CartaoAtividade armazenados.
     */
    virtual vector<CartaoAtividade> listar() const = 0;

    /**
     * @brief Consulta um cartão de atividade específico pelo seu identificador.
     * @param identificador Objeto Identificador do cartão buscado.
     * @param cartao Referência para o objeto CartaoAtividade onde os dados encontrados serão armazenados.
     * @return true se o cartão for encontrado; false caso contrário.
     */
    virtual bool consultar(const Identificador &identificador, CartaoAtividade &cartao) = 0;

    /**
     * @brief Atualiza os dados de um cartão de atividade existente.
     * @param cartao Objeto CartaoAtividade contendo os dados atualizados.
     * @return true se a edição for realizada com sucesso; false caso contrário.
     */
    virtual bool editar(const CartaoAtividade &cartao) = 0;

    /**
     * @brief Remove um cartão de atividade do sistema pelo seu identificador.
     * @param identificador Objeto Identificador do cartão a ser excluído.
     * @return true se o cartão for removido com sucesso; false caso contrário.
     */
    virtual bool excluir(const Identificador &identificador) = 0;

    /**
     * @brief Altera o estado atual de um cartão de atividade no fluxo de trabalho (FAZENDO ou FEITO).
     * @param identificador Objeto Identificador do cartão a ser movido.
     * @param estado Novo objeto Estado a ser atribuído ao cartão.
     * @return true se a movimentação for realizada com sucesso; false caso contrário.
     */
    virtual bool mover(const Identificador &identificador, const Estado &estado) = 0;

    /**
     * @brief Permite destruir uma implementação por meio da interface.
     */
    virtual ~ServicoCartao() = default;
};

#endif
