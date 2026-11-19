#ifndef SERVICOPESSOA_H
#define SERVICOPESSOA_H

#include <vector>

#include "../dominios/Email.hpp"
#include "../entidades/Pessoa.hpp"

using namespace std;

class ServicoPessoa {
  public:
    virtual bool criar(const Pessoa &pessoa) = 0;
    virtual vector<Pessoa> listar() const = 0;

    virtual bool consultar(const Email &email, Pessoa &pessoa) = 0;

    virtual bool editar(const Pessoa &pessoa) = 0;
    virtual bool excluir(const Email &email) = 0;

    virtual ~ServicoPessoa() = default;
};

#endif
