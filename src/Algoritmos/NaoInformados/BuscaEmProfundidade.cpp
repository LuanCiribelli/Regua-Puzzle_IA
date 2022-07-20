#ifndef BUSCA_EM_PROFUNDIDADE_CPP
#define BUSCA_EM_PROFUNDIDADE_CPP
#include <string>
#include <iostream>
#include "../../Estruturas/Headers/Estado.hpp"
#include "../../Estruturas/Headers/Listas/Pilha.hpp"
#include "../../Estruturas/Headers/Listas/Lista.hpp"

using namespace std;

/*******************************************
 * Autor: João Pedro de Carvalho Lima
 * Desde: 11/07/2022
 *******************************************/
class BuscaEmProfundidade
{
public:
    static void run(Estado *inicial, Estado *final)
    {
        short status = 0; // -1 = FRACASSO; 1 = SUCESSO; 0 = EM PROCESSO
        Pilha<Estado *> *abertos = new Pilha<Estado *>();
        Lista<Estado *> *fechados = new Lista<Estado *>();
        Estado *atual;
        Estado *aux;
        abertos->inserir(inicial);
        while (status == 0)
        {
            if (abertos->estaVazio())
            {
                cout << "FRACASSO" << endl;
                status = -1;
            }
            else
            {
                atual = abertos->remover();
                if (fechados->contem(atual))
                {
                    delete atual;
                }
                else
                {
                    atual->print();
                    cout << "-->";
                    if (atual->equals(final))
                    {
                        cout << "SUCESSO" << endl;
                        status = 1;
                    }
                    else
                    {
                        for (int i = 1; i <= inicial->getNumMovimentos(); i++)
                        {
                            aux = atual->movimentar(i, false);
                            if (aux != NULL && !fechados->contem(aux))
                            {
                                aux->print();
                                abertos->inserir(aux);
                            }
                        }
                        cout << endl;
                        fechados->inserir(atual);
                    }
                }
            }
        }
    }
};
#endif