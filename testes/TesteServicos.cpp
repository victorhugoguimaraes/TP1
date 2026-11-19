#include "TesteServicos.h"

#include "../persistencia/Schema.hpp"

using namespace std;

void TUServicos::setUp() {
    banco = new BancoDados(":memory:");
    criarTabelas(*banco);
    pessoas = new ContainerPessoas(*banco);
    projetos = new ContainerProjetos(*banco);
    quadros = new ContainerQuadros(*banco);
    cartoes = new ContainerCartoes(*banco);
    gestor = new Pessoa(criarPessoa("gestor@dominio", Papel::Gestor));
    desenvolvedor = new Pessoa(criarPessoa("dev@dominio", Papel::Desenvolvedor));
    pessoas->inserir(*gestor);
    pessoas->inserir(*desenvolvedor);
    servicoProjetoGestor = new CntrlServicoProjeto(*projetos, *gestor);
    servicoProjetoDesenvolvedor = new CntrlServicoProjeto(*projetos, *desenvolvedor);
    servicoQuadroGestor = new CntrlServicoQuadro(*quadros, *gestor);
    servicoQuadroDesenvolvedor = new CntrlServicoQuadro(*quadros, *desenvolvedor);
    servicoCartaoGestor = new CntrlServicoCartao(*cartoes, *quadros, *gestor);
    servicoCartaoDesenvolvedor = new CntrlServicoCartao(*cartoes, *quadros, *desenvolvedor);
    servicoRelatorioGestor = new CntrlServicoRelatorio(*cartoes, *gestor);
    estado = SUCESSO;
}

void TUServicos::tearDown() {
    delete servicoRelatorioGestor;
    delete servicoCartaoDesenvolvedor;
    delete servicoCartaoGestor;
    delete servicoQuadroDesenvolvedor;
    delete servicoQuadroGestor;
    delete servicoProjetoDesenvolvedor;
    delete servicoProjetoGestor;
    delete desenvolvedor;
    delete gestor;
    delete cartoes;
    delete quadros;
    delete projetos;
    delete pessoas;
    delete banco;
}

Pessoa TUServicos::criarPessoa(const string &email, Papel::Cargo cargo) {
    Pessoa pessoa;
    Email valorEmail;
    valorEmail.setValor(email);
    Nome nome;
    nome.setNome("Pessoa");
    Senha senha;
    senha.setValor("Abc12");
    Papel papel;
    papel.setCargo(cargo);
    pessoa.setEmail(valorEmail);
    pessoa.setNome(nome);
    pessoa.setSenha(senha);
    pessoa.setPapel(papel);
    return pessoa;
}

Projeto TUServicos::criarProjeto() {
    Projeto projeto;
    Identificador identificador;
    identificador.setIdentificador("PRJ001");
    Nome nome;
    nome.setNome("Projeto");
    Texto descricao;
    descricao.setTexto("Descricao.");
    Timestamp inicio;
    inicio.setValor("01-JAN-2026-08:00");
    Timestamp termino;
    termino.setValor("31-JAN-2026-18:00");
    projeto.setIdentificador(identificador);
    projeto.setGestor(gestor->getEmail());
    projeto.setNome(nome);
    projeto.setDescricao(descricao);
    projeto.setInicio(inicio);
    projeto.setTermino(termino);
    return projeto;
}

Quadro TUServicos::criarQuadro() {
    Quadro quadro;
    Identificador identificador;
    identificador.setIdentificador("QUA001");
    Limite limite;
    limite.setLimite(1);
    quadro.setIdentificador(identificador);
    quadro.setNome(criarProjeto().getNome());
    quadro.setLimite(limite);
    return quadro;
}

CartaoAtividade TUServicos::criarCartao(const string &identificadorTexto) {
    CartaoAtividade cartao;
    Identificador identificador;
    identificador.setIdentificador(identificadorTexto);
    Identificador quadro;
    quadro.setIdentificador("QUA001");
    Nome nome;
    nome.setNome("Cartao");
    Texto descricao;
    descricao.setTexto("Descricao.");
    cartao.setIdentificador(identificador);
    cartao.setQuadro(quadro);
    cartao.setNome(nome);
    cartao.setDescricao(descricao);
    return cartao;
}

void TUServicos::testarCenarioSucesso() {
    Projeto projeto = criarProjeto();
    if (!servicoProjetoGestor->criar(projeto))
        estado = FALHA;
    if (!servicoProjetoGestor->adicionarPessoa(projeto.getIdentificador(), desenvolvedor->getEmail()))
        estado = FALHA;
    if (servicoProjetoGestor->listarPessoas(projeto.getIdentificador()).size() != 1)
        estado = FALHA;

    Quadro quadro = criarQuadro();
    quadro.setProjeto(projeto.getIdentificador());
    if (!servicoQuadroGestor->criar(quadro))
        estado = FALHA;

    CartaoAtividade cartao = criarCartao("CAR001");
    if (!servicoCartaoGestor->criar(cartao))
        estado = FALHA;

    Estado fazendo;
    fazendo.setEstado(Estado::FAZENDO);
    if (!servicoCartaoDesenvolvedor->mover(cartao.getIdentificador(), fazendo))
        estado = FALHA;
    if (servicoRelatorioGestor->lerWIP(quadro.getIdentificador()) != 1)
        estado = FALHA;

    Estado feito;
    feito.setEstado(Estado::FEITO);
    if (!servicoCartaoDesenvolvedor->mover(cartao.getIdentificador(), feito))
        estado = FALHA;
    if (servicoRelatorioGestor->lerWIP(quadro.getIdentificador()) != 0)
        estado = FALHA;
    if (servicoRelatorioGestor->lerTempoCiclo(cartao.getIdentificador()) < 0)
        estado = FALHA;
    if (servicoRelatorioGestor->lerLeadTime(cartao.getIdentificador()) < 0)
        estado = FALHA;
}

void TUServicos::testarCenarioFalha() {
    Projeto projeto = criarProjeto();
    if (servicoProjetoDesenvolvedor->criar(projeto))
        estado = FALHA;

    Quadro quadro = criarQuadro();
    quadro.setProjeto(projeto.getIdentificador());
    if (servicoQuadroDesenvolvedor->criar(quadro))
        estado = FALHA;

    if (!servicoProjetoGestor->criar(projeto))
        estado = FALHA;
    if (!servicoQuadroGestor->criar(quadro))
        estado = FALHA;

    CartaoAtividade primeiro = criarCartao("CAR001");
    CartaoAtividade segundo = criarCartao("CAR002");
    if (!servicoCartaoGestor->criar(primeiro))
        estado = FALHA;
    if (!servicoCartaoGestor->criar(segundo))
        estado = FALHA;

    Estado fazendo;
    fazendo.setEstado(Estado::FAZENDO);
    if (!servicoCartaoGestor->mover(primeiro.getIdentificador(), fazendo))
        estado = FALHA;
    if (servicoCartaoGestor->mover(segundo.getIdentificador(), fazendo))
        estado = FALHA;

    Estado aFazer;
    aFazer.setEstado(Estado::A_FAZER);
    if (servicoCartaoGestor->mover(primeiro.getIdentificador(), aFazer))
        estado = FALHA;
}

int TUServicos::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    setUp();
    testarCenarioFalha();
    tearDown();
    return estado;
}
