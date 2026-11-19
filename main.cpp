#include "apresentacao/CntrlApresentacao.hpp"
#include "persistencia/Schema.hpp"
#include "servico/CntrlServicoAutenticacao.hpp"
#include "servico/CntrlServicoCartao.hpp"
#include "servico/CntrlServicoPessoa.hpp"
#include "servico/CntrlServicoProjeto.hpp"
#include "servico/CntrlServicoQuadro.hpp"
#include "servico/CntrlServicoRelatorio.hpp"

int main() {
    BancoDados banco("tp1.db");
    criarTabelas(banco);

    ContainerPessoas pessoasContainer(banco);
    ContainerProjetos projetosContainer(banco);
    ContainerQuadros quadrosContainer(banco);
    ContainerCartoes cartoesContainer(banco);

    CntrlServicoPessoa servicoPessoa(pessoasContainer);
    CntrlServicoAutenticacao servicoAutenticacao(pessoasContainer);
    Pessoa usuario;
    CntrlServicoProjeto servicoProjeto(projetosContainer, usuario);
    CntrlServicoQuadro servicoQuadro(quadrosContainer, usuario);
    CntrlServicoCartao servicoCartao(cartoesContainer, quadrosContainer, usuario);
    CntrlServicoRelatorio servicoRelatorio(cartoesContainer, usuario);
    CntrlApresentacaoAutenticacao apresentacaoAutenticacao(servicoAutenticacao, servicoPessoa);
    CntrlApresentacao apresentacao(servicoPessoa, servicoProjeto, servicoQuadro, servicoCartao, servicoRelatorio,
                                   apresentacaoAutenticacao, usuario);

    apresentacao.executar();
    return 0;
}
