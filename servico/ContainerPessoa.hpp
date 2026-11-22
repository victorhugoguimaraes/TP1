#ifndef CONTAINER_PESSOAS_H
#define CONTAINER_PESSOAS_H

#include "../entidades/Pessoa.hpp"
#include "../persistencia/BancoDados.hpp"

using namespace std;

/**
 * @class ContainerPessoas
 * @brief Armazena e recupera pessoas identificadas pelo email.
 * @details Utiliza um banco SQLite para persistir os cadastros.
 */
class ContainerPessoas {
  private:
    /**
     * @brief Banco utilizado para persistir as pessoas.
     */
    BancoDados &banco;

  public:
    /**
     * @brief Associa o container a uma conexao de banco existente.
     * @param banco Banco que deve permanecer existente durante o uso do container.
     */
    explicit ContainerPessoas(BancoDados &banco);

    /**
     * @brief Insere uma pessoa quando seu email ainda nao esta cadastrado.
     * @param pessoa Pessoa com os dados previamente validados pelos dominios.
     * @return true se inserida; false se o email ja existir.
     */
    bool inserir(const Pessoa &pessoa);

    /**
     * @brief Procura uma pessoa pelo email sem modificar o banco.
     * @param email Email a ser procurado.
     * @param resultado Recebe uma copia da pessoa encontrada.
     * @return true se a pessoa for encontrada; false caso contrario.
     */
    bool buscar(const Email &email, Pessoa &resultado) const;

    /**
     * @brief Retorna uma copia de todas as pessoas cadastradas.
     * @return Vetor de pessoas cadastradas.
     */
    vector<Pessoa> listar() const;

    /**
     * @brief Atualiza os dados de uma pessoa identificada pelo email.
     * @param pessoa Pessoa com os novos dados.
     * @return true se a pessoa foi atualizada; false se nao foi encontrada.
     */
    bool editar(const Pessoa &pessoa);

    /**
     * @brief Exclui uma pessoa identificada pelo email.
     * @param email Email da pessoa a ser excluida.
     * @return true se a pessoa foi excluida; false se nao foi encontrada.
     */
    bool excluir(const Email &email);
};

#endif
