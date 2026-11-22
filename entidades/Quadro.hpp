/**
 * @file Quadro.hpp
 * @brief Declaração da classe de entidade Quadro.
 */

#ifndef QUADRO_HPP
#define QUADRO_HPP

#include <vector>

#include "../dominios/Identificador.hpp"
#include "../dominios/Limite.hpp"
#include "../dominios/Nome.hpp"

using namespace std;

class CartaoAtividade;

/**
 * @class Quadro
 * @brief Entidade que representa um quadro de atividades dentro de um projeto.
 * @details Armazena a identificação do quadro, seu vínculo com o projeto pai,
 * o limite máximo de capacidade e a coleção de cartões de atividade associados.
 */
class Quadro {
  private:
    Identificador identificador;
    Identificador projeto;
    Nome nome;
    Limite limite;
    vector<CartaoAtividade *> cartoes;

  public:
    /**
     * @brief Define o identificador do quadro.
     * @param identificador Objeto da classe Identificador a ser atribuído.
     */
    void setIdentificador(Identificador identificador);

    /**
     * @brief Obtém o identificador do quadro.
     * @return Objeto Identificador correspondente ao quadro.
     */
    Identificador getIdentificador() const;

    /**
     * @brief Define o identificador do projeto ao qual o quadro pertence.
     * @param projeto Objeto da classe Identificador referente ao projeto.
     */
    void setProjeto(Identificador projeto);

    /**
     * @brief Obtém o identificador do projeto associado ao quadro.
     * @return Objeto Identificador correspondente ao projeto.
     */
    Identificador getProjeto() const;

    /**
     * @brief Define o nome do quadro.
     * @param nome Objeto da classe Nome a ser atribuído.
     */
    void setNome(Nome nome);

    /**
     * @brief Obtém o nome do quadro.
     * @return Objeto Nome correspondente ao quadro.
     */
    Nome getNome() const;

    /**
     * @brief Define o limite máximo de cartões permitidos no quadro.
     * @param limite Objeto da classe Limite a ser atribuído.
     */
    void setLimite(Limite limite);

    /**
     * @brief Obtém o limite máximo de cartões do quadro.
     * @return Objeto Limite correspondente à capacidade do quadro.
     */
    Limite getLimite() const;

    /**
     * @brief Adiciona um cartão de atividade à lista de cartões do quadro.
     * @param cartao Ponteiro para o objeto CartaoAtividade a ser adicionado.
     */
    void adicionarCartao(CartaoAtividade *cartao);

    /**
     * @brief Obtém a lista de cartões de atividade contidos no quadro.
     * @return Vetor de ponteiros (vector<CartaoAtividade *>) contendo os cartões vinculados.
     */
    vector<CartaoAtividade *> getCartoes() const;
};

#endif
