#ifndef CNTRLSERVICOPROJETO_H
#define CNTRLSERVICOPROJETO_H

#include "../entidades/Pessoa.hpp"
#include "../interfaces/ServicoProjeto.hpp"
#include "ContainerProjeto.hpp"

class CntrlServicoProjeto : public ServicoProjeto {
  private:
    ContainerProjetos &container;
    const Pessoa &usuario;

  public:
    CntrlServicoProjeto(ContainerProjetos &container, const Pessoa &usuario);

    bool criar(const Projeto &projeto) override;
    vector<Projeto> listar() const override;
    bool consultar(const Identificador &identificador, Projeto &projeto) override;
    bool editar(const Projeto &projeto) override;
    bool excluir(const Identificador &identificador) override;
    bool adicionarPessoa(const Identificador &projeto, const Email &pessoa) override;
    bool removerPessoa(const Identificador &projeto, const Email &pessoa) override;
    vector<Email> listarPessoas(const Identificador &projeto) const override;
};

#endif
