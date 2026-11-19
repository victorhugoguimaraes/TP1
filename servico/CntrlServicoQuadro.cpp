#include "CntrlServicoQuadro.hpp"

CntrlServicoQuadro::CntrlServicoQuadro(ContainerQuadros& container, const Pessoa& usuario) : container(container), usuario(usuario) {}

namespace {

bool ehGestor(const Pessoa& pessoa) {
  return pessoa.getPapel().getCargo() == Papel::Gestor;
}

}

bool CntrlServicoQuadro::criar(const Quadro& quadro) {
  if (!ehGestor(usuario))
    return false;

  return container.inserir(quadro);
}

vector<Quadro> CntrlServicoQuadro::listar() const {
  return container.listar();
}

bool CntrlServicoQuadro::consultar(const Identificador& identificador, Quadro& quadro) {
  return container.buscar(identificador, quadro);
}

bool CntrlServicoQuadro::editar(const Quadro& quadro) {
  if (!ehGestor(usuario))
    return false;

  return container.editar(quadro);
}

bool CntrlServicoQuadro::excluir(const Identificador& identificador) {
  if (!ehGestor(usuario))
    return false;

  return container.excluir(identificador);
}
