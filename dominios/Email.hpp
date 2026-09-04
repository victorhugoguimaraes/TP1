#ifndef EMAIL_HPP
#define EMAIL_HPP
class Email {
private:
    char valor[322];
    bool ehLetra(char c) const;
    bool ehDigito(char c) const;
    bool ehAlfanumerico(char c) const;
    bool ehEspecial(char c) const;
    bool validarLocal(const char email[], int inicio, int fim) const;
    bool validarDominio(const char email[], int inicio, int fim) const;
    bool validar(const char email[]) const;
public:
    const char* getValor() const;
    void setValor(const char novoValor[]);
    bool validar(const char email[]) const;

};
#endif
