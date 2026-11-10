#include "CntrlServicoAutenticacao.hpp"

CntrlServicoAutenticacao::CntrlServicoAutenticacao(const ContainerPessoas& container) : container(container){}

bool CntrlServicoAutenticacao::autenticar(const Email& email, const Senha& senha){
  Pessoa pessoa;

  if(!container.buscar(email, pessoa))
    return false;

  return pessoa.getSenha().getValor() == senha.getValor();
}
