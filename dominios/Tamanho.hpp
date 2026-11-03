#ifndef TAMANHO_HPP
#define TAMANHO_HPP

using namespace std;

/**
 * @class Tamanho
 * @brief Gerencia e valida o dimensionamento ou escala (Grande, Médio, Pequeno) de um objeto.
 *
 * Esta classe encapsula um enumerador que representa três níveis de dimensão
 * garantindo que qualquer alteração de escala respeite estritamente as
 * opções permitidas pelo sistema.
 */
class Tamanho{
    public:
        /**
         * @enum Nivel
         * @brief Define as opções de escala ou dimensão aceitas pelo sistema.
         */
        enum Nivel {
            GRANDE,
            MEDIO,
            PEQUENO
        };

        /**
         * @brief Valida e altera a escala do tamanho contanto que pertença ao enumerador Nivel.
         * @param tamanho O novo nível do tipo Tamanho::Nivel a ser atribuído.
         * @throws std::invalid_argument Se o valor fornecido for inválido ou não mapeado ("Tamanho invalido").
         */
        void setTamanho(Nivel tamanho);

        /**
         * @brief Recupera o nível de tamanho atualmente configurado.
         * @return O nível atual armazenado no objeto (do tipo Tamanho::Nivel).
         */
        Nivel getTamanho() const;

    private:
        /**
         * @brief Armazena o nível de tamanho atual do objeto.
         *
         * O valor padrão ao instanciar a classe é definido automaticamente como Tamanho::PEQUENO.
         */
        Nivel tamanho = PEQUENO;
};

#endif
