#include "CntrlServicoCartao.hpp"
#include <ctime>
#include <string>

using namespace std;

namespace {

string doisDigitos(int valor) {
    string resultado = to_string(valor);

    if (resultado.size() == 1)
        resultado = "0" + resultado;

    return resultado;
}

string timestampAtual() {
    const string meses[] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN", "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};
    time_t agora = time(nullptr);
    tm *data = localtime(&agora);
    string ano = to_string(data->tm_year + 1900);

    return doisDigitos(data->tm_mday) + "-" + meses[data->tm_mon] + "-" + ano + "-" + doisDigitos(data->tm_hour) + ":" +
           doisDigitos(data->tm_min);
}

bool transicaoValida(Estado::Status atual, Estado::Status proximo) {
    if (atual == Estado::A_FAZER && proximo == Estado::FAZENDO)
        return true;

    if (atual == Estado::FAZENDO && proximo == Estado::FEITO)
        return true;

    return false;
}

} // namespace

CntrlServicoCartao::CntrlServicoCartao(ContainerCartoes &container, ContainerQuadros &quadros, const Pessoa &usuario)
    : container(container), quadros(quadros), usuario(usuario) {
}

namespace {

bool ehGestor(const Pessoa &pessoa) {
    return pessoa.getPapel().getCargo() == Papel::Gestor;
}

} // namespace

bool CntrlServicoCartao::criar(const CartaoAtividade &cartao) {
    if (!ehGestor(usuario))
        return false;

    CartaoAtividade novoCartao = cartao;

    if (novoCartao.getEntrada().getValor().empty()) {
        Timestamp entrada;
        entrada.setValor(timestampAtual());
        novoCartao.setEntrada(entrada);
    }

    return container.inserir(novoCartao);
}

vector<CartaoAtividade> CntrlServicoCartao::listar() const {
    return container.listar();
}

bool CntrlServicoCartao::consultar(const Identificador &identificador, CartaoAtividade &cartao) {
    return container.buscar(identificador, cartao);
}

bool CntrlServicoCartao::editar(const CartaoAtividade &cartao) {
    if (!ehGestor(usuario))
        return false;

    return container.editar(cartao);
}

bool CntrlServicoCartao::excluir(const Identificador &identificador) {
    if (!ehGestor(usuario))
        return false;

    return container.excluir(identificador);
}

bool CntrlServicoCartao::mover(const Identificador &identificador, const Estado &estado) {
    CartaoAtividade cartao;

    if (!container.buscar(identificador, cartao))
        return false;

    Estado::Status atual = cartao.getEstado().getEstado();
    Estado::Status proximo = estado.getEstado();

    if (!transicaoValida(atual, proximo))
        return false;

    if (proximo == Estado::FAZENDO) {
        Quadro quadro;

        if (!quadros.buscar(cartao.getQuadro(), quadro))
            return false;

        int quantidade = container.contarPorEstado(cartao.getQuadro(), Estado::FAZENDO);

        if (quantidade >= quadro.getLimite().getLimite())
            return false;

        Timestamp inicio;
        inicio.setValor(timestampAtual());
        cartao.setInicio(inicio);
    }

    if (proximo == Estado::FEITO) {
        Timestamp termino;
        termino.setValor(timestampAtual());
        cartao.setTermino(termino);
    }

    cartao.setEstado(estado);
    return container.editar(cartao);
}
