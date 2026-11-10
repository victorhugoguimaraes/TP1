#include "ContainerPessoa.hpp"

bool ContainerPessoas::inserir(const Pessoa& pessoa) {
  for(const Pessoa& cadastrada : pessoas) {
    if (cadastrada.getEmail().getValor() == pessoa.getEmail().getValor())
      return false; 
  }

  pessoas.push_back(pessoa);
  return true;
}

bool ContainerPessoas::buscar(const Email& email, Pessoa& resultado) const{ 
  for (const Pessoa& cadastrada : pessoas){
    if (cadastrada.getEmail().getValor() == email.getValor()){
      resultado = cadastrada;
      return true;
    }
  }
  return false;
}
