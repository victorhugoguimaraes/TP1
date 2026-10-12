#ifndef CARTAO_ATIVIDADE_HPP
#define CARTAO_ATIVIDADE_HPP

#include "../dominios/Estado.hpp"
#include "../dominios/Identificador.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Prioridade.hpp"
#include "../dominios/Tamanho.hpp"
#include "../dominios/Texto.hpp"
#include "../dominios/Timestamp.hpp"

using namespace std;

class CartaoAtividade {
    private:
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Prioridade prioridade;
        Estado estado;
        Tamanho tamanho;
        Timestamp entrada;
        Timestamp inicio;
        Timestamp termino;

    public:
        void setIdentificador(Identificador identificador);
        Identificador getIdentificador() const;
        void setNome(Nome nome);
        Nome getNome() const;
        void setDescricao(Texto descricao);
        Texto getDescricao() const;
        void setPrioridade(Prioridade prioridade);
        Prioridade getPrioridade() const;
        void setEstado(Estado estado);
        Estado getEstado() const;
        void setTamanho(Tamanho tamanho);
        Tamanho getTamanho() const;
        void setEntrada(Timestamp entrada);
        Timestamp getEntrada() const;
        void setInicio(Timestamp inicio);
        Timestamp getInicio() const;
        void setTermino(Timestamp termino);
        Timestamp getTermino() const;
};

using Cartao = CartaoAtividade;

#endif
