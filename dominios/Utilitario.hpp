#ifndef UTILITARIO_H
#define UTILITARIO_H

#include <string>

using namespace std;

class Utilitario {
public:
  static bool ehLetra(char caractere);
  static bool ehLetraMinuscula(char caractere);
  static bool ehDigito(char caractere);
  static bool ehAlfanumerico(char caractere);
  static bool ehMaiuscula(char caractere);
  static bool ehEspecial(char caractere);
  static bool ehPontuacao(char caractere);
};

#endif
