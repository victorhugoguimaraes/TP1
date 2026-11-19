#ifndef SERVICOPROJETO_H
#define SERVICOPROJETO_H

#include <vector>

#include "../entidades/Projeto.hpp"
#include "../dominios/Identificador.hpp"
#include "../dominios/Email.hpp"

using namespace std;

class ServicoProjeto {
public:
  virtual bool criar(const Projeto& projeto) = 0;
  virtual vector<Projeto> listar() const = 0;

  virtual bool consultar(const Identificador& identificador, Projeto& projeto) = 0;

  virtual bool editar(const Projeto& projeto) = 0;
  virtual bool excluir(const Identificador& identificador) = 0;
  virtual bool adicionarPessoa(const Identificador& projeto, const Email& pessoa) = 0;
  virtual bool removerPessoa(const Identificador& projeto, const Email& pessoa) = 0;
  virtual vector<Email> listarPessoas(const Identificador& projeto) const = 0;

  virtual ~ServicoProjeto() = default;
};

#endif
