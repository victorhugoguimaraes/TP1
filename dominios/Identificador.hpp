#ifndef IDENTIFICADOR_HPP
#define IDENTIFICADOR_HPP
#include <string>

using namespace std;

/**
 * @class Identificador
 * @brief Representa e valida um código de identificação alfanumérico com formato fixo.
 *
 * Esta classe encapsula uma string que deve seguir um padrão estrito de formatação:
 * ter exatamente 6 caracteres, onde os 3 primeiros são letras e os 3 últimos são dígitos.
 * Cada entidade (pessoa, projeto, quadro, cartão de atividade) possui um identificador único.
 */
class Identificador{
    private:
        static const int TAMANHO_IDENTIFICADOR = 6;
        static const int QUANTIDADE_LETRAS = 3;
        /**
         * @brief Armazena o texto do identificador.
         */
        string identificador;

        /**
         * @brief Realiza a validação das regras de formato do identificador interno.
         *
         * Critérios de validação:
         * - O tamanho total da string deve ser de exatamente 6 caracteres.
         * - Os índices de 0 a 2 devem conter exclusivamente letras (ehLetra).
         * - Os índices de 3 a 5 devem conter exclusivamente dígitos numéricos (ehDigito).
         *
         * @return true se o identificador atual seguir todas as regras, false caso contrário.
         */
        bool validacaoIdentificador() const;

    public:
        /**
         * @brief Tenta atualizar o identificador com um novo valor, verificando se é válido.
         * @param identificador O novo código identificador a ser validado e atribuído.
         * @throws invalid_argument Se a string não possuir 6 caracteres no formato adequado ("Identificador invalido").
         */
        void setIdentificador(string identificador);

        /**
         * @brief Recupera o identificador armazenado.
         * @return Uma cópia da string do identificador.
         */
        string getIdentificador() const;
};

#endif
