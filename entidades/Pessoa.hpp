/**
 * @file Pessoa.hpp
 * @brief Declaração da classe de entidade Pessoa.
 */

#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <vector>

#include "../dominios/Email.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Papel.hpp"
#include "../dominios/Senha.hpp"

using namespace std;

class Projeto;
class CartaoAtividade;

/**
 * @class Pessoa
 * @brief Entidade que representa uma pessoa (usuário) no sistema.
 * @details Armazena os dados cadastrais e de autenticação de um participante,
 * além de manter as referências para os projetos e cartões de atividade vinculados a ele.
 */
class Pessoa {
  private:
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;
    vector<Projeto *> projetos;
    vector<CartaoAtividade *> cartoes;

  public:
    /**
     * @brief Define o endereço de e-mail da pessoa.
     * @param email Objeto da classe Email a ser atribuído.
     */
    void setEmail(Email email);

    /**
     * @brief Obtém o endereço de e-mail da pessoa.
     * @return Objeto Email correspondente ao usuário.
     */
    Email getEmail() const;

    /**
     * @brief Define o nome da pessoa.
     * @param nome Objeto da classe Nome a ser atribuído.
     */
    void setNome(Nome nome);

    /**
     * @brief Obtém o nome da pessoa.
     * @return Objeto Nome correspondente ao usuário.
     */
    Nome getNome() const;

    /**
     * @brief Define a senha de acesso da pessoa.
     * @param senha Objeto da classe Senha a ser atribuído.
     */
    void setSenha(Senha senha);

    /**
     * @brief Obtém a senha de acesso da pessoa.
     * @return Objeto Senha correspondente ao usuário.
     */
    Senha getSenha() const;

    /**
     * @brief Define o papel desempenhado pela pessoa (GESTOR ou DESENVOLVEDOR).
     * @param papel Objeto da classe Papel a ser atribuído.
     */
    void setPapel(Papel papel);

    /**
     * @brief Obtém o papel desempenhado pela pessoa.
     * @return Objeto Papel correspondente ao usuário.
     */
    Papel getPapel() const;

    /**
     * @brief Vincula um projeto à lista de projetos da pessoa.
     * @param projeto Ponteiro para o objeto Projeto a ser adicionado.
     */
    void adicionarProjeto(Projeto *projeto);

    /**
     * @brief Obtém a lista de projetos associados à pessoa.
     * @return Vetor de ponteiros (vector<Projeto *>) contendo os projetos vinculados.
     */
    vector<Projeto *> getProjetos() const;

    /**
     * @brief Atribui um cartão de atividade à lista de cartões da pessoa.
     * @param cartao Ponteiro para o objeto CartaoAtividade a ser adicionado.
     */
    void adicionarCartao(CartaoAtividade *cartao);

    /**
     * @brief Obtém a lista de cartões de atividade atribuídos à pessoa.
     * @return Vetor de ponteiros (vector<CartaoAtividade *>) contendo os cartões vinculados.
     */
    vector<CartaoAtividade *> getCartoes() const;
};

#endif
