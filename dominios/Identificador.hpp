#ifndef IDENTIFICADOR_HPP
#define IDENTIFICADOR_HPP
#include <string>

using namespace std;
class Identificador{
    private:
        string identificador;
        bool ehLetra(char c) const;
        bool ehDigito(char c) const;
        bool validacaoIdentificador() const;
    public:
        void setIdentificador(string identificador);
        string getIdentificador() const;
};

#endif