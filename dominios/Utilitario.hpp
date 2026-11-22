#ifndef UTILITARIO_H
#define UTILITARIO_H

#include <string>

using namespace std;

/**
 * @class Utilitario
 * @brief Fornece métodos auxiliares estáticos para classificação e validação de caracteres.
 * @details Centraliza verificações léxicas utilizadas na validação sintática das classes de domínio
 * do sistema (letras, dígitos, caracteres alfanuméricos, especiais e de pontuação).
 */
class Utilitario {
  public:
    /**
     * @brief Verifica se o caractere informado é uma letra do alfabeto (maiúscula ou minúscula).
     * @param caractere Caractere a ser avaliado.
     * @return true se o caractere for uma letra (A-Z ou a-z); false caso contrário.
     */
    static bool ehLetra(char caractere);

    /**
     * @brief Verifica se o caractere informado é uma letra minúscula.
     * @param caractere Caractere a ser avaliado.
     * @return true se o caractere estiver no intervalo 'a' a 'z'; false caso contrário.
     */
    static bool ehLetraMinuscula(char caractere);

    /**
     * @brief Verifica se o caractere informado é um dígito numérico.
     * @param caractere Caractere a ser avaliado.
     * @return true se o caractere estiver no intervalo '0' a '9'; false caso contrário.
     */
    static bool ehDigito(char caractere);

    /**
     * @brief Verifica se o caractere informado é alfanumérico (letra ou dígito).
     * @param caractere Caractere a ser avaliado.
     * @return true se o caractere for letra ou dígito numérico; false caso contrário.
     */
    static bool ehAlfanumerico(char caractere);

    /**
     * @brief Verifica se o caractere informado é uma letra maiúscula.
     * @param caractere Caractere a ser avaliado.
     * @return true se o caractere estiver no intervalo 'A' a 'Z'; false caso contrário.
     */
    static bool ehMaiuscula(char caractere);

    /**
     * @brief Verifica se o caractere informado pertence ao conjunto de caracteres especiais permitidos.
     * @param caractere Caractere a ser avaliado.
     * @return true se o caractere for considerado especial pelas regras de domínio; false caso contrário.
     */
    static bool ehEspecial(char caractere);

    /**
     * @brief Verifica se o caractere informado é um sinal de pontuação válido.
     * @param caractere Caractere a ser avaliado.
     * @return true se o caractere for um sinal de pontuação aceito; false caso contrário.
     */
    static bool ehPontuacao(char caractere);
};

#endif
