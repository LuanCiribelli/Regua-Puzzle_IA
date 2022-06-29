#include<iostream>
#include "Estruturas/Headers/Estado.hpp"
#include "Estruturas/Jarros.cpp"
#include<string>

using namespace std;

int main()
{
    Estado* estado;
    Jarros jarros;
    estado = &jarros;
    cout << "HELLO" << endl;
    estado->movimentar(1)->movimentar(4);

    return 0;
}