#ifndef CNTRLSERVICORELATORIO_H
#define CNTRLSERVICORELATORIO_H

#include "../entidades/Pessoa.hpp"
#include "../interfaces/ServicoRelatorio.hpp"
#include "ContainerCartao.hpp"

class CntrlServicoRelatorio : public ServicoRelatorio {
private:
  ContainerCartoes& container;
  const Pessoa& usuario;

public:
  CntrlServicoRelatorio(ContainerCartoes& container, const Pessoa& usuario);

  int lerTempoCiclo(const Identificador& identificador) const override;
  double lerTempoCicloMedio(const Identificador& quadro) const override;
  int lerLeadTime(const Identificador& identificador) const override;
  double lerLeadTimeMedio(const Identificador& quadro) const override;
  int lerWIP(const Identificador& quadro) const override;
};

#endif
