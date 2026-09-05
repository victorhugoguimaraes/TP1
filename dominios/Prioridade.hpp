#ifndef PRIORIDADE_HPP
#define PRIORIDADE_HPP

using namespace std;

class Prioridade{
    public:
    enum Nivel {
        ALTA,
        MEDIA,
        BAIXA
    };
        void setPrioridade(Nivel prioridade);
        Nivel getPrioridade() const;

    private: 
        Nivel prioridade = BAIXA;
};

#endif