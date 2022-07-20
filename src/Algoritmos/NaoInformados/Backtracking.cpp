#ifndef BACKTRACKING_CPP
#define BACKTRACKING_CPP
#include "../../Estruturas/Headers/Estado.hpp"
#include "../../Estruturas/Headers/Listas/Lista.hpp"
#include "../../Estruturas/Headers/Listas/Pilha.hpp"
#include <iostream>
#include <string>

using namespace std;
/*******************************************
 * Autores: João Pedro Lima e Luan Reis Ciribelli
 * Desde: 20/07/2022
 *******************************************/

class Backtracking
{
public:
  static void run(Estado *inicial, Estado *final)
  {
    short status = 0; // -1 = FRACASSO; 1 = SUCESSO; 0 = EM PROCESSO
    Pilha<Estado *> *abertos = new Pilha<Estado *>();
    Lista<Estado *> *fechados = new Lista<Estado *>();
    Estado *atual;
    Estado *aux;
    bool null;
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
        atual = abertos->get();
        atual->print();
        cout << "-->";
        if (atual->equals(final))
        {
          cout << "SUCESSO" << endl;
          status = 1;
        }
        else
        {
          null = true;
          for (int i = inicial->getNumMovimentos(); i >= 1; i--)
          {
            aux = atual->movimentar(i, false);
            if (aux != NULL && !fechados->contem(aux) && !abertos->contem(aux))
            {
              aux->print();
              abertos->inserir(aux);
              null = false;
              break;
            }
          }
          cout << endl;
          if (null)
          {
            atual = abertos->remover();
            fechados->inserir(atual);
          }
        }
      }
    }
  }
};

#endif