#include "CntrlServicoRelatorio.hpp"

#include <ctime>
#include <string>

using namespace std;

namespace {

bool temAcesso(const Pessoa &pessoa) {
    Papel::Cargo cargo = pessoa.getPapel().getCargo();
    return cargo == Papel::Gestor || cargo == Papel::Desenvolvedor;
}

bool converterTimestamp(const string &texto, tm &data) {
    int separadorMes = texto.find('-');
    int separadorAno = texto.find('-', separadorMes + 1);
    int separadorHora = texto.find('-', separadorAno + 1);
    const string meses[] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN", "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};

    if (separadorMes < 0 || separadorAno < 0 || separadorHora < 0)
        return false;

    int numeroMes = 0;

    while (numeroMes < 12 && texto.substr(separadorMes + 1, 3) != meses[numeroMes])
        ++numeroMes;

    if (numeroMes == 12)
        return false;

    data = {};
    data.tm_mday = stoi(texto.substr(0, separadorMes));
    data.tm_mon = numeroMes;
    data.tm_year = stoi(texto.substr(separadorAno + 1, 4)) - 1900;
    data.tm_hour = stoi(texto.substr(separadorHora + 1, 2));
    data.tm_min = stoi(texto.substr(separadorHora + 4, 2));
    data.tm_sec = 0;
    data.tm_isdst = -1;
    return true;
}

int diferencaMinutos(const string &inicio, const string &termino) {
    tm dataInicio;
    tm dataTermino;

    if (inicio.empty() || termino.empty())
        return -1;

    if (!converterTimestamp(inicio, dataInicio) || !converterTimestamp(termino, dataTermino))
        return -1;

    time_t tempoInicio = mktime(&dataInicio);
    time_t tempoTermino = mktime(&dataTermino);

    if (tempoInicio == -1 || tempoTermino < tempoInicio)
        return -1;

    return static_cast<int>(difftime(tempoTermino, tempoInicio) / 60);
}

bool pertenceAoQuadro(const CartaoAtividade &cartao, const Identificador &quadro) {
    return cartao.getQuadro().getIdentificador() == quadro.getIdentificador();
}

} // namespace

CntrlServicoRelatorio::CntrlServicoRelatorio(ContainerCartoes &container, const Pessoa &usuario)
    : container(container), usuario(usuario) {
}

int CntrlServicoRelatorio::lerTempoCiclo(const Identificador &identificador) const {
    if (!temAcesso(usuario))
        return -1;

    CartaoAtividade cartao;

    if (!container.buscar(identificador, cartao))
        return -1;

    return diferencaMinutos(cartao.getInicio().getValor(), cartao.getTermino().getValor());
}

double CntrlServicoRelatorio::lerTempoCicloMedio(const Identificador &quadro) const {
    if (!temAcesso(usuario))
        return -1;

    vector<CartaoAtividade> cartoes = container.listar();
    int soma = 0;
    int quantidade = 0;

    for (const CartaoAtividade &cartao : cartoes) {
        if (!pertenceAoQuadro(cartao, quadro))
            continue;

        int tempo = diferencaMinutos(cartao.getInicio().getValor(), cartao.getTermino().getValor());

        if (tempo >= 0) {
            soma += tempo;
            ++quantidade;
        }
    }

    if (quantidade == 0)
        return -1;

    return static_cast<double>(soma) / quantidade;
}

int CntrlServicoRelatorio::lerLeadTime(const Identificador &identificador) const {
    if (!temAcesso(usuario))
        return -1;

    CartaoAtividade cartao;

    if (!container.buscar(identificador, cartao))
        return -1;

    return diferencaMinutos(cartao.getEntrada().getValor(), cartao.getTermino().getValor());
}

double CntrlServicoRelatorio::lerLeadTimeMedio(const Identificador &quadro) const {
    if (!temAcesso(usuario))
        return -1;

    vector<CartaoAtividade> cartoes = container.listar();
    int soma = 0;
    int quantidade = 0;

    for (const CartaoAtividade &cartao : cartoes) {
        if (!pertenceAoQuadro(cartao, quadro))
            continue;

        int tempo = diferencaMinutos(cartao.getEntrada().getValor(), cartao.getTermino().getValor());

        if (tempo >= 0) {
            soma += tempo;
            ++quantidade;
        }
    }

    if (quantidade == 0)
        return -1;

    return static_cast<double>(soma) / quantidade;
}

int CntrlServicoRelatorio::lerWIP(const Identificador &quadro) const {
    if (!temAcesso(usuario))
        return -1;

    vector<CartaoAtividade> cartoes = container.listar();
    int quantidade = 0;

    for (const CartaoAtividade &cartao : cartoes) {
        if (pertenceAoQuadro(cartao, quadro) && cartao.getEstado().getEstado() == Estado::FAZENDO)
            ++quantidade;
    }

    return quantidade;
}
