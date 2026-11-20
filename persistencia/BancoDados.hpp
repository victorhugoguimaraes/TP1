#ifndef BANCODADOS_H
#define BANCODADOS_H

#include "../sqlite3.h"
#include <string>

using namespace std;

class BancoDados {
  private:
    sqlite3 *banco;

  public:
    explicit BancoDados(const string &caminho);
    ~BancoDados();

    sqlite3 *obterBanco() const;

    void executar(const string &sql) const;
};

#endif
