#ifndef ESTADO_HPP
#define ESTADO_HPP

using namespace std;

class Estado{
    public:
    enum Status {
        A_FAZER,
        FAZENDO,
        FEITO
    };
        void setEstado(Status estado);
        Status getEstado() const;

    private: 
        Status estado = A_FAZER;
};

#endif