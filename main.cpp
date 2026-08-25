#include <iostream>
#include "dominios.hpp"
using namespace std;

/*
int main() {

  CodigoCliente a; // Criar objeto da classe domínio.
  int valor;
  cout << "Fale o valor: ";
  cin >> valor; // Ler valor a partir da entrada padrão.
  if(a.setValor(valor))
    cout << a.getValor();
  else
    cout<< "Valor nao apresentado";
// Armazenar valor no objeto.
// Se o valor for válido, apresentar valor armazenado no objeto.
// Se o valor for inválido, informar que o valor não foi armazenado.
return 0;
}
*/


int main(){
  CodigoCliente* a = new CodigoCliente();
  int valor;
  cout << "Fale o valor: ";
  cin >> valor; // Ler valor a partir da entrada padrão.
  if(a->setValor(valor))
    cout << a->getValor();
  else
    cout<< "Valor nao apresentado";

  delete a;
return 0;}
