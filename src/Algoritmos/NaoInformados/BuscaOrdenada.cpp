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
 * Autor: luan Reis Ciribelli
 * Desde: 17/07/2022
 *******************************************/
class BuscaOrdenada {

private:
  static map<Estado *, int> *getMin(map<Estado *, int> *mymap) {

    int min = mymap->begin()->second;

    map<Estado *, int> *aux;
    for (auto const &x : *mymap) {
      if (x.second < min) {
        aux->clear();
        aux->insert({x.first, x.second});
        min = x.second;
      }
    }

    return aux;
  };

public:
  static void run(Estado *inicial, Estado *final) {
    short status = 0; // -1 = FRACASSO; 1 = SUCESSO; 0 = EM PROCESSO
    map<Estado *, int> *abertos;
    Lista<Estado *> *fechados = new Lista<Estado *>();
    Estado *atual;
    Estado *aux;
    map<Estado *, int> *auxiliar;
    abertos->insert({inicial, -1});
    while (status == 0) {
      if (abertos->empty()) {
        cout << "FRACASSO" << endl;
        status = -1;
      } else {
        atual = (getMin(abertos))->begin()->first;
        abertos->erase(auxiliar->begin()->first);
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
                cout << "Inserindo com peso:" << aux->getPeso();
                abertos->insert({aux, aux->getPeso()});
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
