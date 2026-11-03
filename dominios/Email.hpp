#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <string>
using namespace std;

/**
 * @class Email
 * @brief Representa e valida sintaticamente um endereço de e-mail.
 *
 * Esta classe encapsula uma string de e-mail, garantindo que regras estritas de
 * formatação sejam aplicadas no momento da atribuição. A validação é dividida entre
 * a parte local (antes do '@') e o domínio (depois do '@') através de análise de caracteres.
 */


class Email {
    private:
        /**
         * @brief Armazena o endereço de e-mail validado.
         */
        string valor;

        /**
         * @brief Verifica se um caractere é uma letra alfabética (a-z, A-Z).
         * @param c O caractere a ser verificado.
         * @return true se for uma letra, false caso contrário.
         */
        bool ehLetra(char c) const;

        /**
         * @brief Verifica se um caractere é um dígito numérico (0-9).
         * @param c O caractere a ser verificado.
         * @return true se for um dígito, false caso contrário.
         */
        bool ehDigito(char c) const;

        /**
         * @brief Verifica se um caractere é alfanumérico (letra ou dígito).
         * @param c O caractere a ser verificado.
         * @return true se for alfanumérico, false caso contrário.
         */
        bool ehAlfanumerico(char c) const;

        /**
         * @brief Verifica se um caractere é um caractere especial permitido na parte local ('.' ou '-').
         * @param c O caractere a ser verificado.
         * @return true se for '.' ou '-', false caso contrário.
         */
        bool ehEspecial(char c) const;

        /**
         * @brief Valida a parte local do e-mail (antes do arroba).
         *
         * Critérios de validação:
         * - O tamanho deve ser de 1 a 64 caracteres.
         * - Não pode começar nem terminar com um caractere especial.
         * - Deve conter exclusivamente caracteres alfanuméricos ou especiais permitidos.
         * - Caracteres especiais não podem ser consecutivos.
         *
         * @param email A string completa do e-mail.
         * @param inicio O índice inicial (inclusivo) da parte local.
         * @param fim O índice final (exclusivo) da parte local.
         * @return true se a parte local for válida, false caso contrário.
         */
        bool validarLocal(const string& email, int inicio, int fim) const;

        /**
         * @brief Valida a parte do domínio do e-mail (depois do arroba).
         *
         * Critérios de validação:
         * - O tamanho total do domínio deve ser de 1 a 255 caracteres.
         * - Os subdomínios (partes separadas por pontos) não podem ser vazios.
         * - Os subdomínios não podem começar nem terminar com hífen.
         * - Os subdomínios devem conter exclusivamente caracteres alfanuméricos ou hifens.
         *
         * @param email A string completa do e-mail.
         * @param inicio O índice inicial (inclusivo) do domínio.
         * @param fim O índice final (exclusivo) do domínio.
         * @return true se o domínio for válido, false caso contrário.
         */
        bool validarDominio(const string& email, int inicio, int fim) const;

        /**
         * @brief Coordena a validação estrutural completa do e-mail.
         *
         * Garante que existe exatamente um caractere '@', separa a string nas duas
         * partes principais e realiza validarLocal() e validarDominio().
         *
         * @param email O endereço de e-mail completo que será validado.
         * @return true se o e-mail cumprir todas as regras estruturais, false caso contrário.
         */
        bool validar(const string& email) const;

    public:

        /**
         * @brief Valida e atualiza o endereço de e-mail.
         * @param valor O novo e-mail a ser atribuído.
         * @throws std::invalid_argument Se a string falhar nas restrições de validação ("Email invalido").
         */
        void setValor(string valor);

        /**
         * @brief Recupera o e-mail atualmente armazenado.
         * @return Uma cópia da string do e-mail validado.
         */
        string getValor() const;
};
#endif
