#ifndef SERVICOQUADRO_H
#define SERVICOQUADRO_H

#include <vector>

#include "../entidades/Quadro.hpp"
#include "../dominios/Identificador.hpp"

using namespace std;

class ServicoQuadro {
public:
  virtual bool criar(const Quadro& quadro) = 0;
  virtual vector<Quadro> listar() const = 0;

  virtual bool consultar(const Identificador& identificador, Quadro& quadro) = 0;

  virtual bool editar(const Quadro& quadro) = 0;
  virtual bool excluir(const Identificador& identificador) = 0;

  virtual ~ServicoQuadro() = default;
};

#endif
