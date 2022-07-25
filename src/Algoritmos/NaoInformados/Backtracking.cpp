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
    Pilha<int> *movimentos = new Pilha<int>();
    Estado *atual;
    Estado *aux;
    abertos->inserir(inicial);
    movimentos->inserir(inicial->getNumMovimentos());
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
        if (atual->equals(final))
        {
          cout << "\nSUCESSO" << endl;
          status = 1;
        }
        else
        {
          while(movimentos->get() > 0){
            aux = atual->movimentar(movimentos->get(), false, NULL);
            movimentos->inserir(movimentos->remover() - 1);
            if(aux != NULL && !abertos->contem(aux)){
              abertos->inserir(aux);
              movimentos->inserir(inicial->getNumMovimentos());
              cout << "-->";
              aux->print();
              cout << endl;
              break;
            }
          }
          if(movimentos->get() == 0){
            delete abertos->remover();
            movimentos->remover();
            cout << "--> NULL" << endl;
          }
        }
      }
    }
  }
};

#endif