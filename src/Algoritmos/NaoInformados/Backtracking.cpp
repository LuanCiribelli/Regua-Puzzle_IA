#ifndef BUSCA_EM_LARGURA_CPP
#define BUSCA_EM_LARGURA_CPP
#include "../../Estruturas/Headers/Estado.hpp"
#include "../../Estruturas/Headers/Listas/Lista.hpp"
#include "../../Estruturas/Headers/Listas/Pilha.hpp"
#include <iostream>
#include <string>

using namespace std;
/*******************************************
 * Autor: Luan Reis Ciribelli
 * Desde: 13/07/2022
 *******************************************/

class Backtracking {
public:
<<<<<<< HEAD
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
                            aux = atual->movimentar(i);
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
=======
  static void run(Estado *inicial, Estado *final) {
    short status = 0; // -1 = FRACASSO; 1 = SUCESSO; 0 = EM PROCESSO
    Pilha<Estado *> *abertos = new Pilha<Estado *>();
    Lista<Estado *> *fechados = new Lista<Estado *>();
    Estado *atual;
    Estado *aux;

    abertos->inserir(inicial);
    while (status == 0) {
      if (abertos->estaVazio()) {
        if (atual->equals(inicial)) {
          cout << "FRACASSO" << endl;
          status = -1;
        } else {
         atual = abertos->remover();
        }
      } else {
        atual = abertos->remover();
        if (fechados->contem(atual)) {
          delete atual;
        } else {
          atual->print();
          cout << "-->";
          if (atual->equals(final)) {
            cout << "SUCESSO" << endl;
            status = 1;
          } else {
            for (int i = inicial->getNumMovimentos(); i >= 1; i--) {
              aux = atual->movimentar(i);
              if (aux != NULL && !fechados->contem(aux)) {
                aux->print();
                abertos->inserir(aux);
              }
>>>>>>> feature/backtracking
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