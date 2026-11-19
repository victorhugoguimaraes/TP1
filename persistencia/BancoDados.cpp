#include "BancoDados.hpp"
#include <stdexcept>

BancoDados::BancoDados(const string &caminho) : banco(nullptr) {
  int resultado = sqlite3_open(caminho.c_str(), &banco);

  if (resultado != SQLITE_OK) {
    string mensagem = "Nao foi possivel abrir o banco de dados";

    if (banco != nullptr) {
      mensagem = sqlite3_errmsg(banco);
    }

    if (banco != nullptr) {
      sqlite3_close(banco);
      banco = nullptr;
    }

    throw runtime_error(mensagem);
  }

  executar("PRAGMA foreign_keys = ON;");
}

sqlite3* BancoDados::obterBanco() const {
  return banco;
}

BancoDados::~BancoDados() {
  if (banco != nullptr)
    sqlite3_close(banco);
}

void BancoDados::executar(const string &sql) const {
  char *mensagemErro = nullptr;
  int resultado =
      sqlite3_exec(banco, sql.c_str(), nullptr, nullptr, &mensagemErro);

  if (resultado != SQLITE_OK) {
    string mensagem = "Erro desconhecido ao abrir o SQL";

    if (mensagemErro != nullptr) {
      mensagem = mensagemErro;
      sqlite3_free(mensagemErro);
    }

    throw runtime_error(mensagem);
  }
}
