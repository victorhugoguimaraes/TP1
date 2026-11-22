/**
 * @file Projeto.hpp
 * @brief Declaração da classe de entidade Projeto.
 */

#ifndef PROJETO_HPP
#define PROJETO_HPP

#include <vector>

#include "../dominios/Email.hpp"
#include "../dominios/Identificador.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Texto.hpp"
#include "../dominios/Timestamp.hpp"

using namespace std;

class Quadro;
class Pessoa;

/**
 * @class Projeto
 * @brief Entidade que representa um projeto no sistema.
 * @details Armazena os dados principais de um projeto, incluindo seu gestor,
 * período de vigência e as associações com seus respectivos quadros e membros participantes.
 */
class Projeto {
  private:
    Identificador identificador;
    Email gestor;
    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;
    vector<Quadro *> quadros;
    vector<Pessoa *> pessoas;

  public:
    /**
     * @brief Define o identificador do projeto.
     * @param identificador Objeto da classe Identificador a ser atribuído.
     */
    void setIdentificador(Identificador identificador);

    /**
     * @brief Obtém o identificador do projeto.
     * @return Objeto Identificador correspondente ao projeto.
     */
    Identificador getIdentificador() const;

    /**
     * @brief Define o e-mail do gestor responsável pelo projeto.
     * @param gestor Objeto da classe Email referente ao gestor.
     */
    void setGestor(Email gestor);

    /**
     * @brief Obtém o e-mail do gestor responsável pelo projeto.
     * @return Objeto Email correspondente ao gestor.
     */
    Email getGestor() const;

    /**
     * @brief Define o nome do projeto.
     * @param nome Objeto da classe Nome a ser atribuído.
     */
    void setNome(Nome nome);

    /**
     * @brief Obtém o nome do projeto.
     * @return Objeto Nome correspondente ao projeto.
     */
    Nome getNome() const;

    /**
     * @brief Define a descrição do projeto.
     * @param descricao Objeto da classe Texto contendo os detalhes do projeto.
     */
    void setDescricao(Texto descricao);

    /**
     * @brief Obtém a descrição do projeto.
     * @return Objeto Texto correspondente à descrição.
     */
    Texto getDescricao() const;

    /**
     * @brief Define o timestamp de início do projeto.
     * @param inicio Objeto da classe Timestamp representando a data e hora de início.
     */
    void setInicio(Timestamp inicio);

    /**
     * @brief Obtém o timestamp de início do projeto.
     * @return Objeto Timestamp correspondente ao início.
     */
    Timestamp getInicio() const;

    /**
     * @brief Define o timestamp de término do projeto.
     * @param termino Objeto da classe Timestamp representando a data e hora de término.
     */
    void setTermino(Timestamp termino);

    /**
     * @brief Obtém o timestamp de término do projeto.
     * @return Objeto Timestamp correspondente ao término.
     */
    Timestamp getTermino() const;

    /**
     * @brief Vincula um quadro à lista de quadros do projeto.
     * @param quadro Ponteiro para o objeto Quadro a ser adicionado.
     */
    void adicionarQuadro(Quadro *quadro);

    /**
     * @brief Obtém a lista de quadros pertencentes ao projeto.
     * @return Vetor de ponteiros (vector<Quadro *>) contendo os quadros vinculados.
     */
    vector<Quadro *> getQuadros() const;

    /**
     * @brief Vincula uma pessoa à equipe participante do projeto.
     * @param pessoa Ponteiro para o objeto Pessoa a ser adicionado.
     */
    void adicionarPessoa(Pessoa *pessoa);

    /**
     * @brief Obtém a lista de pessoas participantes do projeto.
     * @return Vetor de ponteiros (vector<Pessoa *>) contendo os membros vinculados.
     */
    vector<Pessoa *> getPessoas() const;
};

#endif
