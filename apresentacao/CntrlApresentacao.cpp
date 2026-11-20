#include "CntrlApresentacao.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

namespace {

string cargoTexto(Papel::Cargo cargo) {
    if (cargo == Papel::Gestor)
        return "Gestor";
    if (cargo == Papel::Desenvolvedor)
        return "Desenvolvedor";
    return "Nenhum";
}

string estadoTexto(Estado::Status estado) {
    if (estado == Estado::FAZENDO)
        return "FAZENDO";
    if (estado == Estado::FEITO)
        return "FEITO";
    return "A FAZER";
}

bool criarEmail(const string &texto, Email &email) {
    try {
        email.setValor(texto);
        return true;
    } catch (const invalid_argument &erro) {
        cout << "Dado invalido: " << erro.what() << endl;
        return false;
    }
}

void informarResultado(bool sucesso, const string &sucessoTexto, const string &falhaTexto) {
    if (sucesso)
        cout << sucessoTexto << endl;
    else
        cout << falhaTexto << endl;
}

}

CntrlApresentacao::CntrlApresentacao(ServicoPessoa &pessoas, ServicoProjeto &projetos, ServicoQuadro &quadros,
                                     ServicoCartao &cartoes, ServicoRelatorio &relatorios,
                                     CntrlApresentacaoAutenticacao &autenticacao, Pessoa &usuario)
    : pessoas(pessoas), projetos(projetos), quadros(quadros), cartoes(cartoes), relatorios(relatorios),
      autenticacao(autenticacao), usuario(usuario) {
}

bool CntrlApresentacao::lerTexto(const string &mensagem, string &valor) {
    cout << mensagem;
    return static_cast<bool>(getline(cin, valor));
}

bool CntrlApresentacao::lerInteiro(const string &mensagem, int &valor) {
    string texto;

    if (!lerTexto(mensagem, texto))
        return false;

    stringstream entrada(texto);
    entrada >> valor;

    if (entrada.fail()) {
        cout << "Entrada invalida: informe um numero.\n";
        return false;
    }

    return true;
}

bool CntrlApresentacao::lerEmail(Email &email) {
    string valor;

    while (true) {
        if (!lerTexto("Email: ", valor))
            return false;
        if (criarEmail(valor, email))
            return true;
    }
}

