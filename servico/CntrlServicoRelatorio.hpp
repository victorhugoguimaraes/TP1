/**
 * @file CntrlServicoRelatorio.hpp
 * @brief Declaração da classe controladora de serviço para geração de relatórios e métricas.
 */

#ifndef CNTRLSERVICORELATORIO_H
#define CNTRLSERVICORELATORIO_H

#include "../entidades/Pessoa.hpp"
#include "../interfaces/ServicoRelatorio.hpp"
#include "ContainerCartao.hpp"

/**
 * @class CntrlServicoRelatorio
 * @brief Implementa o cálculo de indicadores e métricas de desempenho dos cartões e quadros.
 * @details Realiza as consultas e cálculos definidos em ServicoRelatorio (Tempo de Ciclo,
 * Lead Time e WIP) utilizando os dados armazenados no ContainerCartoes associado e o contexto
 * do usuário autenticado.
 */
class CntrlServicoRelatorio : public ServicoRelatorio {
  private:
    /**
     * @brief Referência ao container onde os cartões de atividade estão armazenados.
     */
    ContainerCartoes &container;

    /**
     * @brief Referência constante para o usuário autenticado na sessão atual.
     */
    const Pessoa &usuario;

  public:
    /**
     * @brief Constrói a controladora associando o container de cartões e o usuário autenticado.
     * @param container Referência ao container responsável pelo armazenamento dos cartões.
     * @param usuario Referência constante para a pessoa autenticada na sessão atual.
     */
    CntrlServicoRelatorio(ContainerCartoes &container, const Pessoa &usuario);

    int lerTempoCiclo(const Identificador &identificador) const override;
    double lerTempoCicloMedio(const Identificador &quadro) const override;
    int lerLeadTime(const Identificador &identificador) const override;
    double lerLeadTimeMedio(const Identificador &quadro) const override;
    int lerWIP(const Identificador &quadro) const override;
};

#endif
