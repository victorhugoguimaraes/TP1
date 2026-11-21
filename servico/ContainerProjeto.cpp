#include "ContainerProjeto.hpp"

#include "../persistencia/SqliteUtil.hpp"

#include <stdexcept>

namespace {

Projeto criarProjeto(sqlite3_stmt *comando) {
    Projeto projeto;

    Identificador identificador;
    identificador.setIdentificador(obterTexto(comando, 0));
    projeto.setIdentificador(identificador);

    const unsigned char *gestor = sqlite3_column_text(comando, 1);

    if (gestor != nullptr) {
        Email emailGestor;
        emailGestor.setValor(obterTexto(comando, 1));
        projeto.setGestor(emailGestor);
    }

    Nome nome;
    nome.setNome(obterTexto(comando, 2));
    projeto.setNome(nome);

    Texto descricao;
    descricao.setTexto(obterTexto(comando, 3));
    projeto.setDescricao(descricao);

    Timestamp inicio;
    inicio.setValor(obterTexto(comando, 4));
    projeto.setInicio(inicio);

    Timestamp termino;
    termino.setValor(obterTexto(comando, 5));
    projeto.setTermino(termino);

    return projeto;
}

void verificarResultado(int resultado, sqlite3 *banco) {
    if (resultado != SQLITE_OK && resultado != SQLITE_DONE) {
        throw runtime_error(sqlite3_errmsg(banco));
    }
}

} // namespace

ContainerProjetos::ContainerProjetos(BancoDados &banco) : banco(banco) {
}

bool ContainerProjetos::inserir(const Projeto &projeto) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "INSERT INTO projeto (identificador, gestor_email, nome, descricao, inicio, termino) VALUES (?, "
                      "?, ?, ?, ?, ?);";

    int resultado = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(resultado, banco.obterBanco());

    sqlite3_bind_text(comando, 1, projeto.getIdentificador().getIdentificador().c_str(), -1, SQLITE_TRANSIENT);

    if (projeto.getGestor().getValor().empty())
        sqlite3_bind_null(comando, 2);
    else
        sqlite3_bind_text(comando, 2, projeto.getGestor().getValor().c_str(), -1, SQLITE_TRANSIENT);

    sqlite3_bind_text(comando, 3, projeto.getNome().getNome().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 4, projeto.getDescricao().getTexto().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 5, projeto.getInicio().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 6, projeto.getTermino().getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(comando);
    sqlite3_finalize(comando);

    if (resultado == SQLITE_CONSTRAINT)
        return false;

    verificarResultado(resultado, banco.obterBanco());
    return true;
}

bool ContainerProjetos::buscar(const Identificador &identificador, Projeto &resultado) const {
    sqlite3_stmt *comando = nullptr;
    const char *sql =
        "SELECT identificador, gestor_email, nome, descricao, inicio, termino FROM projeto WHERE identificador = ?;";

    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, identificador.getIdentificador().c_str(), -1, SQLITE_TRANSIENT);
    codigo = sqlite3_step(comando);

    if (codigo == SQLITE_ROW) {
        resultado = criarProjeto(comando);
        sqlite3_finalize(comando);
        return true;
    }

    sqlite3_finalize(comando);

    if (codigo == SQLITE_DONE)
        return false;

    verificarResultado(codigo, banco.obterBanco());
    return false;
}

vector<Projeto> ContainerProjetos::listar() const {
    vector<Projeto> resultado;
    sqlite3_stmt *comando = nullptr;
    const char *sql = "SELECT identificador, gestor_email, nome, descricao, inicio, termino FROM projeto;";

    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    while ((codigo = sqlite3_step(comando)) == SQLITE_ROW)
        resultado.push_back(criarProjeto(comando));

    sqlite3_finalize(comando);
    verificarResultado(codigo, banco.obterBanco());
    return resultado;
}

bool ContainerProjetos::editar(const Projeto &projeto) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "UPDATE projeto SET nome = ?, descricao = ?, inicio = ?, termino = ? WHERE identificador = ?;";

    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, projeto.getNome().getNome().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 2, projeto.getDescricao().getTexto().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 3, projeto.getInicio().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 4, projeto.getTermino().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 5, projeto.getIdentificador().getIdentificador().c_str(), -1, SQLITE_TRANSIENT);

    codigo = sqlite3_step(comando);
    sqlite3_finalize(comando);
    verificarResultado(codigo, banco.obterBanco());

    return sqlite3_changes(banco.obterBanco()) > 0;
}

bool ContainerProjetos::adicionarPessoa(const Identificador &projeto, const Email &pessoa) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "INSERT INTO projeto_pessoa (projeto_id, pessoa_email) VALUES (?, ?);";
    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, projeto.getIdentificador().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 2, pessoa.getValor().c_str(), -1, SQLITE_TRANSIENT);
    codigo = sqlite3_step(comando);
    sqlite3_finalize(comando);

    if (codigo == SQLITE_CONSTRAINT)
        return false;

    verificarResultado(codigo, banco.obterBanco());
    return true;
}

bool ContainerProjetos::removerPessoa(const Identificador &projeto, const Email &pessoa) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "DELETE FROM projeto_pessoa WHERE projeto_id = ? AND pessoa_email = ?;";
    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, projeto.getIdentificador().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 2, pessoa.getValor().c_str(), -1, SQLITE_TRANSIENT);
    codigo = sqlite3_step(comando);
    sqlite3_finalize(comando);
    verificarResultado(codigo, banco.obterBanco());
    return sqlite3_changes(banco.obterBanco()) > 0;
}

vector<Email> ContainerProjetos::listarPessoas(const Identificador &projeto) const {
    vector<Email> resultado;
    sqlite3_stmt *comando = nullptr;
    const char *sql = "SELECT pessoa_email FROM projeto_pessoa WHERE projeto_id = ?;";
    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, projeto.getIdentificador().c_str(), -1, SQLITE_TRANSIENT);

    while ((codigo = sqlite3_step(comando)) == SQLITE_ROW) {
        Email pessoa;
        pessoa.setValor(obterTexto(comando, 0));
        resultado.push_back(pessoa);
    }

    sqlite3_finalize(comando);
    verificarResultado(codigo, banco.obterBanco());
    return resultado;
}

bool ContainerProjetos::excluir(const Identificador &identificador) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "DELETE FROM projeto WHERE identificador = ?;";

    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, identificador.getIdentificador().c_str(), -1, SQLITE_TRANSIENT);
    codigo = sqlite3_step(comando);
    sqlite3_finalize(comando);

    if ((codigo & 0xff) == SQLITE_CONSTRAINT)
        return false;

    verificarResultado(codigo, banco.obterBanco());

    return sqlite3_changes(banco.obterBanco()) > 0;
}
