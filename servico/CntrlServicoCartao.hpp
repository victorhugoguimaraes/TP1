#ifndef CNTRLSERVICOCARTAO_H
#define CNTRLSERVICOCARTAO_H

#include "../entidades/Pessoa.hpp"
#include "../interfaces/ServicoCartao.hpp"
#include "ContainerCartao.hpp"
#include "ContainerQuadro.hpp"

class CntrlServicoCartao : public ServicoCartao {
  private:
    ContainerCartoes &container;
    ContainerQuadros &quadros;
    const Pessoa &usuario;

  public:
    CntrlServicoCartao(ContainerCartoes &container, ContainerQuadros &quadros, const Pessoa &usuario);

    bool criar(const CartaoAtividade &cartao) override;
    vector<CartaoAtividade> listar() const override;
    bool consultar(const Identificador &identificador, CartaoAtividade &cartao) override;
    bool editar(const CartaoAtividade &cartao) override;
    bool excluir(const Identificador &identificador) override;
    bool mover(const Identificador &identificador, const Estado &estado) override;
};

#endif
