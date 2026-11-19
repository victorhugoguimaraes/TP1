#ifndef CONTAINER_PROJETOS_H
#define CONTAINER_PROJETOS_H

#include "../entidades/Projeto.hpp"
#include "../persistencia/BancoDados.hpp"

using namespace std;

class ContainerProjetos {
  private:
    BancoDados &banco;

  public:
    explicit ContainerProjetos(BancoDados &banco);

    bool inserir(const Projeto &projeto);
    bool buscar(const Identificador &identificador, Projeto &resultado) const;
    vector<Projeto> listar() const;
    bool editar(const Projeto &projeto);
    bool excluir(const Identificador &identificador);
    bool adicionarPessoa(const Identificador &projeto, const Email &pessoa);
    bool removerPessoa(const Identificador &projeto, const Email &pessoa);
    vector<Email> listarPessoas(const Identificador &projeto) const;
};

#endif
