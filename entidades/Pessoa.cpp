#include "Pessoa.hpp"

#include <stdexcept>

using namespace std;

void Pessoa::setEmail(Email email) {
    this->email = email;
}

Email Pessoa::getEmail() const {
    return email;
}

void Pessoa::setNome(Nome nome) {
    this->nome = nome;
}

Nome Pessoa::getNome() const {
    return nome;
}

void Pessoa::setSenha(Senha senha) {
    this->senha = senha;
}

Senha Pessoa::getSenha() const {
    return senha;
}

void Pessoa::setPapel(Papel papel) {
    this->papel = papel;
}

Papel Pessoa::getPapel() const {
    return papel;
}

void Pessoa::adicionarProjeto(Projeto* projeto) {
    if (papel.getCargo() != Papel::Gestor)
        throw invalid_argument("Somente gestor pode possuir projetos");
    projetos.push_back(projeto);
}

vector<Projeto*> Pessoa::getProjetos() const {
    return projetos;
}

void Pessoa::adicionarCartao(CartaoAtividade* cartao) {
    if (papel.getCargo() != Papel::Desenvolvedor)
        throw invalid_argument("Somente desenvolvedor pode possuir cartoes");
    cartoes.push_back(cartao);
}

vector<CartaoAtividade*> Pessoa::getCartoes() const {
    return cartoes;
}
