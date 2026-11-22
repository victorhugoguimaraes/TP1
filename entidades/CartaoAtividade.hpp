/**
 * @file CartaoAtividade.hpp
 * @brief Declaração da classe de entidade CartaoAtividade.
 */

#ifndef CARTAO_ATIVIDADE_HPP
#define CARTAO_ATIVIDADE_HPP

#include "../dominios/Estado.hpp"
#include "../dominios/Identificador.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Prioridade.hpp"
#include "../dominios/Tamanho.hpp"
#include "../dominios/Texto.hpp"
#include "../dominios/Timestamp.hpp"

using namespace std;

/**
 * @class CartaoAtividade
 * @brief Entidade que representa um cartão de atividade no sistema.
 * @details Armazena os atributos fundamentais de uma tarefa ou atividade, associando-a
 * a um quadro específico e controlando seu estado, prioridade, tamanho e datas de ciclo de vida.
 */
class CartaoAtividade {
  private:
    Identificador identificador;
    Identificador quadro;
    Nome nome;
    Texto descricao;
    Prioridade prioridade;
    Estado estado;
    Tamanho tamanho;
    Timestamp entrada;
    Timestamp inicio;
    Timestamp termino;

  public:
    /**
     * @brief Define o identificador do cartão de atividade.
     * @param identificador Objeto da classe Identificador a ser atribuído.
     */
    void setIdentificador(Identificador identificador);

    /**
     * @brief Obtém o identificador do cartão de atividade.
     * @return Objeto Identificador correspondente ao cartão.
     */
    Identificador getIdentificador() const;

    /**
     * @brief Define o identificador do quadro associado ao cartão.
     * @param quadro Objeto da classe Identificador referente ao quadro.
     */
    void setQuadro(Identificador quadro);

    /**
     * @brief Obtém o identificador do quadro associado ao cartão.
     * @return Objeto Identificador correspondente ao quadro.
     */
    Identificador getQuadro() const;

    /**
     * @brief Define o nome do cartão de atividade.
     * @param nome Objeto da classe Nome a ser atribuído.
     */
    void setNome(Nome nome);

    /**
     * @brief Obtém o nome do cartão de atividade.
     * @return Objeto Nome correspondente à atividade.
     */
    Nome getNome() const;

    /**
     * @brief Define a descrição do cartão de atividade.
     * @param descricao Objeto da classe Texto contendo os detalhes da atividade.
     */
    void setDescricao(Texto descricao);

    /**
     * @brief Obtém a descrição do cartão de atividade.
     * @return Objeto Texto correspondente à descrição.
     */
    Texto getDescricao() const;

    /**
     * @brief Define a prioridade do cartão de atividade (ALTA, MEDIA ou BAIXA).
     * @param prioridade Objeto da classe Prioridade a ser atribuído.
     */
    void setPrioridade(Prioridade prioridade);


    /**
     * @brief Obtém a prioridade do cartão de atividade.
     * @return Objeto Prioridade correspondente à atividade.
     */
    Prioridade getPrioridade() const;

    /**
     * @brief Define o estado atual do cartão de atividade (A FAZER, FAZENDO ou FEITO).
     * @param estado Objeto da classe Estado a ser atribuído.
     */
    void setEstado(Estado estado);

    /**
     * @brief Obtém o estado atual do cartão de atividade.
     * @return Objeto Estado correspondente à situação do cartão.
     */
    Estado getEstado() const;

    /**
     * @brief Define o tamanho estimado da atividade (GRANDE, MEDIO ou PEQUENO).
     * @param tamanho Objeto da classe Tamanho a ser atribuído.
     */
    void setTamanho(Tamanho tamanho);

    /**
     * @brief Obtém o tamanho estimado da atividade.
     * @return Objeto Tamanho correspondente à atividade.
     */
    Tamanho getTamanho() const;

    /**
     * @brief Define o timestamp de entrada do cartão, registrado em sua criação.
     * @param entrada Objeto da classe Timestamp representando a entrada.
     */
    void setEntrada(Timestamp entrada);

    /**
     * @brief Obtém o timestamp de entrada do cartão.
     * @return Objeto Timestamp correspondente à entrada.
     */
    Timestamp getEntrada() const;

    /**
     * @brief Define o timestamp de início da atividade, registrado quando o estado do cartão é mudado para FAZENDO.
     * @param inicio Objeto da classe Timestamp representando o início.
     */
    void setInicio(Timestamp inicio);

    /**
     * @brief Obtém o timestamp de início da atividade.
     * @return Objeto Timestamp correspondente ao início.
     */
    Timestamp getInicio() const;

    /**
     * @brief Define o timestamp de término da atividade, registrado quando o estado do cartão é mudado para FEITO.
     * @param termino Objeto da classe Timestamp representando o término.
     */
    void setTermino(Timestamp termino);

    /**
     * @brief Obtém o timestamp de término da atividade.
     * @return Objeto Timestamp correspondente ao término.
     */
    Timestamp getTermino() const;
};

/**
 * @typedef Cartao
 * @brief Alias (apelido) simplificado para a classe CartaoAtividade.
 */
using Cartao = CartaoAtividade;

#endif
