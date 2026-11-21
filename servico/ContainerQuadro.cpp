#include "ContainerQuadro.hpp"

#include "../persistencia/SqliteUtil.hpp"

#include <stdexcept>

namespace {

Quadro criarQuadro(sqlite3_stmt *comando) {
    Quadro quadro;

    Identificador identificador;
    identificador.setIdentificador(obterTexto(comando, 0));
    quadro.setIdentificador(identificador);

    Identificador projeto;
    projeto.setIdentificador(obterTexto(comando, 3));
    quadro.setProjeto(projeto);

    Nome nome;
    nome.setNome(obterTexto(comando, 1));
    quadro.setNome(nome);

    Limite limite;
    limite.setLimite(sqlite3_column_int(comando, 2));
    quadro.setLimite(limite);

    return quadro;
}

void verificarResultado(int resultado, sqlite3 *banco) {
    if (resultado != SQLITE_OK && resultado != SQLITE_DONE)
        throw runtime_error(sqlite3_errmsg(banco));
}

} // namespace

ContainerQuadros::ContainerQuadros(BancoDados &banco) : banco(banco) {
}

bool ContainerQuadros::inserir(const Quadro &quadro) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "INSERT INTO quadro (identificador, nome, limite, projeto_id) VALUES (?, ?, ?, ?);";
    int resultado = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(resultado, banco.obterBanco());

    sqlite3_bind_text(comando, 1, quadro.getIdentificador().getIdentificador().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 2, quadro.getNome().getNome().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(comando, 3, quadro.getLimite().getLimite());
    sqlite3_bind_text(comando, 4, quadro.getProjeto().getIdentificador().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(comando);
    sqlite3_finalize(comando);

    if (resultado == SQLITE_CONSTRAINT)
        return false;

    verificarResultado(resultado, banco.obterBanco());
    return true;
}

bool ContainerQuadros::buscar(const Identificador &identificador, Quadro &resultado) const {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "SELECT identificador, nome, limite, projeto_id FROM quadro WHERE identificador = ?;";
    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, identificador.getIdentificador().c_str(), -1, SQLITE_TRANSIENT);
    codigo = sqlite3_step(comando);

    if (codigo == SQLITE_ROW) {
        resultado = criarQuadro(comando);
        sqlite3_finalize(comando);
        return true;
    }

    sqlite3_finalize(comando);

    if (codigo == SQLITE_DONE)
        return false;

    verificarResultado(codigo, banco.obterBanco());
    return false;
}

vector<Quadro> ContainerQuadros::listar() const {
    vector<Quadro> resultado;
    sqlite3_stmt *comando = nullptr;
    const char *sql = "SELECT identificador, nome, limite, projeto_id FROM quadro;";
    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    while ((codigo = sqlite3_step(comando)) == SQLITE_ROW)
        resultado.push_back(criarQuadro(comando));

    sqlite3_finalize(comando);
    verificarResultado(codigo, banco.obterBanco());
    return resultado;
}

bool ContainerQuadros::editar(const Quadro &quadro) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "UPDATE quadro SET nome = ?, limite = ?, projeto_id = ? WHERE identificador = ?;";
    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, quadro.getNome().getNome().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(comando, 2, quadro.getLimite().getLimite());
    sqlite3_bind_text(comando, 3, quadro.getProjeto().getIdentificador().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 4, quadro.getIdentificador().getIdentificador().c_str(), -1, SQLITE_TRANSIENT);

    codigo = sqlite3_step(comando);
    sqlite3_finalize(comando);
    verificarResultado(codigo, banco.obterBanco());
    return sqlite3_changes(banco.obterBanco()) > 0;
}

bool ContainerQuadros::excluir(const Identificador &identificador) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "DELETE FROM quadro WHERE identificador = ?;";
    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, identificador.getIdentificador().c_str(), -1, SQLITE_TRANSIENT);
    codigo = sqlite3_step(comando);
    sqlite3_finalize(comando);

    if (codigo == SQLITE_CONSTRAINT || codigo == SQLITE_CONSTRAINT_FOREIGNKEY)
        return false;

    verificarResultado(codigo, banco.obterBanco());
    return sqlite3_changes(banco.obterBanco()) > 0;
}
