/**
 * @file ContainerQuadro.hpp
 * @brief Declaração da classe de persistência (container) para quadros de atividades.
 */

#ifndef CONTAINER_QUADROS_H
#define CONTAINER_QUADROS_H

#include "../entidades/Quadro.hpp"
#include "../persistencia/BancoDados.hpp"

using namespace std;

/**
 * @class ContainerQuadros
 * @brief Gerencia a persistência de objetos Quadro no banco de dados SQLite.
 * @details Encapsula as operações CRUD (inserção, busca, listagem, edição e exclusão)
 * dos quadros de atividades armazenados no banco de dados.
 */
class ContainerQuadros {
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
    explicit ContainerQuadros(BancoDados &banco);

    /**
     * @brief Insere um novo quadro de atividades no banco de dados.
     * @param quadro Objeto Quadro contendo os dados a serem persistidos.
     * @return true se a inserção for concluída com sucesso; false caso contrário.
     */
    bool inserir(const Quadro &quadro);

    /**
     * @brief Busca um quadro de atividades pelo seu identificador único.
     * @param identificador Objeto Identificador do quadro pesquisado.
     * @param resultado Referência para o objeto Quadro que receberá os dados encontrados.
     * @return true se o quadro for encontrado; false caso contrário.
     */
    bool buscar(const Identificador &identificador, Quadro &resultado) const;

    /**
     * @brief Recupera todos os quadros de atividades cadastrados no banco de dados.
     * @return Vetor contendo todos os objetos Quadro armazenados.
     */
    vector<Quadro> listar() const;

    /**
     * @brief Atualiza os dados de um quadro de atividades existente no banco de dados.
     * @param quadro Objeto Quadro contendo os novos dados do registro.
     * @return true se o registro for atualizado com sucesso; false caso contrário.
     */
    bool editar(const Quadro &quadro);

    /**
     * @brief Remove um quadro de atividades do banco de dados pelo seu identificador.
     * @param identificador Objeto Identificador do quadro a ser excluído.
     * @return true se o quadro for removido com sucesso; false caso contrário.
     */
    bool excluir(const Identificador &identificador);
};

#endif
