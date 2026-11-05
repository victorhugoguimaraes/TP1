#ifndef TEXTO_HPP
#define TEXTO_HPP

#include <string>

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
    /**
     * @brief Verifica se um caractere é uma letra (maiúscula ou minúscula).
     * @param c Caractere a ser verificado.
     * @return true se for letra, false caso contrário.
     */
    bool ehLetra(char c) const;

    /**
     * @brief Verifica se um caractere é um dígito numérico (0-9).
     * @param c Caractere a ser verificado.
     * @return true se for dígito, false caso contrário.
     */
    bool ehDigito(char c) const;

    /**
     * @brief Verifica se um caractere é uma letra maiúscula.
     * @param c Caractere a ser verificado.
     * @return true se for maiúscula, false caso contrário.
     */
    bool ehMaius(char c) const;

    /**
     * @brief Verifica se um caractere é alfanumérico (letra ou dígito).
     * @param c Caractere a ser verificado.
     * @return true se for alfanumérico, false caso contrário.
     */
    bool ehAlfanumerico(char c) const;

    /**
     * @brief Verifica se um caractere é um sinal de pontuação válido (,;.:?!).
     * @param c Caractere a ser verificado.
     * @return true se for um sinal de pontuação, false caso contrário.
     */
    bool ehPontuacao(char c) const;

    /**
     -* @brief Armazena a string validada.
     */
    std::string texto;

    /**
     * @brief Valida a string de acordo com as regras de formatação da classe.
     * @param texto String a ser validada.
     * @return true se o texto for válido, false caso contrário.
     */
    bool validar(const std::string&) const;
public:
    /**
     * @brief Define o valor do texto, caso passe pelo método de validação.
     * @param texto String que se deseja armazenar.
     * @return true se o texto for definido com sucesso.
     * @throw std::invalid_argument Se o texto não passar nas regras de validação.
     */
    bool setTexto(std::string);

    /**
     * @brief Recupera o texto armazenado.
     * @return std::string contendo o texto validado.
     */
    std::string getTexto() const;
};

#endif // TEXTO_HPP
