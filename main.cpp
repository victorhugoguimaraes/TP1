#include <iostream>
#include "Email.hpp"
using namespace std;

int main()
{
    Email e;
    e.setValor("qualquer coisa");
    cout << e.getValor() << endl;
    return 0;
}