bool CntrlApresentacao::lerIdentificador(Identificador &identificador, const string &mensagem) {
    string valor;

    while (true) {
        if (!lerTexto(mensagem, valor))
            return false;
        try {
            identificador.setIdentificador(valor);
            return true;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
}

bool CntrlApresentacao::lerPessoa(Pessoa &pessoa, bool incluirEmail) {
    string valor;
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;
    int cargo;

    if (incluirEmail) {
        while (true) {
            if (!lerTexto("Email: ", valor))
                return false;
            if (criarEmail(valor, email))
                break;
        }
        pessoa.setEmail(email);
    }

    while (true) {
        try {
            if (!lerTexto("Nome: ", valor))
                return false;
            nome.setNome(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }

    while (true) {
        try {
            if (!lerTexto("Senha: ", valor))
                return false;
            senha.setValor(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }

    while (true) {
        if (!lerInteiro("Cargo (1-Gestor, 2-Desenvolvedor): ", cargo))
            return false;
        try {
            if (cargo == 1)
                papel.setCargo(Papel::Gestor);
            else if (cargo == 2)
                papel.setCargo(Papel::Desenvolvedor);
            else
                throw invalid_argument("Cargo invalido");
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }

    pessoa.setNome(nome);
    pessoa.setSenha(senha);
    pessoa.setPapel(papel);
    return true;
}

bool CntrlApresentacao::lerProjeto(Projeto &projeto) {
    string valor;
    Identificador identificador;
    Email gestor;
    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;

    while (true) {
        try {
            if (!lerTexto("Identificador: ", valor))
                return false;
            identificador.setIdentificador(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    while (true) {
        if (!lerTexto("Email do gestor: ", valor))
            return false;
        if (criarEmail(valor, gestor))
            break;
    }
    while (true) {
        try {
            if (!lerTexto("Nome: ", valor))
                return false;
            nome.setNome(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    while (true) {
        try {
            if (!lerTexto("Descricao: ", valor))
                return false;
            descricao.setTexto(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    while (true) {
        try {
            if (!lerTexto("Inicio (DD-MES-AAAA-HH:MM): ", valor))
                return false;
            inicio.setValor(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    while (true) {
        try {
            if (!lerTexto("Termino (DD-MES-AAAA-HH:MM): ", valor))
                return false;
            termino.setValor(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    projeto.setIdentificador(identificador);
    projeto.setGestor(gestor);
    projeto.setNome(nome);
    projeto.setDescricao(descricao);
    projeto.setInicio(inicio);
    projeto.setTermino(termino);
    return true;
}

bool CntrlApresentacao::lerQuadro(Quadro &quadro) {
    string valor;
    Identificador identificador;
    Identificador projeto;
    Nome nome;
    Limite limite;
    int valorLimite;

    while (true) {
        try {
            if (!lerTexto("Identificador: ", valor))
                return false;
            identificador.setIdentificador(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    while (true) {
        try {
            if (!lerTexto("Identificador do projeto: ", valor))
                return false;
            projeto.setIdentificador(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    while (true) {
        try {
            if (!lerTexto("Nome: ", valor))
                return false;
            nome.setNome(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    while (true) {
        try {
            if (!lerInteiro("Limite WIP: ", valorLimite))
                return false;
            limite.setLimite(valorLimite);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    quadro.setIdentificador(identificador);
    quadro.setProjeto(projeto);
    quadro.setNome(nome);
    quadro.setLimite(limite);
    return true;
}

bool CntrlApresentacao::lerCartao(CartaoAtividade &cartao) {
    string valor;
    Identificador identificador;
    Identificador quadro;
    Nome nome;
    Texto descricao;
    Prioridade prioridade;
    Tamanho tamanho;
    int opcao;

    while (true) {
        try {
            if (!lerTexto("Identificador: ", valor))
                return false;
            identificador.setIdentificador(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    while (true) {
        try {
            if (!lerTexto("Identificador do quadro: ", valor))
                return false;
            quadro.setIdentificador(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    while (true) {
        try {
            if (!lerTexto("Nome: ", valor))
                return false;
            nome.setNome(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    while (true) {
        try {
            if (!lerTexto("Descricao: ", valor))
                return false;
            descricao.setTexto(valor);
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    while (true) {
        try {
            if (!lerInteiro("Prioridade (1-Alta, 2-Media, 3-Baixa): ", opcao))
                return false;
            if (opcao == 1)
                prioridade.setPrioridade(Prioridade::ALTA);
            else if (opcao == 2)
                prioridade.setPrioridade(Prioridade::MEDIA);
            else if (opcao == 3)
                prioridade.setPrioridade(Prioridade::BAIXA);
            else
                throw invalid_argument("Prioridade invalida");
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    while (true) {
        try {
            if (!lerInteiro("Tamanho (1-Grande, 2-Medio, 3-Pequeno): ", opcao))
                return false;
            if (opcao == 1)
                tamanho.setTamanho(Tamanho::GRANDE);
            else if (opcao == 2)
                tamanho.setTamanho(Tamanho::MEDIO);
            else if (opcao == 3)
                tamanho.setTamanho(Tamanho::PEQUENO);
            else
                throw invalid_argument("Tamanho invalido");
            break;
        } catch (const invalid_argument &erro) {
            cout << "Dado invalido: " << erro.what() << endl;
        }
    }
    cartao.setIdentificador(identificador);
    cartao.setQuadro(quadro);
    cartao.setNome(nome);
    cartao.setDescricao(descricao);
    cartao.setPrioridade(prioridade);
    cartao.setTamanho(tamanho);
    return true;
}

void CntrlApresentacao::listarPessoas() {
    vector<Pessoa> lista = pessoas.listar();
    for (const Pessoa &pessoa : lista)
        cout << pessoa.getEmail().getValor() << " - " << pessoa.getNome().getNome() << " - "
             << cargoTexto(pessoa.getPapel().getCargo()) << endl;
}

void CntrlApresentacao::listarProjetos(ServicoProjeto &servico) {
    vector<Projeto> lista = servico.listar();
    for (const Projeto &projeto : lista)
        cout << projeto.getIdentificador().getIdentificador() << " - " << projeto.getNome().getNome()
             << " - gestor: " << projeto.getGestor().getValor() << endl;
}

void CntrlApresentacao::listarQuadros(ServicoQuadro &servico) {
    vector<Quadro> lista = servico.listar();
    for (const Quadro &quadro : lista)
        cout << quadro.getIdentificador().getIdentificador() << " - " << quadro.getNome().getNome()
             << " - limite: " << quadro.getLimite().getLimite() << endl;
}

void CntrlApresentacao::listarCartoes(ServicoCartao &servico) {
    vector<CartaoAtividade> lista = servico.listar();
    for (const CartaoAtividade &cartao : lista)
        cout << cartao.getIdentificador().getIdentificador() << " - " << cartao.getNome().getNome() << " - "
             << estadoTexto(cartao.getEstado().getEstado()) << endl;
}

void CntrlApresentacao::mostrarPessoa(const Pessoa &pessoa) {
    cout << "Email: " << pessoa.getEmail().getValor() << endl;
    cout << "Nome: " << pessoa.getNome().getNome() << endl;
    cout << "Cargo: " << cargoTexto(pessoa.getPapel().getCargo()) << endl;
}

void CntrlApresentacao::mostrarProjeto(const Projeto &projeto) {
    cout << "Identificador: " << projeto.getIdentificador().getIdentificador() << endl;
    cout << "Gestor: " << projeto.getGestor().getValor() << endl;
    cout << "Nome: " << projeto.getNome().getNome() << endl;
    cout << "Descricao: " << projeto.getDescricao().getTexto() << endl;
    cout << "Inicio: " << projeto.getInicio().getValor() << endl;
    cout << "Termino: " << projeto.getTermino().getValor() << endl;
}

void CntrlApresentacao::mostrarQuadro(const Quadro &quadro) {
    cout << "Identificador: " << quadro.getIdentificador().getIdentificador() << endl;
    cout << "Projeto: " << quadro.getProjeto().getIdentificador() << endl;
    cout << "Nome: " << quadro.getNome().getNome() << endl;
    cout << "Limite WIP: " << quadro.getLimite().getLimite() << endl;
}

void CntrlApresentacao::mostrarCartao(const CartaoAtividade &cartao) {
    cout << "Identificador: " << cartao.getIdentificador().getIdentificador() << endl;
    cout << "Quadro: " << cartao.getQuadro().getIdentificador() << endl;
    cout << "Nome: " << cartao.getNome().getNome() << endl;
    cout << "Descricao: " << cartao.getDescricao().getTexto() << endl;
    cout << "Estado: " << estadoTexto(cartao.getEstado().getEstado()) << endl;
    cout << "Entrada: " << cartao.getEntrada().getValor() << endl;
    cout << "Inicio: " << cartao.getInicio().getValor() << endl;
    cout << "Termino: " << cartao.getTermino().getValor() << endl;
}

void CntrlApresentacao::menuPessoa() {
    int opcao;
    if (!lerInteiro("1-Criar 2-Listar 3-Consultar 4-Editar 5-Excluir 0-Voltar: ", opcao))
        return;
    if (opcao == 1) {
        Pessoa pessoa;
        if (lerPessoa(pessoa, true))
            informarResultado(pessoas.criar(pessoa), "Pessoa criada.", "Falha ao criar pessoa.");
    } else if (opcao == 2)
        listarPessoas();
    else if (opcao == 3) {
        Email email;
        if (lerEmail(email)) {
            Pessoa pessoa;
            if (pessoas.consultar(email, pessoa))
                mostrarPessoa(pessoa);
            else
                cout << "Pessoa nao encontrada." << endl;
        }
    } else if (opcao == 4) {
        Email email;
        Pessoa pessoa;
        if (lerEmail(email) && pessoas.consultar(email, pessoa)) {
            cout << "Novos dados da pessoa:\n";
            if (lerPessoa(pessoa, false))
                informarResultado(pessoas.editar(pessoa), "Pessoa editada.", "Falha ao editar pessoa.");
        } else {
            cout << "Pessoa nao encontrada." << endl;
        }
    } else if (opcao == 5) {
        Email email;
        if (lerEmail(email))
            informarResultado(pessoas.excluir(email), "Pessoa excluida.", "Pessoa nao encontrada.");
    }
}

void CntrlApresentacao::menuProjeto(const Pessoa &usuario) {
    int opcao;
    if (!lerInteiro("1-Criar 2-Listar 3-Consultar 4-Editar 5-Excluir 6-Adicionar pessoa 7-Remover pessoa 8-Listar pessoas 0-Voltar: ", opcao))
        return;
    if (opcao == 1) {
        Projeto projeto;
        if (lerProjeto(projeto))
            informarResultado(projetos.criar(projeto), "Projeto criado.", "Falha ao criar projeto.");
    } else if (opcao == 2)
        listarProjetos(projetos);
    else if (opcao == 3) {
        Identificador id;
        if (lerIdentificador(id, "Identificador: ")) {
            Projeto projeto;
            if (projetos.consultar(id, projeto))
                mostrarProjeto(projeto);
            else
                cout << "Projeto nao encontrado." << endl;
        }
    } else if (opcao == 4) {
        Identificador id;
        if (lerIdentificador(id, "Identificador do projeto: ")) {
            Projeto projeto;
            if (projetos.consultar(id, projeto)) {
                cout << "Novos dados do projeto (o identificador sera mantido).\n";
                if (lerProjeto(projeto)) {
                    projeto.setIdentificador(id);
                    informarResultado(projetos.editar(projeto), "Projeto editado.", "Falha ao editar projeto.");
                }
            } else {
                cout << "Projeto nao encontrado." << endl;
            }
        }
    } else if (opcao == 5) {
        Identificador id;
        if (lerIdentificador(id, "Identificador: "))
            informarResultado(projetos.excluir(id), "Projeto excluido.", "Projeto nao encontrado.");
    } else if (opcao == 6) {
        Identificador id;
        Email email;
        if (lerIdentificador(id, "Identificador do projeto: ") && lerEmail(email))
            informarResultado(projetos.adicionarPessoa(id, email), "Pessoa associada.", "Falha ao associar.");
    } else if (opcao == 7) {
        Identificador id;
        Email email;
        if (lerIdentificador(id, "Identificador do projeto: ") && lerEmail(email))
            informarResultado(projetos.removerPessoa(id, email), "Pessoa removida.", "Falha ao remover pessoa.");
    } else if (opcao == 8) {
        Identificador id;
        if (lerIdentificador(id, "Identificador do projeto: ")) {
            vector<Email> lista = projetos.listarPessoas(id);
            for (const Email &email : lista)
                cout << email.getValor() << endl;
        }
    }
    (void)usuario;
}

void CntrlApresentacao::menuQuadro(const Pessoa &usuario) {
    int opcao;
    if (!lerInteiro("1-Criar 2-Listar 3-Consultar 4-Editar 5-Excluir 0-Voltar: ", opcao))
        return;
    if (opcao == 1) {
        Quadro quadro;
        if (lerQuadro(quadro))
            informarResultado(quadros.criar(quadro), "Quadro criado.", "Falha ao criar quadro.");
    } else if (opcao == 2)
        listarQuadros(quadros);
    else if (opcao == 3) {
        Identificador id;
        if (lerIdentificador(id, "Identificador: ")) {
            Quadro quadro;
            if (quadros.consultar(id, quadro))
                mostrarQuadro(quadro);
            else
                cout << "Quadro nao encontrado." << endl;
        }
    } else if (opcao == 4) {
        Identificador id;
        if (lerIdentificador(id, "Identificador do quadro: ")) {
            Quadro quadro;
            if (quadros.consultar(id, quadro)) {
                cout << "Novos dados do quadro (o identificador sera mantido).\n";
                if (lerQuadro(quadro)) {
                    quadro.setIdentificador(id);
                    informarResultado(quadros.editar(quadro), "Quadro editado.", "Falha ao editar quadro.");
                }
            } else {
                cout << "Quadro nao encontrado." << endl;
            }
        }
    } else if (opcao == 5) {
        Identificador id;
        if (lerIdentificador(id, "Identificador: "))
            informarResultado(quadros.excluir(id), "Quadro excluido.", "Quadro nao encontrado.");
    }
    (void)usuario;
}

void CntrlApresentacao::menuCartao(const Pessoa &usuario) {
    int opcao;
    if (!lerInteiro("1-Criar 2-Listar 3-Consultar 4-Editar 5-Mover 6-Excluir 0-Voltar: ", opcao))
        return;
    if (opcao == 1) {
        CartaoAtividade cartao;
        if (lerCartao(cartao))
            informarResultado(cartoes.criar(cartao), "Cartao criado.", "Falha ao criar cartao.");
    } else if (opcao == 2)
        listarCartoes(cartoes);
    else if (opcao == 3) {
        Identificador id;
        if (lerIdentificador(id, "Identificador: ")) {
            CartaoAtividade cartao;
            if (cartoes.consultar(id, cartao))
                mostrarCartao(cartao);
            else
                cout << "Cartao nao encontrado." << endl;
        }
    } else if (opcao == 4) {
        Identificador id;
        if (lerIdentificador(id, "Identificador do cartao: ")) {
            CartaoAtividade cartao;
            if (cartoes.consultar(id, cartao)) {
                cout << "Novos dados do cartao (o identificador sera mantido).\n";
                if (lerCartao(cartao)) {
                    cartao.setIdentificador(id);
                    informarResultado(cartoes.editar(cartao), "Cartao editado.", "Falha ao editar cartao.");
                }
            } else {
                cout << "Cartao nao encontrado." << endl;
            }
        }
    } else if (opcao == 5) {
        int estado;
        Identificador id;
        Estado novo;
        if (lerIdentificador(id, "Identificador: ") && lerInteiro("Estado (1-Fazendo, 2-Feito): ", estado)) {
            if (estado == 1)
                novo.setEstado(Estado::FAZENDO);
            else if (estado == 2)
                novo.setEstado(Estado::FEITO);
            else
                return;
            informarResultado(cartoes.mover(id, novo), "Cartao movido.", "Movimento recusado.");
        }
    } else if (opcao == 6) {
        Identificador id;
        if (lerIdentificador(id, "Identificador: "))
            informarResultado(cartoes.excluir(id), "Cartao excluido.", "Cartao nao encontrado.");
    }
    (void)usuario;
}

void CntrlApresentacao::menuRelatorio(const Pessoa &usuario) {
    Identificador id;
    int opcao;
    if (!lerInteiro("1-Tempo ciclo 2-Ciclo medio 3-Lead time 4-Lead medio 5-WIP 0-Voltar: ", opcao))
        return;
    if (!lerIdentificador(id, "Identificador do cartao/quadro: "))
        return;
    if (opcao == 1)
        cout << "Tempo de ciclo: " << relatorios.lerTempoCiclo(id) << " minutos\n";
    else if (opcao == 2)
        cout << "Tempo de ciclo medio: " << relatorios.lerTempoCicloMedio(id) << " minutos\n";
    else if (opcao == 3)
        cout << "Lead time: " << relatorios.lerLeadTime(id) << " minutos\n";
    else if (opcao == 4)
        cout << "Lead time medio: " << relatorios.lerLeadTimeMedio(id) << " minutos\n";
    else if (opcao == 5)
        cout << "WIP: " << relatorios.lerWIP(id) << "\n";
    (void)usuario;
}

bool CntrlApresentacao::autenticar(Pessoa &usuario) {
    Email email;
    if (!autenticacao.autenticar(email))
        return false;
    return pessoas.consultar(email, usuario);
}

bool CntrlApresentacao::cadastrarPessoaInicial() {
    Pessoa pessoa;
    if (!lerPessoa(pessoa, true))
        return false;
    return pessoas.criar(pessoa);
}

void CntrlApresentacao::executar() {
    while (true) {
        interfaceTerminal.limpar();
        interfaceTerminal.cabecalho("QUADRO KANBAN", "Escolha uma opcao para continuar");
        cout << "\n1 - Cadastrar pessoa\n2 - Entrar\n0 - Sair\n";
        int opcao;
        if (!lerInteiro("Opcao: ", opcao))
            return;
        if (opcao == 0)
            return;
        if (opcao == 1)
            informarResultado(cadastrarPessoaInicial(), "Pessoa criada.", "Falha ao criar pessoa.");
        else if (opcao == 2) {
            interfaceTerminal.limpar();
            interfaceTerminal.cabecalho("AUTENTICACAO", "Informe suas credenciais");
            if (!autenticar(usuario))
                continue;
            while (true) {
                interfaceTerminal.limpar();
                interfaceTerminal.cabecalho("MENU PRINCIPAL", "Usuario: " + usuario.getNome().getNome() + " (" +
                                                                  cargoTexto(usuario.getPapel().getCargo()) + ")");
                cout << "\n1 - Pessoas\n2 - Projetos\n3 - Quadros\n4 - Cartoes\n5 - Relatorios\n0 - Sair\n";
                if (!lerInteiro("Opcao: ", opcao) || opcao == 0)
                    break;
                if (opcao == 1)
                    menuPessoa();
                else if (opcao == 2)
                    menuProjeto(usuario);
                else if (opcao == 3)
                    menuQuadro(usuario);
                else if (opcao == 4)
                    menuCartao(usuario);
                else if (opcao == 5)
                    menuRelatorio(usuario);
            }
        }
    }
}
