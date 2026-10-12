#include "testes.h"

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

namespace {

template <typename Funcao>
void testarFalha(Funcao funcao, int& estado) {
    try {
        funcao();
        estado = -1;
    } catch (const invalid_argument&) {
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
    testarFalha([this] { email->setValor("local..invalido@dominio"); }, estado);
}
int TUEmail::run() {
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
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
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
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
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
}

void TUTexto::setUp() { texto = new Texto(); estado = SUCESSO; }
void TUTexto::tearDown() { delete texto; }
void TUTexto::testarCenarioSucesso() {
    texto->setTexto("Texto valido.");
    if (texto->getTexto() != "Texto valido.") estado = FALHA;
}
void TUTexto::testarCenarioFalha() {
    testarFalha([this] { texto->setTexto("texto invalido"); }, estado);
}
int TUTexto::run() {
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
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
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
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
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
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
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
}

void TUEstado::setUp() { estado = new Estado(); resultado = SUCESSO; }
void TUEstado::tearDown() { delete estado; }
void TUEstado::testarCenarioSucesso() {
    estado->setEstado(Estado::FAZENDO);
    if (estado->getEstado() != Estado::FAZENDO) resultado = FALHA;
}
void TUEstado::testarCenarioFalha() {
    testarFalha([this] { estado->setEstado(static_cast<Estado::Status>(99)); }, resultado);
}
int TUEstado::run() {
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return resultado;
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
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
}

void TUPrioridade::setUp() { prioridade = new Prioridade(); estado = SUCESSO; }
void TUPrioridade::tearDown() { delete prioridade; }
void TUPrioridade::testarCenarioSucesso() {
    prioridade->setPrioridade(Prioridade::ALTA);
    if (prioridade->getPrioridade() != Prioridade::ALTA) estado = FALHA;
}
void TUPrioridade::testarCenarioFalha() {
    testarFalha([this] { prioridade->setPrioridade(static_cast<Prioridade::Nivel>(99)); }, estado);
}
int TUPrioridade::run() {
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
}

void TUTamanho::setUp() { tamanho = new Tamanho(); estado = SUCESSO; }
void TUTamanho::tearDown() { delete tamanho; }
void TUTamanho::testarCenarioSucesso() {
    tamanho->setTamanho(Tamanho::GRANDE);
    if (tamanho->getTamanho() != Tamanho::GRANDE) estado = FALHA;
}
void TUTamanho::testarCenarioFalha() {
    testarFalha([this] { tamanho->setTamanho(static_cast<Tamanho::Nivel>(99)); }, estado);
}
int TUTamanho::run() {
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
}

void TUPessoa::setUp() { pessoa = new Pessoa(); estado = SUCESSO; }
void TUPessoa::tearDown() { delete pessoa; }
void TUPessoa::testarCenarioSucesso() {
    Email email; email.setValor("pessoa@dominio");
    Nome nome; nome.setNome("Pessoa Teste");
    Senha senha; senha.setValor("Abc12");
    Papel papel; papel.setCargo(Papel::Gestor);
    pessoa->setEmail(email);
    pessoa->setNome(nome);
    pessoa->setSenha(senha);
    pessoa->setPapel(papel);
    if (pessoa->getEmail().getValor() != "pessoa@dominio" ||
        pessoa->getNome().getNome() != "Pessoa Teste" ||
        pessoa->getSenha().getValor() != "Abc12" ||
        pessoa->getPapel().getCargo() != Papel::Gestor)
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
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
}

void TUProjeto::setUp() { projeto = new Projeto(); estado = SUCESSO; }
void TUProjeto::tearDown() { delete projeto; }
void TUProjeto::testarCenarioSucesso() {
    Identificador identificador; identificador.setIdentificador("Pro123");
    Nome nome; nome.setNome("Projeto");
    Texto descricao; descricao.setTexto("Descricao valida.");
    Timestamp inicio; inicio.setValor("01-JAN-2024-08:00");
    Timestamp termino; termino.setValor("31-JAN-2024-18:00");
    projeto->setIdentificador(identificador);
    projeto->setNome(nome);
    projeto->setDescricao(descricao);
    projeto->setInicio(inicio);
    projeto->setTermino(termino);
    Quadro quadro;
    projeto->adicionarQuadro(&quadro);
    if (projeto->getIdentificador().getIdentificador() != "Pro123" ||
        projeto->getNome().getNome() != "Projeto" ||
        projeto->getDescricao().getTexto() != "Descricao valida." ||
        projeto->getInicio().getValor() != "01-JAN-2024-08:00" ||
        projeto->getTermino().getValor() != "31-JAN-2024-18:00" ||
        projeto->getQuadros().size() != 1)
        estado = FALHA;
}
void TUProjeto::testarCenarioFalha() {
    Identificador identificador;
    testarFalha([&identificador] { identificador.setIdentificador("invalido"); }, estado);
}
int TUProjeto::run() {
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
}

void TUQuadro::setUp() { quadro = new Quadro(); estado = SUCESSO; }
void TUQuadro::tearDown() { delete quadro; }
void TUQuadro::testarCenarioSucesso() {
    Identificador identificador; identificador.setIdentificador("Qua123");
    Nome nome; nome.setNome("Quadro");
    Limite limite; limite.setLimite(10);
    CartaoAtividade cartao;
    quadro->setIdentificador(identificador);
    quadro->setNome(nome);
    quadro->setLimite(limite);
    quadro->adicionarCartao(&cartao);
    if (quadro->getIdentificador().getIdentificador() != "Qua123" ||
        quadro->getNome().getNome() != "Quadro" ||
        quadro->getLimite().getLimite() != 10 ||
        quadro->getCartoes().size() != 1)
        estado = FALHA;
}
void TUQuadro::testarCenarioFalha() {
    Limite limite;
    testarFalha([&limite] { limite.setLimite(0); }, estado);
}
int TUQuadro::run() {
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
}

void TUCartaoAtividade::setUp() { cartao = new CartaoAtividade(); estado = SUCESSO; }
void TUCartaoAtividade::tearDown() { delete cartao; }
void TUCartaoAtividade::testarCenarioSucesso() {
    Identificador identificador; identificador.setIdentificador("Car123");
    Nome nome; nome.setNome("Cartao");
    Texto descricao; descricao.setTexto("Tarefa valida.");
    Prioridade prioridade; prioridade.setPrioridade(Prioridade::ALTA);
    Estado estadoCartao; estadoCartao.setEstado(Estado::FAZENDO);
    Tamanho tamanho; tamanho.setTamanho(Tamanho::MEDIO);
    Timestamp entrada; entrada.setValor("01-JAN-2024-08:00");
    Timestamp inicio; inicio.setValor("01-JAN-2024-09:00");
    Timestamp termino; termino.setValor("01-JAN-2024-10:00");
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
        cartao->getEntrada().getValor() != "01-JAN-2024-08:00" ||
        cartao->getInicio().getValor() != "01-JAN-2024-09:00" ||
        cartao->getTermino().getValor() != "01-JAN-2024-10:00")
        estado = FALHA;
}
void TUCartaoAtividade::testarCenarioFalha() {
    Estado estadoInvalido;
    testarFalha([&estadoInvalido] {
        estadoInvalido.setEstado(static_cast<Estado::Status>(99));
    }, estado);
}
int TUCartaoAtividade::run() {
    setUp(); testarCenarioSucesso(); testarCenarioFalha(); tearDown(); return estado;
}

void imprimirResultado(const string& nome, int estado) {
    cout << (estado == 0 ? "[OK] " : "[X]  ") << nome << endl;
}

int main() {
    imprimirResultado("Email", TUEmail().run());
    imprimirResultado("Nome", TUNome().run());
    imprimirResultado("Senha", TUSenha().run());
    imprimirResultado("Texto", TUTexto().run());
    imprimirResultado("Timestamp", TUTimestamp().run());
    imprimirResultado("Identificador", TUIdentificador().run());
    imprimirResultado("Limite", TULimite().run());
    imprimirResultado("Estado", TUEstado().run());
    imprimirResultado("Papel", TUPapel().run());
    imprimirResultado("Prioridade", TUPrioridade().run());
    imprimirResultado("Tamanho", TUTamanho().run());
    imprimirResultado("Pessoa", TUPessoa().run());
    imprimirResultado("Projeto", TUProjeto().run());
    imprimirResultado("Quadro", TUQuadro().run());
    imprimirResultado("CartaoAtividade", TUCartaoAtividade().run());
    return 0;
}
