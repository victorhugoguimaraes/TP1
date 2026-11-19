#ifndef SERVICOCARTAO_H
#define SERVICOCARTAO_H

#include <vector>

#include "../entidades/CartaoAtividade.hpp"
#include "../dominios/Estado.hpp"
#include "../dominios/Identificador.hpp"

using namespace std;

class ServicoCartao {
public:
  virtual bool criar(const CartaoAtividade& cartao) = 0;
  virtual vector<CartaoAtividade> listar() const = 0;

  virtual bool consultar(const Identificador& identificador, CartaoAtividade& cartao) = 0;

  virtual bool editar(const CartaoAtividade& cartao) = 0;
  virtual bool excluir(const Identificador& identificador) = 0;

  virtual bool mover(const Identificador& identificador, const Estado& estado) = 0;

  virtual ~ServicoCartao() = default;
};

#endif
