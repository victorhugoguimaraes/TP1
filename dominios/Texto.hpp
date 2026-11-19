#ifndef TEXTO_HPP
#define TEXTO_HPP

#include <string>
using namespace std;

/**
 * @class Texto
 * @brief Entidade que representa um domínio de Texto.
 *
 * Esta classe armazena uma string e garante que ela siga regras específicas
 * de formatação e pontuação.
 *
 * Regras de validação:
 * - O tamanho deve ser entre 1 e 30 caracteres.
 * - Deve iniciar com uma letra maiúscula.
 * - Deve terminar obrigatoriamente com um ponto final.
 * - Não pode conter sinais de pontuação consecutivos.
 * - São permitidos apenas caracteres alfanuméricos, espaços em branco e pontuações.
 */
class Texto {
private:
    static const int TAMANHO_MAXIMO_TEXTO = 30;

    /**
     -* @brief Armazena a string validada.
     */
    string texto;

    /**
     * @brief Valida a string de acordo com as regras de formatação da classe.
     * @param texto String a ser validada.
     * @return true se o texto for válido, false caso contrário.
     */
    bool validar(const string&) const;
public:
    /**
     * @brief Define o valor do texto, caso passe pelo método de validação.
     * @param texto String que se deseja armazenar.
     * @return true se o texto for definido com sucesso.
     * @throw invalid_argument Se o texto não passar nas regras de validação.
     */
    bool setTexto(string);

    /**
     * @brief Recupera o texto armazenado.
     * @return string contendo o texto validado.
     */
    string getTexto() const;
};

#endif // TEXTO_HPP
