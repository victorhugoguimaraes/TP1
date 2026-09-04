#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

using namespace std;

class Senha{
    private:
        static const int LIMITE = 5;
        string valor;
        bool validar(const string&) const;
    public:
        bool setValor(string);
        string getValor() const;
};

#endif // SENHA_HPP_INCLUDED
