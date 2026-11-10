#include "CntrlApresentacaoAutenticacao.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

CntrlApresentacaoAutenticacao::CntrlApresentacaoAutenticacao(ServicoAutenticacao& servico) : servico(servico) {}

bool CntrlApresentacaoAutenticacao::autenticar(Email& emailAutenticacao){
  string entradaEmail;
  string entradaSenha;

  cout<< "Email: ";
  if (!std::getline(std::cin, entradaEmail))
    return false;

  cout<< "Senha: ";
  if (!std::getline(std::cin, entradaSenha))
    return false;

  Email email;
  Senha senha;

  try { 
  email.setValor(entradaEmail);
  senha.setValor(entradaSenha);
  } catch (const invalid_argument& erro){
    cout<<"Dado invalido: " << erro.what() << '\n';
    return false;
  }
  if(!servico.autenticar(email, senha)) {
    cout <<"Email ou senha invalidos.\n";
    return false;
  }

  emailAutenticacao = email;
  cout<< "Autenticação realizada com sucesso!\n";
  return true;
}

 

