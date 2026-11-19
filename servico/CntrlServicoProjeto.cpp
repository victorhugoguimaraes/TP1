#include "CntrlServicoProjeto.hpp"

CntrlServicoProjeto::CntrlServicoProjeto(ContainerProjetos &container, const Pessoa &usuario)
    : container(container), usuario(usuario) {
}

namespace {

bool ehGestor(const Pessoa &pessoa) {
    return pessoa.getPapel().getCargo() == Papel::Gestor;
}

} // namespace

bool CntrlServicoProjeto::criar(const Projeto &projeto) {
    if (!ehGestor(usuario))
        return false;

    return container.inserir(projeto);
}

vector<Projeto> CntrlServicoProjeto::listar() const {
    return container.listar();
}

bool CntrlServicoProjeto::consultar(const Identificador &identificador, Projeto &projeto) {
    return container.buscar(identificador, projeto);
}

bool CntrlServicoProjeto::editar(const Projeto &projeto) {
    if (!ehGestor(usuario))
        return false;

    return container.editar(projeto);
}

bool CntrlServicoProjeto::excluir(const Identificador &identificador) {
    if (!ehGestor(usuario))
        return false;

    return container.excluir(identificador);
}

bool CntrlServicoProjeto::adicionarPessoa(const Identificador &projeto, const Email &pessoa) {
    if (!ehGestor(usuario))
        return false;

    return container.adicionarPessoa(projeto, pessoa);
}

bool CntrlServicoProjeto::removerPessoa(const Identificador &projeto, const Email &pessoa) {
    if (!ehGestor(usuario))
        return false;

    return container.removerPessoa(projeto, pessoa);
}

vector<Email> CntrlServicoProjeto::listarPessoas(const Identificador &projeto) const {
    return container.listarPessoas(projeto);
}
