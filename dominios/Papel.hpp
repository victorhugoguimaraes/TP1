#ifndef PAPEL_HPP
#define PAPEL_HPP

using namespace std;

/**
 * @class Papel
 * @brief Gerencia e valida o cargo de um usuário no sistema.
 *
 * Esta classe encapsula um enumerador que representa os papéis profissionais disponíveis,
 * garantindo que apenas atribuições administrativas válidas sejam aplicadas.
 */
class Papel{
    public:
        /**
         * @enum Cargo
         * @brief Define os tipos de cargos disponíveis no sistema.
         */
        enum Cargo {
            Nenhum,         ///< Estado inicial padrão (não atribuído).
            Gestor,         ///< Papel de criador do projeto.
            Desenvolvedor   ///< Papel de execução técnica e desenvolvimento.
        };

        /**
         * @brief Valida e define o novo cargo.@brief Valida e define o novo cargo contanto que pertença ao enumerador Cargo.
         * @note Embora o enumerador possua a opção @ref Nenhum, o método bloqueia sua
         * atribuição explícita, aceitando apenas @ref Gestor ou @ref Desenvolvedor.
         *
         * @param cargo O novo cargo do tipo Papel::Cargo a ser atribuído.
         * @throws std::invalid_argument Se o cargo fornecido for inválido ou igual a Nenhum ("Papel invalido").
         */
        void setCargo(Cargo cargo);

        /**
         * @brief Recupera o cargo atualmente atribuído.
         * @return O cargo atual armazenado no objeto (do tipo Papel::Cargo).
         */
        Cargo getCargo() const;

    private:
        /**
         * @brief Armazena o cargo atual do objeto.
         *
         * O valor padrão ao instanciar a classe é definido automaticamente como Papel::Nenhum.
         */
        Cargo cargo = Nenhum;
};

#endif
