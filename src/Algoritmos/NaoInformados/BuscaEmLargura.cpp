#ifndef BUSCA_EM_LARGURA_CPP
#define BUSCA_EM_LARGURA_CPP
#include <string>
#include <iostream>
#include "../../Estruturas/Headers/Estado.hpp"
#include "../../Estruturas/Headers/Listas/Fila.hpp"
#include "../../Estruturas/Headers/Listas/Lista.hpp"

using namespace std;
/*******************************************
 * Autor: João Pedro de Carvalho Lima
 * Desde: 11/07/2022
 *******************************************/
class BuscaEmLargura
{
public:
    static void run(Estado *inicial, Estado *final)
    {
        short status = 0; // -1 = FRACASSO; 1 = SUCESSO; 0 = EM PROCESSO
        Fila<Estado *> *abertos = new Fila<Estado *>();
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
                        for (int i = inicial->getNumMovimentos(); i >= 1; i--)
                        {
                            aux = atual->movimentar(i, false, NULL);
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