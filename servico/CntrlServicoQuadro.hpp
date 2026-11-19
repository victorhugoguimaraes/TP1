#ifndef CNTRLSERVICOQUADRO_H
#define CNTRLSERVICOQUADRO_H

#include "../interfaces/ServicoQuadro.hpp"
#include "../entidades/Pessoa.hpp"
#include "ContainerQuadro.hpp"

class CntrlServicoQuadro : public ServicoQuadro {
private:
  ContainerQuadros& container;
  const Pessoa& usuario;

public:
  CntrlServicoQuadro(ContainerQuadros& container, const Pessoa& usuario);

  bool criar(const Quadro& quadro) override;
  vector<Quadro> listar() const override;
  bool consultar(const Identificador& identificador, Quadro& quadro) override;
  bool editar(const Quadro& quadro) override;
  bool excluir(const Identificador& identificador) override;
};

#endif
