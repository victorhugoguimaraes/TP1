#include "ContainerCartao.hpp"

#include "../persistencia/SqliteUtil.hpp"

#include <stdexcept>

namespace {

void definirTimestamp(Timestamp &timestamp, sqlite3_stmt *comando, int coluna) {
    const unsigned char *valor = sqlite3_column_text(comando, coluna);

    if (valor != nullptr)
        timestamp.setValor(obterTexto(comando, coluna));
}

CartaoAtividade criarCartao(sqlite3_stmt *comando) {
    CartaoAtividade cartao;

    Identificador identificador;
    identificador.setIdentificador(obterTexto(comando, 0));
    cartao.setIdentificador(identificador);

    Identificador quadro;
    quadro.setIdentificador(obterTexto(comando, 9));
    cartao.setQuadro(quadro);

    Nome nome;
    nome.setNome(obterTexto(comando, 1));
    cartao.setNome(nome);

    Texto descricao;
    descricao.setTexto(obterTexto(comando, 2));
    cartao.setDescricao(descricao);

    Prioridade prioridade;
    prioridade.setPrioridade(static_cast<Prioridade::Nivel>(sqlite3_column_int(comando, 3)));
    cartao.setPrioridade(prioridade);

    Estado estado;
    estado.setEstado(static_cast<Estado::Status>(sqlite3_column_int(comando, 4)));
    cartao.setEstado(estado);

    Tamanho tamanho;
    tamanho.setTamanho(static_cast<Tamanho::Nivel>(sqlite3_column_int(comando, 5)));
    cartao.setTamanho(tamanho);

    Timestamp entrada;
    definirTimestamp(entrada, comando, 6);
    cartao.setEntrada(entrada);

    Timestamp inicio;
    definirTimestamp(inicio, comando, 7);
    cartao.setInicio(inicio);

    Timestamp termino;
    definirTimestamp(termino, comando, 8);
    cartao.setTermino(termino);

    return cartao;
}

void verificarResultado(int resultado, sqlite3 *banco) {
    if (resultado != SQLITE_OK && resultado != SQLITE_DONE)
        throw runtime_error(sqlite3_errmsg(banco));
}

void vincularTimestamp(sqlite3_stmt *comando, int indice, const Timestamp &timestamp) {
    if (timestamp.getValor().empty())
        sqlite3_bind_null(comando, indice);
    else
        sqlite3_bind_text(comando, indice, timestamp.getValor().c_str(), -1, SQLITE_TRANSIENT);
}

} // namespace

ContainerCartoes::ContainerCartoes(BancoDados &banco) : banco(banco) {
}

bool ContainerCartoes::inserir(const CartaoAtividade &cartao) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "INSERT INTO cartao (identificador, nome, descricao, prioridade, estado, tamanho, entrada, "
                      "inicio, termino, quadro_id) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
    int resultado = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(resultado, banco.obterBanco());

    sqlite3_bind_text(comando, 1, cartao.getIdentificador().getIdentificador().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 2, cartao.getNome().getNome().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 3, cartao.getDescricao().getTexto().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(comando, 4, cartao.getPrioridade().getPrioridade());
    sqlite3_bind_int(comando, 5, cartao.getEstado().getEstado());
    sqlite3_bind_int(comando, 6, cartao.getTamanho().getTamanho());
    vincularTimestamp(comando, 7, cartao.getEntrada());
    vincularTimestamp(comando, 8, cartao.getInicio());
    vincularTimestamp(comando, 9, cartao.getTermino());
    sqlite3_bind_text(comando, 10, cartao.getQuadro().getIdentificador().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(comando);
    sqlite3_finalize(comando);

    if (resultado == SQLITE_CONSTRAINT)
        return false;

    verificarResultado(resultado, banco.obterBanco());
    return true;
}

bool ContainerCartoes::buscar(const Identificador &identificador, CartaoAtividade &resultado) const {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "SELECT identificador, nome, descricao, prioridade, estado, tamanho, entrada, inicio, termino, "
                      "quadro_id FROM cartao WHERE identificador = ?;";
    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, identificador.getIdentificador().c_str(), -1, SQLITE_TRANSIENT);
    codigo = sqlite3_step(comando);

    if (codigo == SQLITE_ROW) {
        resultado = criarCartao(comando);
        sqlite3_finalize(comando);
        return true;
    }

    sqlite3_finalize(comando);

    if (codigo == SQLITE_DONE)
        return false;

    verificarResultado(codigo, banco.obterBanco());
    return false;
}

