#ifndef PAPEL_HPP
#define PAPEL_HPP

using namespace std;

class Papel{
    public:
    enum Cargo {
        Nenhum,
        Gestor,
        Desenvolvedor
    };
        void setCargo(Cargo cargo);
        Cargo getCargo() const;

    private: 
        Cargo cargo = Nenhum;
};

#endif