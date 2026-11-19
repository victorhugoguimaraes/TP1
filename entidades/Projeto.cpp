#include "Projeto.hpp"

void Projeto::setIdentificador(Identificador identificador) {
    this->identificador = identificador;
}

Identificador Projeto::getIdentificador() const {
    return identificador;
}

void Projeto::setGestor(Email gestor) {
    this->gestor = gestor;
}

Email Projeto::getGestor() const {
    return gestor;
}

void Projeto::setNome(Nome nome) {
    this->nome = nome;
}

Nome Projeto::getNome() const {
    return nome;
}

void Projeto::setDescricao(Texto descricao) {
    this->descricao = descricao;
}

Texto Projeto::getDescricao() const {
    return descricao;
}

void Projeto::setInicio(Timestamp inicio) {
    this->inicio = inicio;
}

Timestamp Projeto::getInicio() const {
    return inicio;
}

void Projeto::setTermino(Timestamp termino) {
    this->termino = termino;
}

Timestamp Projeto::getTermino() const {
    return termino;
}

void Projeto::adicionarQuadro(Quadro *quadro) {
    quadros.push_back(quadro);
}

vector<Quadro *> Projeto::getQuadros() const {
    return quadros;
}

void Projeto::adicionarPessoa(Pessoa *pessoa) {
    pessoas.push_back(pessoa);
}

vector<Pessoa *> Projeto::getPessoas() const {
    return pessoas;
}
