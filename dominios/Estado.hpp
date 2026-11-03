#ifndef ESTADO_HPP
#define ESTADO_HPP

using namespace std;

/**
 * @class Estado
 * @brief Gerencia o ciclo de vida ou progresso de uma tarefa ou objeto.
 *
 * Esta classe encapsula um enumerador que representa três estados possíveis
 * de progresso (A_FAZER, FAZENDO, FEITO), garantindo que modificações passem
 * por validação de integridade.
 */
class Estado{
    public:
        /**
         * @enum Status
         * @brief Define as etapas possíveis para o progresso de um fluxo de trabalho.
         */
        enum Status {
            A_FAZER, ///< Tarefa ainda não iniciada.
            FAZENDO, ///< Tarefa em andamento.
            FEITO    ///< Tarefa concluída com sucesso.
        };

        /**
         * @brief Define e valida o novo estado, caso ele pertença ao enumerador status.
         * @param estado O novo status a ser atribuído à tarefa.
         * @throws std::invalid_argument Se o valor fornecido não corresponder a nenhum dos estados mapeados ("Estado invalido").
         */
        void setEstado(Status estado);

        /**
         * @brief Recupera o estado atual.
         * @return O status atual armazenado no objeto.
         */
        Status getEstado() const;

    private:
        /**
         * @brief Armazena o estado atual do objeto.
         *
         * O valor padrão ao instanciar a classe é definido automaticamente como Estado::A_FAZER.
         */
        Status estado = A_FAZER;
};

#endif
