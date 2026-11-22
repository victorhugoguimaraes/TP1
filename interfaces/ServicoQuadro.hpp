/**
 * @file ServicoQuadro.hpp
 * @brief Declaração da interface de serviço para gerenciamento de quadros de atividades.
 */

#ifndef SERVICOQUADRO_H
#define SERVICOQUADRO_H

#include <vector>

#include "../dominios/Identificador.hpp"
#include "../entidades/Quadro.hpp"

using namespace std;

/**
 * @class ServicoQuadro
 * @brief Define a interface de operações de negócio sobre quadros de atividades.
 * @details Permite que a camada de apresentação realize operações de criação,
 * listagem, consulta, edição e exclusão de quadros sem depender da implementação
 * concreta do armazenamento.
 */
class ServicoQuadro {
  public:
    /**
     * @brief Cria e armazena um novo quadro de atividades no sistema.
     * @param quadro Objeto Quadro contendo os dados do quadro a ser criado.
     * @return true se o quadro for criado com sucesso; false caso contrário.
     */
    virtual bool criar(const Quadro &quadro) = 0;

    /**
     * @brief Lista todos os quadros de atividades cadastrados no sistema.
     * @return Vetor contendo os objetos Quadro armazenados.
     */
    virtual vector<Quadro> listar() const = 0;
//
    /**
     * @brief Consulta um quadro específico pelo seu identificador.
     * @param identificador Objeto Identificador do quadro buscado.
     * @param quadro Referência para o objeto Quadro onde os dados encontrados serão armazenados.
     * @return true se o quadro for encontrado; false caso contrário.
     */
    virtual bool consultar(const Identificador &identificador, Quadro &quadro) = 0;

    /**
     * @brief Atualiza os dados de um quadro de atividades já cadastrado.
     * @param quadro Objeto Quadro contendo os dados atualizados.
     * @return true se a edição for realizada com sucesso; false caso contrário.
     */
    virtual bool editar(const Quadro &quadro) = 0;

    /**
     * @brief Remove um quadro de atividades do sistema pelo seu identificador.
     * @param identificador Objeto Identificador do quadro a ser excluído.
     * @return true se a exclusão for realizada com sucesso; false caso contrário.
     */
    virtual bool excluir(const Identificador &identificador) = 0;

    /**
     * @brief Permite destruir uma implementação por meio da interface.
     */
    virtual ~ServicoQuadro() = default;
};

#endif
