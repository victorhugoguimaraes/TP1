#ifndef CONTAINER_CARTOES_H
#define CONTAINER_CARTOES_H

#include <vector>

#include "../entidades/CartaoAtividade.hpp"
#include "../persistencia/BancoDados.hpp"

using namespace std;

class ContainerCartoes {
private:
  BancoDados& banco;

public:
  explicit ContainerCartoes(BancoDados& banco);

  bool inserir(const CartaoAtividade& cartao);
  bool buscar(const Identificador& identificador, CartaoAtividade& resultado) const;
  vector<CartaoAtividade> listar() const;
  bool editar(const CartaoAtividade& cartao);
  bool excluir(const Identificador& identificador);
  bool mover(const Identificador& identificador, const Estado& estado);
  int contarPorEstado(const Identificador& quadro, Estado::Status estado) const;
};

#endif
