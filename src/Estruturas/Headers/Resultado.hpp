#ifndef RESULTADO_HPP
#define RESULTADO_HPP

using namespace std;

class Resultado
{
public:
    bool sucesso;
    int profundidade;
    int nosExpandidos;
    int nosVisitados;
    int custoDaSolucao;
    Resultado()
    {
        this->sucesso = false;
        this->profundidade = 0;
        this->nosExpandidos = 0;
        this->nosVisitados = 0;
        this->custoDaSolucao = 0;
    }
};
#endif