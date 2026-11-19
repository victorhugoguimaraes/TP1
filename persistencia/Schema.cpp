#include "Schema.hpp"

void criarTabelas(BancoDados &banco) {
    banco.executar("CREATE TABLE IF NOT EXISTS pessoa ("
                   "email TEXT PRIMARY KEY NOT NULL,"
                   "nome TEXT NOT NULL,"
                   "senha TEXT NOT NULL,"
                   "papel INTEGER NOT NULL"
                   ");");

    banco.executar("CREATE TABLE IF NOT EXISTS projeto ("
                   "identificador TEXT PRIMARY KEY NOT NULL,"
                   "gestor_email TEXT,"
                   "nome TEXT NOT NULL,"
                   "descricao TEXT NOT NULL,"
                   "inicio TEXT NOT NULL,"
                   "termino TEXT NOT NULL,"
                   "FOREIGN KEY (gestor_email) REFERENCES pessoa (email)"
                   ");");

    banco.executar("CREATE TABLE IF NOT EXISTS projeto_pessoa ("
                   "projeto_id TEXT NOT NULL,"
                   "pessoa_email TEXT NOT NULL,"
                   "PRIMARY KEY (projeto_id, pessoa_email),"
                   "FOREIGN KEY (projeto_id) REFERENCES projeto (identificador),"
                   "FOREIGN KEY (pessoa_email) REFERENCES pessoa (email)"
                   ");");

    banco.executar("CREATE TABLE IF NOT EXISTS quadro ("
                   "identificador TEXT PRIMARY KEY NOT NULL,"
                   "nome TEXT NOT NULL,"
                   "limite INTEGER NOT NULL,"
                   "projeto_id TEXT NOT NULL,"
                   "FOREIGN KEY (projeto_id) REFERENCES projeto (identificador)"
                   ");");

    banco.executar("CREATE TABLE IF NOT EXISTS cartao ("
                   "identificador TEXT PRIMARY KEY NOT NULL,"
                   "nome TEXT NOT NULL,"
                   "descricao TEXT NOT NULL,"
                   "prioridade INTEGER NOT NULL,"
                   "estado INTEGER NOT NULL,"
                   "tamanho INTEGER NOT NULL,"
                   "entrada TEXT,"
                   "inicio TEXT,"
                   "termino TEXT,"
                   "quadro_id TEXT NOT NULL,"
                   "FOREIGN KEY (quadro_id) REFERENCES quadro (identificador)"
                   ");");
}
