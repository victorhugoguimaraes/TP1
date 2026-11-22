/**
 * @file ContainerProjeto.hpp
 * @brief Declaração da classe de persistência (container) para projetos e seus participantes.
 */

#ifndef CONTAINER_PROJETOS_H
#define CONTAINER_PROJETOS_H

#include "../entidades/Projeto.hpp"
#include "../persistencia/BancoDados.hpp"

using namespace std;

/**
 * @class ContainerProjetos
 * @brief Gerencia a persistência de objetos Projeto e seus vínculos com pessoas no banco SQLite.
 * @details Encapsula as operações CRUD de projetos (inserção, busca, listagem, edição e exclusão),
 * além das operações na tabela associativa para adicionar, remover e listar os e-mails dos
 * participantes vinculados a cada projeto.
 */
class ContainerProjetos {
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
    explicit ContainerProjetos(BancoDados &banco);

    /**
     * @brief Insere um novo projeto no banco de dados.
     * @param projeto Objeto Projeto contendo os dados a serem persistidos.
     * @return true se a inserção for concluída com sucesso; false caso contrário.
     */
    bool inserir(const Projeto &projeto);

    /**
     * @brief Busca um projeto pelo seu identificador único.
     * @param identificador Objeto Identificador do projeto pesquisado.
     * @param resultado Referência para o objeto Projeto que receberá os dados encontrados.
     * @return true se o projeto for encontrado; false caso contrário.
     */
    bool buscar(const Identificador &identificador, Projeto &resultado) const;

    /**
     * @brief Recupera todos os projetos cadastrados no banco de dados.
     * @return Vetor contendo todos os objetos Projeto armazenados.
     */
    vector<Projeto> listar() const;

    /**
     * @brief Atualiza os dados de um projeto existente no banco de dados.
     * @param projeto Objeto Projeto contendo os novos dados do registro.
     * @return true se o registro for atualizado com sucesso; false caso contrário.
     */
    bool editar(const Projeto &projeto);

    /**
     * @brief Remove um projeto do banco de dados pelo seu identificador.
     * @param identificador Objeto Identificador do projeto a ser excluído.
     * @return true se o projeto for removido com sucesso; false caso contrário.
     */
    bool excluir(const Identificador &identificador);

    /**
     * @brief Vincula uma pessoa (participante) a um projeto no banco de dados.
     * @param projeto Objeto Identificador do projeto ao qual a pessoa será associada.
     * @param pessoa Objeto Email da pessoa a ser adicionada ao projeto.
     * @return true se o vínculo for registrado com sucesso; false caso contrário.
     */
    bool adicionarPessoa(const Identificador &projeto, const Email &pessoa);

    /**
     * @brief Remove o vínculo de uma pessoa com um projeto no banco de dados.
     * @param projeto Objeto Identificador do projeto do qual a pessoa será desvinculada.
     * @param pessoa Objeto Email da pessoa a ser removida do projeto.
     * @return true se o vínculo for removido com sucesso; false caso contrário.
     */
    bool removerPessoa(const Identificador &projeto, const Email &pessoa);

    /**
     * @brief Lista os e-mails de todas as pessoas vinculadas a um projeto específico.
     * @param projeto Objeto Identificador do projeto consultado.
     * @return Vetor contendo os objetos Email dos participantes associados ao projeto.
     */
    vector<Email> listarPessoas(const Identificador &projeto) const;
};

#endif
