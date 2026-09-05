#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <string>
using namespace std;

class Email {
private:
    string valor;
    bool ehLetra(char c) const;
    bool ehDigito(char c) const;
    bool ehAlfanumerico(char c) const;
    bool ehEspecial(char c) const;
    bool validarLocal(const string& email, int inicio, int fim) const;
    bool validarDominio(const string& email, int inicio, int fim) const;
public:
    string getValor() const;
    void setValor(const string& novoValor);
    bool validar(const string& email) const;

};
#endif
