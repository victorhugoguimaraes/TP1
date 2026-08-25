#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

using namespace std;

class CodigoCliente {
    private:
        static const int LIMITE = 5;
        int valor;
        bool validar(int);
    public:
        bool setValor(int);
        int  getValor();
};

inline int CodigoCliente::getValor(){
    return valor;
    }

#endif // DOMINIOS_HPP_INCLUDED
