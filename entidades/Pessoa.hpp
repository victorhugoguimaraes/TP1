#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <vector>

#include "../dominios/Email.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Papel.hpp"
#include "../dominios/Senha.hpp"

using namespace std;

class Projeto;
class CartaoAtividade;

class Pessoa {
    private:
        Email email;
        Nome nome;
        Senha senha;
        Papel papel;
        vector<Projeto*> projetos;
        vector<CartaoAtividade*> cartoes;

    public:
        void setEmail(Email email);
        Email getEmail() const;
        void setNome(Nome nome);
        Nome getNome() const;
        void setSenha(Senha senha);
        Senha getSenha() const;
        void setPapel(Papel papel);
        Papel getPapel() const;

        void adicionarProjeto(Projeto* projeto);
        vector<Projeto*> getProjetos() const;
        void adicionarCartao(CartaoAtividade* cartao);
        vector<CartaoAtividade*> getCartoes() const;
};

#endif
