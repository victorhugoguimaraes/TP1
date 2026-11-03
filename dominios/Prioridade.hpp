#ifndef PRIORIDADE_HPP
#define PRIORIDADE_HPP

using namespace std;

/**
 * @class Prioridade
 * @brief Gerencia e valida o nível de urgência ou importância de uma tarefa ou evento.
 *
 * Esta classe encapsula um enumerador que representa três níveis de prioridade fixos
 * (ALTA, MEDIA, BAIXA), garantindo que qualquer modificação de estado respeite as
 * opções permitidas.
 */
class Prioridade{
    public:
        /**
         * @enum Nivel
         * @brief Define os níveis de urgência aceitos pelo sistema.
         */
        enum Nivel {
            ALTA,
            MEDIA,
            BAIXA
        };

        /**
         * @brief Valida e define o novo nível de prioridade contanto que pertença ao enumerador Nivel.
         * @param prioridade O novo nível do tipo Prioridade::Nivel a ser atribuído.
         * @throws std::invalid_argument Se o valor fornecido for inválido ou não mapeado ("Prioridade invalida").
         */
        void setPrioridade(Nivel prioridade);

        /**
         * @brief Recupera o nível de prioridade atualmente configurado.
         * @return O nível atual armazenado no objeto (do tipo Prioridade::Nivel).
         */
        Nivel getPrioridade() const;

    private:
        /**
         * @brief Armazena o nível de prioridade atual do objeto.
         *
         * O valor padrão ao instanciar a classe é definido automaticamente como Prioridade::BAIXA.
         */
        Nivel prioridade = BAIXA;
};

#endif
