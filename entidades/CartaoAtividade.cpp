#include "CartaoAtividade.hpp"

void CartaoAtividade::setIdentificador(Identificador identificador) {
    this->identificador = identificador;
}

Identificador CartaoAtividade::getIdentificador() const {
    return identificador;
}

void CartaoAtividade::setNome(Nome nome) {
    this->nome = nome;
}

Nome CartaoAtividade::getNome() const {
    return nome;
}

void CartaoAtividade::setDescricao(Texto descricao) {
    this->descricao = descricao;
}

Texto CartaoAtividade::getDescricao() const {
    return descricao;
}

void CartaoAtividade::setPrioridade(Prioridade prioridade) {
    this->prioridade = prioridade;
}

Prioridade CartaoAtividade::getPrioridade() const {
    return prioridade;
}

void CartaoAtividade::setEstado(Estado estado) {
    this->estado = estado;
}

Estado CartaoAtividade::getEstado() const {
    return estado;
}

void CartaoAtividade::setTamanho(Tamanho tamanho) {
    this->tamanho = tamanho;
}

Tamanho CartaoAtividade::getTamanho() const {
    return tamanho;
}

void CartaoAtividade::setEntrada(Timestamp entrada) {
    this->entrada = entrada;
}

Timestamp CartaoAtividade::getEntrada() const {
    return entrada;
}

void CartaoAtividade::setInicio(Timestamp inicio) {
    this->inicio = inicio;
}

Timestamp CartaoAtividade::getInicio() const {
    return inicio;
}

void CartaoAtividade::setTermino(Timestamp termino) {
    this->termino = termino;
}

Timestamp CartaoAtividade::getTermino() const {
    return termino;
}
