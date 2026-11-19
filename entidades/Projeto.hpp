#ifndef PROJETO_HPP
#define PROJETO_HPP

#include <vector>

#include "../dominios/Email.hpp"
#include "../dominios/Identificador.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Texto.hpp"
#include "../dominios/Timestamp.hpp"

using namespace std;

class Quadro;
class Pessoa;

class Projeto {
  private:
    Identificador identificador;
    Email gestor;
    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;
    vector<Quadro *> quadros;
    vector<Pessoa *> pessoas;

  public:
    void setIdentificador(Identificador identificador);
    Identificador getIdentificador() const;
    void setGestor(Email gestor);
    Email getGestor() const;
    void setNome(Nome nome);
    Nome getNome() const;
    void setDescricao(Texto descricao);
    Texto getDescricao() const;
    void setInicio(Timestamp inicio);
    Timestamp getInicio() const;
    void setTermino(Timestamp termino);
    Timestamp getTermino() const;

    void adicionarQuadro(Quadro *quadro);
    vector<Quadro *> getQuadros() const;
    void adicionarPessoa(Pessoa *pessoa);
    vector<Pessoa *> getPessoas() const;
};

#endif
