#ifndef NOME_HPP
#define NOME_HPP

#include <string>
using namespace std;

class Nome {
  private:
    static const int TAMANHO_MAXIMO_NOME = 15;
    string nome;
    bool validar(const string &) const;

  public:
    bool setNome(string);
    string getNome() const;
};

#endif // NOME_HPP
