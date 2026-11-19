
#ifndef CNTRLSERVICOPESSOA_H
#define CNTRLSERVICOPESSOA_H

#include "../interfaces/ServicoPessoa.hpp"
#include "ContainerPessoa.hpp"

class CntrlServicoPessoa : public ServicoPessoa {
private:
  ContainerPessoas& container;

public:
  explicit CntrlServicoPessoa(ContainerPessoas& container);

  bool criar(const Pessoa& pessoa) override;
  vector<Pessoa> listar() const override;
  bool consultar(const Email& email, Pessoa& pessoa) override;
  bool editar(const Pessoa& pessoa) override;
  bool excluir(const Email& email) override;
};

#endif
