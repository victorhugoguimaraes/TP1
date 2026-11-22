/**
 * @file ContainerCartao.hpp
 * @brief Declaração da classe de persistência (container) para cartões de atividade.
 */

#ifndef CONTAINER_CARTOES_H
#define CONTAINER_CARTOES_H

#include <vector>

#include "../entidades/CartaoAtividade.hpp"
#include "../persistencia/BancoDados.hpp"

using namespace std;

/**
 * @class ContainerCartoes
 * @brief Gerencia a persistência de objetos CartaoAtividade no banco de dados SQLite.
 * @details Encapsula as operações CRUD (inserção, busca, listagem, edição e exclusão),
 * além de consultas específicas de mudança de estado e contagem para cálculo de métricas.
 */
class ContainerCartoes {
  private:
    /**
     * @brief Referência ao gerenciador da conexão com o banco de dados SQLite.
     */
    BancoDados &banco;

  public:
    /**
     * @brief Constrói o container associando-o a uma instância ativa de BancoDados.
     * @param banco Referência ao objeto BancoDados utilizado nas operações SQL.
     */
    explicit ContainerCartoes(BancoDados &banco);

    /**
     * @brief Insere um novo cartão de atividade no banco de dados.
     * @param cartao Objeto CartaoAtividade contendo os dados a serem persistidos.
     * @return true se a inserção for concluída com sucesso; false caso contrário.
     */
    bool inserir(const CartaoAtividade &cartao);

    /**
     * @brief Busca um cartão de atividade pelo seu identificador único.
     * @param identificador Objeto Identificador do cartão pesquisado.
     * @param resultado Referência para o objeto CartaoAtividade que receberá os dados encontrados.
     * @return true se o cartão for encontrado; false caso contrário.
     */
    bool buscar(const Identificador &identificador, CartaoAtividade &resultado) const;

    /**
     * @brief Recupera todos os cartões de atividade cadastrados no banco de dados.
     * @return Vetor contendo todos os objetos CartaoAtividade armazenados.
     */
    vector<CartaoAtividade> listar() const;

    /**
     * @brief Atualiza os dados de um cartão de atividade existente no banco de dados.
     * @param cartao Objeto CartaoAtividade contendo os novos dados do registro.
     * @return true se o registro for atualizado com sucesso; false caso contrário.
     */
    bool editar(const CartaoAtividade &cartao);

    /**
     * @brief Remove um cartão de atividade do banco de dados pelo seu identificador.
     * @param identificador Objeto Identificador do cartão a ser excluído.
     * @return true se o cartão for removido com sucesso; false caso contrário.
     */
    bool excluir(const Identificador &identificador);

    /**
     * @brief Atualiza o estado de um cartão de atividade e seus respectivos timestamps.
     * @param identificador Objeto Identificador do cartão a ser movido.
     * @param estado Novo objeto Estado a ser atribuído ao cartão.
     * @return true se a atualização de estado for bem-sucedida; false caso contrário.
     */
    bool mover(const Identificador &identificador, const Estado &estado);

    /**
     * @brief Conta quantos cartões de um quadro específico encontram-se em determinado estado.
     * @param quadro Objeto Identificador do quadro analisado.
     * @param estado Valor enumerado Estado::Status usado como filtro da contagem.
     * @return Número inteiro de cartões que satisfazem os critérios informados.
     */
    int contarPorEstado(const Identificador &quadro, Estado::Status estado) const;
};

#endif
