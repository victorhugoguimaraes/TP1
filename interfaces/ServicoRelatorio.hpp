/**
 * @file ServicoRelatorio.hpp
 * @brief Declaração da interface de serviço para geração de relatórios e métricas de fluxo.
 */

#ifndef SERVICORELATORIO_H
#define SERVICORELATORIO_H

#include <vector>

#include "../dominios/Identificador.hpp"

using namespace std;

/**
 * @class ServicoRelatorio
 * @brief Define a interface de cálculo de métricas e indicadores de desempenho.
 * @details Permite que a camada de apresentação consulte indicadores de tempo e volume
 * de trabalho (como Tempo de Ciclo, Lead Time e WIP) de cartões e quadros sem depender
 * da implementação concreta do armazenamento.
 */
class ServicoRelatorio {
  public:
    /**
     * @brief Calcula o tempo de ciclo (Cycle Time) de um cartão de atividade específico.
     * @param identificador Objeto Identificador do cartão analisado.
     * @return Valor inteiro correspondente ao tempo decorrido entre o início (quando cartão é colocado no estado FAZENDO) e o término do cartão.
     */
    virtual int lerTempoCiclo(const Identificador &identificador) const = 0;

    /**
     * @brief Calcula o tempo de ciclo médio dos cartões concluídos em um quadro.
     * @param quadro Objeto Identificador do quadro analisado.
     * @return Valor em ponto flutuante (double) representando a média do tempo de ciclo do quadro.
     */
    virtual double lerTempoCicloMedio(const Identificador &quadro) const = 0;

    /**
     * @brief Calcula o Lead Time de um cartão de atividade específico.
     * @param identificador Objeto Identificador do cartão analisado.
     * @return Valor inteiro correspondente ao tempo total decorrido desde a entrada (criação do cartão) até o término do cartão.
     */
    virtual int lerLeadTime(const Identificador &identificador) const = 0;

    /**
     * @brief Calcula o Lead Time médio dos cartões concluídos em um quadro.
     * @param quadro Objeto Identificador do quadro analisado.
     * @return Valor em ponto flutuante (double) representando a média do Lead Time do quadro.
     */
    virtual double lerLeadTimeMedio(const Identificador &quadro) const = 0;

    /**
     * @brief Obtém a quantidade atual de trabalho em progresso (Work In Progress - WIP) de um quadro.
     * @param quadro Objeto Identificador do quadro analisado.
     * @return Número inteiro de cartões atualmente em execução no quadro.
     */
    virtual int lerWIP(const Identificador &quadro) const = 0;

    /**
     * @brief Permite destruir uma implementação por meio da interface.
     */
    virtual ~ServicoRelatorio() = default;
};

#endif
