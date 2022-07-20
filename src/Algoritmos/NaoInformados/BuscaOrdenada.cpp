#ifndef BUSCA_ORDENADA_CPP
#define BUSCA_ORDENADA_CPP
#include "../../Estruturas/Headers/Estado.hpp"
#include "../../Estruturas/Headers/Listas/Fila.hpp"
#include "../../Estruturas/Headers/Listas/Lista.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;
/*******************************************
 * Autor: João Pedro Lima e Luan Reis Ciribelli
 * Desde: 20/07/2022
 *******************************************/
class BuscaOrdenada
{
public:
  static void run(Estado *inicial, Estado *final)
  {
    short status = 0; // -1 = FRACASSO; 1 = SUCESSO; 0 = EM PROCESSO
    Lista<Estado *> *abertos = new Lista<Estado *>();
    Lista<Estado *> *fechados = new Lista<Estado *>();
    Estado *atual;
    Estado *aux;
    int index;
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
        atual = abertos->remover(0);
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
              aux = atual->movimentar(i, true);
              if (aux != NULL && !fechados->contem(aux))
              {
                aux->print();
                cout << "  ";
                index = 0;
                while (index < abertos->getTamanho())
                {
                  if (aux->getCusto() < abertos->get(index)->getCusto())
                  {
                    break;
                  }
                  else
                  {
                    index += 1;
                  }
                }
                abertos->inserir(aux, index);
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
