#ifndef LIMITE_HPP
#define LIMITE_HPP

using namespace std;

/**
 * @class Limite
 * @brief Gerencia e valida um valor de limite numérico inteiro dentro de um intervalo fixo.
 *
 * Esta classe encapsula um valor inteiro de limite de Work in Progress (WIP), garantindo
 * que a quantidade de atividades no estado FAZENDO nunca sejam menor que 1 ou superior ao teto máximo definido.
 */
class Limite{
    private:
        /**
         * @brief Valor máximo permitido para o limite.
         *
         * Define o teto constante da validação, configurado estaticamente como 25.
         */
        static const int limiteMax = 25;

        /**
         * @brief O valor numérico do limite atual.
         *
         * Inicializado por padrão com o valor 0.
         */
        int limite = 0;
    public:
        /**
         * @brief Valida e define o novo valor do limite, caso dentro do intervalo permitido.
         * @param limite O novo valor inteiro a ser atribuído.
         * @throws std::invalid_argument Se o valor for menor que 1 ou maior que limiteMax ("Limite máximo atingido").
         */
        void setLimite(int limite);

        /**
         * @brief Recupera o valor do limite atualmente armazenado.
         * @return O valor inteiro do limite atual.
         */
        int  getLimite() const;

};

#endif
