#include "ContainerPessoa.hpp"

#include "../persistencia/SqliteUtil.hpp"

#include <stdexcept>

namespace {

Pessoa criarPessoa(sqlite3_stmt *comando) {
    Pessoa pessoa;

    Email email;
    email.setValor(obterTexto(comando, 0));
    pessoa.setEmail(email);

    Nome nome;
    nome.setNome(obterTexto(comando, 1));
    pessoa.setNome(nome);

    Senha senha;
    senha.setValor(obterTexto(comando, 2));
    pessoa.setSenha(senha);

    Papel papel;
    papel.setCargo(static_cast<Papel::Cargo>(sqlite3_column_int(comando, 3)));
    pessoa.setPapel(papel);

    return pessoa;
}

void verificarResultado(int resultado, sqlite3 *banco) {
    if (resultado != SQLITE_OK && resultado != SQLITE_DONE) {
        throw runtime_error(sqlite3_errmsg(banco));
    }
}

} // namespace

ContainerPessoas::ContainerPessoas(BancoDados &banco) : banco(banco) {
}

bool ContainerPessoas::inserir(const Pessoa &pessoa) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "INSERT INTO pessoa (email, nome, senha, papel) VALUES (?, ?, ?, ?);";

    int resultado = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(resultado, banco.obterBanco());

    sqlite3_bind_text(comando, 1, pessoa.getEmail().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 2, pessoa.getNome().getNome().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 3, pessoa.getSenha().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(comando, 4, pessoa.getPapel().getCargo());

    resultado = sqlite3_step(comando);
    sqlite3_finalize(comando);

    if (resultado == SQLITE_CONSTRAINT)
        return false;

    verificarResultado(resultado, banco.obterBanco());
    return true;
}

bool ContainerPessoas::buscar(const Email &email, Pessoa &resultado) const {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "SELECT email, nome, senha, papel FROM pessoa WHERE email = ?;";

    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, email.getValor().c_str(), -1, SQLITE_TRANSIENT);
    codigo = sqlite3_step(comando);

    if (codigo == SQLITE_ROW) {
        resultado = criarPessoa(comando);
        sqlite3_finalize(comando);
        return true;
    }

    sqlite3_finalize(comando);

    if (codigo == SQLITE_DONE)
        return false;

    verificarResultado(codigo, banco.obterBanco());
    return false;
}

vector<Pessoa> ContainerPessoas::listar() const {
    vector<Pessoa> resultado;
    sqlite3_stmt *comando = nullptr;
    const char *sql = "SELECT email, nome, senha, papel FROM pessoa;";

    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    while ((codigo = sqlite3_step(comando)) == SQLITE_ROW)
        resultado.push_back(criarPessoa(comando));

    sqlite3_finalize(comando);
    verificarResultado(codigo, banco.obterBanco());
    return resultado;
}

bool ContainerPessoas::editar(const Pessoa &pessoa) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "UPDATE pessoa SET nome = ?, senha = ?, papel = ? WHERE email = ?;";

    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, pessoa.getNome().getNome().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 2, pessoa.getSenha().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(comando, 3, pessoa.getPapel().getCargo());
    sqlite3_bind_text(comando, 4, pessoa.getEmail().getValor().c_str(), -1, SQLITE_TRANSIENT);

    codigo = sqlite3_step(comando);
    sqlite3_finalize(comando);
    verificarResultado(codigo, banco.obterBanco());

    return sqlite3_changes(banco.obterBanco()) > 0;
}

bool ContainerPessoas::excluir(const Email &email) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "DELETE FROM pessoa WHERE email = ?;";

    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, email.getValor().c_str(), -1, SQLITE_TRANSIENT);
    codigo = sqlite3_step(comando);
    sqlite3_finalize(comando);

    if ((codigo & 0xff) == SQLITE_CONSTRAINT)
        return false;

    verificarResultado(codigo, banco.obterBanco());

    return sqlite3_changes(banco.obterBanco()) > 0;
}
