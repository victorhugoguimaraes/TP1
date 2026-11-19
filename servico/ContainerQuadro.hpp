#ifndef CONTAINER_QUADROS_H
#define CONTAINER_QUADROS_H

#include "../entidades/Quadro.hpp"
#include "../persistencia/BancoDados.hpp"

using namespace std;

class ContainerQuadros {
private:
  BancoDados& banco;

public:
  explicit ContainerQuadros(BancoDados& banco);

  bool inserir(const Quadro& quadro);
  bool buscar(const Identificador& identificador, Quadro& resultado) const;
  vector<Quadro> listar() const;
  bool editar(const Quadro& quadro);
  bool excluir(const Identificador& identificador);
};

#endif
