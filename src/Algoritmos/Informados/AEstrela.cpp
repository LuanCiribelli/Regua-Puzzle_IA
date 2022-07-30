#ifndef AESTRELA_CPP
#define AESTRELA_CPP
#include "../../Estruturas/Headers/Estado.hpp"
#include "../../Estruturas/Headers/Listas/Fila.hpp"
#include "../../Estruturas/Headers/Listas/Lista.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;
/*******************************************
 * Autor: João Pedro Lima
 * Desde: 25/07/2022
 *******************************************/
class AEstrela
{
public:
  static void run(Estado *inicial, Estado *final, fstream &outputFile)
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
        outputFile << "FRACASSO" << endl;
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
          atual->print(outputFile);
          cout << "-->";
          outputFile << "-->";
          if (atual->equals(final))
          {
            cout << "SUCESSO" << endl;
            outputFile << "SUCESSO" << endl;
            status = 1;
          }
          else
          {
            for (int i = inicial->getNumMovimentos(); i > 0; i--)
            {
              aux = atual->movimentar(i, true, final);
              if (aux != NULL && !fechados->contem(aux))
              {
                aux->print();
                aux->print(outputFile);
                cout << "  "; 
                outputFile << "  "; 
                while (index < abertos->getTamanho())
                {
                  if (aux->getHeuristica() + aux->getCusto() 
                  < abertos->get(index)->getHeuristica() + abertos->get(index)->getCusto())
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
            outputFile << endl;
            fechados->inserir(atual);
          }
        }
      }
    }
  }
};
#endif
