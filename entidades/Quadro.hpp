#ifndef QUADRO_HPP
#define QUADRO_HPP

#include <vector>

#include "../dominios/Identificador.hpp"
#include "../dominios/Limite.hpp"
#include "../dominios/Nome.hpp"

using namespace std;

class CartaoAtividade;

class Quadro {
  private:
    Identificador identificador;
    Identificador projeto;
    Nome nome;
    Limite limite;
    vector<CartaoAtividade *> cartoes;

  public:
    void setIdentificador(Identificador identificador);
    Identificador getIdentificador() const;
    void setProjeto(Identificador projeto);
    Identificador getProjeto() const;
    void setNome(Nome nome);
    Nome getNome() const;
    void setLimite(Limite limite);
    Limite getLimite() const;

    void adicionarCartao(CartaoAtividade *cartao);
    vector<CartaoAtividade *> getCartoes() const;
};

#endif
