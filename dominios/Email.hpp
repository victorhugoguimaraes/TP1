#ifndef EMAIL_H
#define EMAIL_H
#include <string>

using namespace std;

class Email{
private:
    string valor;
    bool validar(const string& email) const;
public:
    void setValor(string novoValor);

    string getValor() const;
};

#endif
