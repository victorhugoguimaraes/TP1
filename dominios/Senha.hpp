#ifndef SENHA_HPP
#define SENHA_HPP

#include <string>
using namespace std;

/**
 * @class Senha
 * @brief Representa e valida uma senha alfanumérica segura com tamanho fixo.
 *
 * Esta classe encapsula uma string de senha, aplicando regras rígidas de validação
 * de caracteres e tamanho.
 */
class Senha {
    private:
        static const int TAMANHO_SENHA = 5;
        /**
         * @brief Verifica se um caractere é uma letra alfabética (a-z, A-Z).
         * @param c O caractere a ser verificado.
         * @return true se for uma letra, false caso contrário.
         */

        /**
         * @brief Verifica se um caractere é um dígito numérico (0-9).
         * @param c O caractere a ser verificado.
         * @return true se for um dígito, false caso contrário.
         */

        /**
         * @brief Armazena a string da senha que foi validada com sucesso.
         */
        string senha;

        /**
         * @brief Realiza a validação estrutural da senha fornecida.
         *
         * Critérios de validação:
         * - O tamanho total deve ser de exatamente 5 caracteres.
         * - Todos os caracteres devem ser estritamente alfanuméricos (letras ou dígitos).
         * - Deve conter obrigatoriamente pelo menos uma letra.
         * - Deve conter obrigatoriamente pelo menos um dígito numérico.
         *
         * @param senha A string da senha a ser submetida aos testes.
         * @return true se a senha cumprir todas as exigências de segurança, false caso contrário.
         */
        bool validar(const string&) const;
    public:
        /**
         * @brief Valida e atualiza a senha caso ela cumpra os requisitos.
         * @param senha A nova string de senha proposta para atribuição.
         * @return true se a operação foi concluída com sucesso.
         * @throws invalid_argument Se a string falhar nos critérios de validação ("Senha invalida").
         */
        bool setValor(string);

        /**
         * @brief Recupera a senha atualmente armazenada.
         * @return Uma cópia da string da senha validada.
         */
        string getValor() const;
    };

#endif // SENHA_HPP
