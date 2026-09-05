#ifndef TAMANHO_HPP
#define TAMANHO_HPP

using namespace std;

class Tamanho{
    public:
    enum Nivel {
        GRANDE,
        MEDIO,
        PEQUENO
    };
        void setTamanho(Nivel tamanho);
        Nivel getTamanho() const;

    private: 
        Nivel tamanho = PEQUENO;
};

#endif