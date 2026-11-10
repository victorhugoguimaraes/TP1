#ifndef CONTAINER_PESSOAS_H
#define CONTAINER_PESSOAS_H

#include <list> 
#include "../entidades/Pessoa.hpp"

using namespace std;

/**
 * @class ContainerPessoas
 * @brief Armazena e recupera pessoas identificadas pelo email.
 *
 * Utiliza uma lista em memoria. Os cadastros existem somente enquanto
 * o container existir e nao sao gravados em arquivo.
 */
class ContainerPessoas{
   private:
     /**
      * @brief Armazena copias das pessoas cadastradas.
      */
     list<Pessoa> pessoas;

   public: 

       /**
        * @brief Insere uma pessoa quando seu email ainda nao esta cadastrado.
        * @param pessoa Pessoa com os dados previamente validados pelos dominios.
        * @return true se inserida; false se o email ja existir.
        */
       bool inserir(const Pessoa& pessoa);

       /**
        * @brief Procura uma pessoa pelo email sem modificar o container.
        * @param email Email a ser procurado na lista.
        * @param resultado Recebe uma copia da pessoa encontrada; permanece inalterado se nao encontrada.
        * @return true se a pessoa for encontrada; false caso contrario.
        */
       bool buscar(const Email& email, Pessoa& resultado) const;

  };


#endif
