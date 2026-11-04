#include "TesteEntidade.h"

#include <stdexcept>

namespace {

template <typename Funcao>
void testarFalha(Funcao funcao, int& estado) {
    try {
        funcao();
        estado = -1;
    } catch (const std::invalid_argument&) {
    }
}

}

void TUPessoa::setUp() { pessoa = new Pessoa(); estado = SUCESSO; }
void TUPessoa::tearDown() { delete pessoa; }
void TUPessoa::testarCenarioSucesso() {
    Email email;
    email.setValor("pessoa@dominio");
    Nome nome;
    nome.setNome("Pessoa Teste");
    Senha senha;
    senha.setValor("Abc12");
    Papel papel;
    papel.setCargo(Papel::Gestor);

    pessoa->setEmail(email);
    pessoa->setNome(nome);
    pessoa->setSenha(senha);
    pessoa->setPapel(papel);

    Projeto projeto;
    pessoa->adicionarProjeto(&projeto);

    pessoa->setPapel(papel);
    if (pessoa->getEmail().getValor() != "pessoa@dominio" ||
        pessoa->getNome().getNome() != "Pessoa Teste" ||
        pessoa->getSenha().getValor() != "Abc12" ||
        pessoa->getPapel().getCargo() != Papel::Gestor ||
        pessoa->getProjetos().size() != 1 ||
        pessoa->getProjetos()[0] != &projeto)
        estado = FALHA;
}
void TUPessoa::testarCenarioFalha() {
    Papel papel;
    papel.setCargo(Papel::Desenvolvedor);
    pessoa->setPapel(papel);
    Projeto projeto;
    testarFalha([this, &projeto] { pessoa->adicionarProjeto(&projeto); }, estado);
}
int TUPessoa::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUProjeto::setUp() { projeto = new Projeto(); estado = SUCESSO; }
void TUProjeto::tearDown() { delete projeto; }
void TUProjeto::testarCenarioSucesso() {
    Identificador identificador;
    identificador.setIdentificador("Pro123");
    Nome nome;
    nome.setNome("Projeto");
    Texto descricao;
    descricao.setTexto("Descricao valida.");
    Timestamp inicio;
    inicio.setTimestamp("01-JAN-2024-08:00");
    Timestamp termino;
    termino.setTimestamp("31-JAN-2024-18:00");
    Quadro quadro;

    projeto->setIdentificador(identificador);
    projeto->setNome(nome);
    projeto->setDescricao(descricao);
    projeto->setInicio(inicio);
    projeto->setTermino(termino);
    projeto->adicionarQuadro(&quadro);

    if (projeto->getIdentificador().getIdentificador() != "Pro123" ||
        projeto->getNome().getNome() != "Projeto" ||
        projeto->getDescricao().getTexto() != "Descricao valida." ||
        projeto->getInicio().getTimestamp() != "01-JAN-2024-08:00" ||
        projeto->getTermino().getTimestamp() != "31-JAN-2024-18:00" ||
        projeto->getQuadros().size() != 1 ||
        projeto->getQuadros()[0] != &quadro)
        estado = FALHA;
}
int TUProjeto::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

void TUQuadro::setUp() { quadro = new Quadro(); estado = SUCESSO; }
void TUQuadro::tearDown() { delete quadro; }
void TUQuadro::testarCenarioSucesso() {
    Identificador identificador;
    identificador.setIdentificador("Qua123");
    Nome nome;
    nome.setNome("Quadro");
    Limite limite;
    limite.setLimite(10);
    CartaoAtividade cartao;

    quadro->setIdentificador(identificador);
    quadro->setNome(nome);
    quadro->setLimite(limite);
    quadro->adicionarCartao(&cartao);

    if (quadro->getIdentificador().getIdentificador() != "Qua123" ||
        quadro->getNome().getNome() != "Quadro" ||
        quadro->getLimite().getLimite() != 10 ||
        quadro->getCartoes().size() != 1 ||
        quadro->getCartoes()[0] != &cartao)
        estado = FALHA;
}
int TUQuadro::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

void TUCartaoAtividade::setUp() { cartao = new CartaoAtividade(); estado = SUCESSO; }
void TUCartaoAtividade::tearDown() { delete cartao; }
void TUCartaoAtividade::testarCenarioSucesso() {
    Identificador identificador;
    identificador.setIdentificador("Car123");
    Nome nome;
    nome.setNome("Cartao");
    Texto descricao;
    descricao.setTexto("Tarefa valida.");
    Prioridade prioridade;
    prioridade.setPrioridade(Prioridade::ALTA);
    Estado estadoCartao;
    estadoCartao.setEstado(Estado::FAZENDO);
    Tamanho tamanho;
    tamanho.setTamanho(Tamanho::MEDIO);
    Timestamp entrada;
    entrada.setTimestamp("01-JAN-2024-08:00");
    Timestamp inicio;
    inicio.setTimestamp("01-JAN-2024-09:00");
    Timestamp termino;
    termino.setTimestamp("01-JAN-2024-10:00");

    cartao->setIdentificador(identificador);
    cartao->setNome(nome);
    cartao->setDescricao(descricao);
    cartao->setPrioridade(prioridade);
    cartao->setEstado(estadoCartao);
    cartao->setTamanho(tamanho);
    cartao->setEntrada(entrada);
    cartao->setInicio(inicio);
    cartao->setTermino(termino);

    if (cartao->getIdentificador().getIdentificador() != "Car123" ||
        cartao->getNome().getNome() != "Cartao" ||
        cartao->getDescricao().getTexto() != "Tarefa valida." ||
        cartao->getPrioridade().getPrioridade() != Prioridade::ALTA ||
        cartao->getEstado().getEstado() != Estado::FAZENDO ||
        cartao->getTamanho().getTamanho() != Tamanho::MEDIO ||
        cartao->getEntrada().getTimestamp() != "01-JAN-2024-08:00" ||
        cartao->getInicio().getTimestamp() != "01-JAN-2024-09:00" ||
        cartao->getTermino().getTimestamp() != "01-JAN-2024-10:00")
        estado = FALHA;
}
int TUCartaoAtividade::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
