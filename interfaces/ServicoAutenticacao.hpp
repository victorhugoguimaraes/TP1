#ifndef SERVICOAUTENTICACAO_H
#define SERVICOAUTENTICACAO_H

#include "../dominios/Email.hpp"
#include "../dominios/Senha.hpp"

using namespace std;

/**
 * @class ServicoAutenticacao
 * @brief Define a interface de verificacao das credenciais de uma pessoa.
 *
 * Permite que a camada de apresentacao solicite autenticacao sem depender
 * da implementacao do armazenamento de pessoas.
 */
class ServicoAutenticacao{
  public:

    /**
     * @brief Verifica as credenciais de uma pessoa cadastrada.
     * @param email Email da pessoa que deseja acessar o sistema.
     * @param senha Senha informada para autenticacao.
     * @return true se as credenciais corresponderem a um cadastro; false caso contrario.
     */
    virtual bool autenticar(
        const Email& email,
        const Senha& senha
        ) = 0;

    /**
     * @brief Permite destruir uma implementacao por meio da interface.
     */
    virtual ~ServicoAutenticacao() = default; 
}; 



#endif 
