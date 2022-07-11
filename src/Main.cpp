#include<iostream>
#include "Estruturas/Headers/Estado.hpp"
#include "Estruturas/Jarros.cpp"
#include<string>
#include "Algoritmos/NaoInformados/BuscaEmProfundidade.cpp"
#include "Algoritmos/NaoInformados/BuscaEmLargura.cpp"

using namespace std;

int main()
{
    cout << "BUSCA EM PROFUNDIDADE" << endl;
    BuscaEmProfundidade::run(new Jarros(0,0), new Jarros(2,-1));
    cout << "BUSCA EM LARGURA" << endl;
    BuscaEmLargura::run(new Jarros(0,0), new Jarros(-1,2));

    return 0;
}