vector<CartaoAtividade> ContainerCartoes::listar() const {
    vector<CartaoAtividade> resultado;
    sqlite3_stmt *comando = nullptr;
    const char *sql = "SELECT identificador, nome, descricao, prioridade, estado, tamanho, entrada, inicio, termino, "
                      "quadro_id FROM cartao;";
    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    while ((codigo = sqlite3_step(comando)) == SQLITE_ROW)
        resultado.push_back(criarCartao(comando));

    sqlite3_finalize(comando);
    verificarResultado(codigo, banco.obterBanco());
    return resultado;
}

bool ContainerCartoes::editar(const CartaoAtividade &cartao) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "UPDATE cartao SET nome = ?, descricao = ?, prioridade = ?, estado = ?, tamanho = ?, entrada = "
                      "?, inicio = ?, termino = ?, quadro_id = ? WHERE identificador = ?;";
    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, cartao.getNome().getNome().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 2, cartao.getDescricao().getTexto().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(comando, 3, cartao.getPrioridade().getPrioridade());
    sqlite3_bind_int(comando, 4, cartao.getEstado().getEstado());
    sqlite3_bind_int(comando, 5, cartao.getTamanho().getTamanho());
    vincularTimestamp(comando, 6, cartao.getEntrada());
    vincularTimestamp(comando, 7, cartao.getInicio());
    vincularTimestamp(comando, 8, cartao.getTermino());
    sqlite3_bind_text(comando, 9, cartao.getQuadro().getIdentificador().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(comando, 10, cartao.getIdentificador().getIdentificador().c_str(), -1, SQLITE_TRANSIENT);

    codigo = sqlite3_step(comando);
    sqlite3_finalize(comando);
    verificarResultado(codigo, banco.obterBanco());
    return sqlite3_changes(banco.obterBanco()) > 0;
}

bool ContainerCartoes::excluir(const Identificador &identificador) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "DELETE FROM cartao WHERE identificador = ?;";
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

bool ContainerCartoes::mover(const Identificador &identificador, const Estado &estado) {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "UPDATE cartao SET estado = ? WHERE identificador = ?;";
    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_int(comando, 1, estado.getEstado());
    sqlite3_bind_text(comando, 2, identificador.getIdentificador().c_str(), -1, SQLITE_TRANSIENT);
    codigo = sqlite3_step(comando);
    sqlite3_finalize(comando);
    verificarResultado(codigo, banco.obterBanco());
    return sqlite3_changes(banco.obterBanco()) > 0;
}

int ContainerCartoes::contarPorEstado(const Identificador &quadro, Estado::Status estado) const {
    sqlite3_stmt *comando = nullptr;
    const char *sql = "SELECT COUNT(*) FROM cartao WHERE quadro_id = ? AND estado = ?;";
    int codigo = sqlite3_prepare_v2(banco.obterBanco(), sql, -1, &comando, nullptr);
    verificarResultado(codigo, banco.obterBanco());

    sqlite3_bind_text(comando, 1, quadro.getIdentificador().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(comando, 2, estado);
    codigo = sqlite3_step(comando);

    if (codigo != SQLITE_ROW) {
        sqlite3_finalize(comando);
        verificarResultado(codigo, banco.obterBanco());
        return 0;
    }

    int quantidade = sqlite3_column_int(comando, 0);
    sqlite3_finalize(comando);
    return quantidade;
}
