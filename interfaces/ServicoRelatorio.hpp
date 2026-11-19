#ifndef SERVICORELATORIO_H
#define SERVICORELATORIO_H

#include <vector>

#include "../dominios/Identificador.hpp"

using namespace std;

class ServicoRelatorio {
  public:
    virtual int lerTempoCiclo(const Identificador &identificador) const = 0;
    virtual double lerTempoCicloMedio(const Identificador &quadro) const = 0;
    virtual int lerLeadTime(const Identificador &identificador) const = 0;
    virtual double lerLeadTimeMedio(const Identificador &quadro) const = 0;
    virtual int lerWIP(const Identificador &quadro) const = 0;

    virtual ~ServicoRelatorio() = default;
};

#endif
