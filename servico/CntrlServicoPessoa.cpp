#include "CntrlServicoPessoa.hpp"

CntrlServicoPessoa::CntrlServicoPessoa(ContainerPessoas& container) : container(container) {}

bool CntrlServicoPessoa::criar(const Pessoa& pessoa) {
  return container.inserir(pessoa);
}

vector<Pessoa> CntrlServicoPessoa::listar() const {
  return container.listar();
}

bool CntrlServicoPessoa::consultar(const Email& email, Pessoa& pessoa) {
  return container.buscar(email, pessoa);
}

bool CntrlServicoPessoa::editar(const Pessoa& pessoa) {
  return container.editar(pessoa);
}

bool CntrlServicoPessoa::excluir(const Email& email) {
  return container.excluir(email);
}
