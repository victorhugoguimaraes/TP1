#ifndef LIMITE_HPP
#define LIMITE_HPP

using namespace std;

class Limite{
    private:
        static const int limiteMax = 25;
        int limite = 0;
    public:
        void setLimite(int limite);
        int  getLimite() const;

};

#endif