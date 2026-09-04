#include <iostream>
#include "dominios/Email.hpp"

using namespace std;

int main()
{
    Email e;

    const char* testes[] = {
        "usuario@dominio.com",
        "a@b.co",
        "user.name@dominio.com.br",
        "user-name@meu-dominio.com",
        "usuariodominio.com",
        "usuario@@dominio.com",
        "@dominio.com",
        "usuario@",
        ".usuario@dominio.com",
        "usuario.@dominio.com",
        "-usuario@dominio.com",
        "usuario-@dominio.com",
        "usu..ario@dominio.com",
        "usu--ario@dominio.com",
        "USUARIO@dominio.com",
        "usuario@.dominio.com",
        "usuario@dominio.com.",
        "usuario@dominio..com",
        "usuario@-dominio.com",
        "usuario@dominio-.com"
    };

    int quantidade = sizeof(testes) / sizeof(testes[0]);

    for (int i = 0; i < quantidade; i++) {
        try {
            e.setValor(testes[i]);

            cout << "[OK]     "
                 << testes[i]
                 << " -> valido"
                 << endl;
        }
        catch (...) {
            cout << "[FALHOU] "
                 << testes[i]
                 << " -> invalido"
                 << endl;
        }
    }

    return 0;
}
