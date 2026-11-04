#include "TesteDominios.h"

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

void TUEmail::setUp() { email = new Email(); estado = SUCESSO; }
void TUEmail::tearDown() { delete email; }
void TUEmail::testarCenarioSucesso() {
    email->setValor("parte-local@dominio");
    if (email->getValor() != "parte-local@dominio") estado = FALHA;
}
void TUEmail::testarCenarioFalha() {
    testarFalha([this] { email->setValor("email-invalido"); }, estado);
}
int TUEmail::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUNome::setUp() { nome = new Nome(); estado = SUCESSO; }
void TUNome::tearDown() { delete nome; }
void TUNome::testarCenarioSucesso() {
    nome->setNome("Victor Hugo");
    if (nome->getNome() != "Victor Hugo") estado = FALHA;
}
void TUNome::testarCenarioFalha() {
    testarFalha([this] { nome->setNome(" Victor"); }, estado);
}
int TUNome::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUSenha::setUp() { senha = new Senha(); estado = SUCESSO; }
void TUSenha::tearDown() { delete senha; }
void TUSenha::testarCenarioSucesso() {
    senha->setValor("Abc12");
    if (senha->getValor() != "Abc12") estado = FALHA;
}
void TUSenha::testarCenarioFalha() {
    testarFalha([this] { senha->setValor("abcde"); }, estado);
}
int TUSenha::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUTexto::setUp() { texto = new Texto(); estado = SUCESSO; }
void TUTexto::tearDown() { delete texto; }
void TUTexto::testarCenarioSucesso() {
    texto->setTexto("Tarefa valida.");
    if (texto->getTexto() != "Tarefa valida.") estado = FALHA;
}
void TUTexto::testarCenarioFalha() {
    testarFalha([this] { texto->setTexto("texto invalido"); }, estado);
}
int TUTexto::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUTimestamp::setUp() { timestamp = new Timestamp(); estado = SUCESSO; }
void TUTimestamp::tearDown() { delete timestamp; }
void TUTimestamp::testarCenarioSucesso() {
    timestamp->setTimestamp("29-FEV-2024-23:59");
    if (timestamp->getTimestamp() != "29-FEV-2024-23:59") estado = FALHA;
}
void TUTimestamp::testarCenarioFalha() {
    testarFalha([this] { timestamp->setTimestamp("29-FEV-2023-12:00"); }, estado);
}
int TUTimestamp::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUIdentificador::setUp() { identificador = new Identificador(); estado = SUCESSO; }
void TUIdentificador::tearDown() { delete identificador; }
void TUIdentificador::testarCenarioSucesso() {
    identificador->setIdentificador("Abc123");
    if (identificador->getIdentificador() != "Abc123") estado = FALHA;
}
void TUIdentificador::testarCenarioFalha() {
    testarFalha([this] { identificador->setIdentificador("abc12"); }, estado);
}
int TUIdentificador::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TULimite::setUp() { limite = new Limite(); estado = SUCESSO; }
void TULimite::tearDown() { delete limite; }
void TULimite::testarCenarioSucesso() {
    limite->setLimite(25);
    if (limite->getLimite() != 25) estado = FALHA;
}
void TULimite::testarCenarioFalha() {
    testarFalha([this] { limite->setLimite(26); }, estado);
}
int TULimite::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUEstado::setUp() { estado = new Estado(); resultado = SUCESSO; }
void TUEstado::tearDown() { delete estado; }
void TUEstado::testarCenarioSucesso() {
    estado->setEstado(Estado::FAZENDO);
    if (estado->getEstado() != Estado::FAZENDO) resultado = FALHA;
}
void TUEstado::testarCenarioFalha() {
    testarFalha([this] {
        estado->setEstado(static_cast<Estado::Status>(99));
    }, resultado);
}
int TUEstado::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return resultado;
}

void TUPapel::setUp() { papel = new Papel(); estado = SUCESSO; }
void TUPapel::tearDown() { delete papel; }
void TUPapel::testarCenarioSucesso() {
    papel->setCargo(Papel::Gestor);
    if (papel->getCargo() != Papel::Gestor) estado = FALHA;
}
void TUPapel::testarCenarioFalha() {
    testarFalha([this] { papel->setCargo(Papel::Nenhum); }, estado);
}
int TUPapel::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUPrioridade::setUp() { prioridade = new Prioridade(); estado = SUCESSO; }
void TUPrioridade::tearDown() { delete prioridade; }
void TUPrioridade::testarCenarioSucesso() {
    prioridade->setPrioridade(Prioridade::ALTA);
    if (prioridade->getPrioridade() != Prioridade::ALTA) estado = FALHA;
}
void TUPrioridade::testarCenarioFalha() {
    testarFalha([this] {
        prioridade->setPrioridade(static_cast<Prioridade::Nivel>(99));
    }, estado);
}
int TUPrioridade::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUTamanho::setUp() { tamanho = new Tamanho(); estado = SUCESSO; }
void TUTamanho::tearDown() { delete tamanho; }
void TUTamanho::testarCenarioSucesso() {
    tamanho->setTamanho(Tamanho::GRANDE);
    if (tamanho->getTamanho() != Tamanho::GRANDE) estado = FALHA;
}
void TUTamanho::testarCenarioFalha() {
    testarFalha([this] {
        tamanho->setTamanho(static_cast<Tamanho::Nivel>(99));
    }, estado);
}
int TUTamanho::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}
