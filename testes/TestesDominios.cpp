#include <iostream>
#include <stdexcept>
#include <string>

#include "../dominios/Email.hpp"
#include "../dominios/Estado.hpp"
#include "../dominios/Identificador.hpp"
#include "../dominios/Limite.hpp"
#include "../dominios/Papel.hpp"
#include "../dominios/Prioridade.hpp"
#include "../dominios/Tamanho.hpp"

using namespace std;

namespace {

bool testarEmail() {
    try {
        Email email;
        email.setValor("parte-local@dominio");
        if (email.getValor() != "parte-local@dominio")
            return false;

        const string parteLocalLonga(65, 'a');
        const string dominioLongo(256, 'a');
        const string casosInvalidos[] = {
            ".local@dominio",
            "local-@dominio",
            "local..nome@dominio",
            "local.-nome@dominio",
            "local@-dominio",
            "local@dominio-",
            "local@dominio..com",
            parteLocalLonga + "@dominio",
            "local@" + dominioLongo
        };

        for (const string& valor : casosInvalidos) {
            try {
                email.setValor(valor);
                return false;
            } catch (const invalid_argument&) {
            }
        }
        return true;
    } catch (...) {
        return false;
    }
}

bool testarIdentificador() {
    try {
        Identificador identificador;
        identificador.setIdentificador("Abc123");
        if (identificador.getIdentificador() != "Abc123")
            return false;

        const string casosInvalidos[] = {
            "abc12",
            "abcdef",
            "123456",
            "abc12x"
        };

        for (const string& valor : casosInvalidos) {
            try {
                identificador.setIdentificador(valor);
                return false;
            } catch (const invalid_argument&) {
            }
        }
        return true;
    } catch (...) {
        return false;
    }
}

bool testarEstado() {
    Estado estado;
    if (estado.getEstado() != Estado::A_FAZER)
        return false;

    estado.setEstado(Estado::FAZENDO);
    if (estado.getEstado() != Estado::FAZENDO)
        return false;

    estado.setEstado(Estado::FEITO);
    return estado.getEstado() == Estado::FEITO;
}

bool testarLimite() {
    try {
        Limite limite;
        if (limite.getLimite() != 0)
            return false;

        limite.setLimite(25);
        if (limite.getLimite() != 25)
            return false;

        try {
            limite.setLimite(26);
            return false;
        } catch (const invalid_argument&) {
        }
        return true;
    } catch (...) {
        return false;
    }
}

bool testarPapel() {
    Papel papel;
    if (papel.getCargo() != Papel::Nenhum)
        return false;

    papel.setCargo(Papel::Gestor);
    if (papel.getCargo() != Papel::Gestor)
        return false;

    papel.setCargo(Papel::Desenvolvedor);
    return papel.getCargo() == Papel::Desenvolvedor;
}

bool testarPrioridade() {
    Prioridade prioridade;
    if (prioridade.getPrioridade() != Prioridade::BAIXA)
        return false;

    prioridade.setPrioridade(Prioridade::ALTA);
    return prioridade.getPrioridade() == Prioridade::ALTA;
}

bool testarTamanho() {
    Tamanho tamanho;
    if (tamanho.getTamanho() != Tamanho::PEQUENO)
        return false;

    tamanho.setTamanho(Tamanho::GRANDE);
    return tamanho.getTamanho() == Tamanho::GRANDE;
}

void imprimirResultado(const string& nome, bool passou) {
    cout << (passou ? "[OK] " : "[X]  ") << nome << endl;
}

}

int main() {
    imprimirResultado("Email", testarEmail());
    imprimirResultado("Estado", testarEstado());
    imprimirResultado("Identificador", testarIdentificador());
    imprimirResultado("Limite", testarLimite());
    imprimirResultado("Papel", testarPapel());
    imprimirResultado("Prioridade", testarPrioridade());
    imprimirResultado("Tamanho", testarTamanho());

    return 0;
}
