#ifndef BUSCA_EM_LARGURA_CPP
#define BUSCA_EM_LARGURA_CPP
#include "../../Estruturas/Headers/Estado.hpp"
#include "../../Estruturas/Headers/Listas/Fila.hpp"
#include "../../Estruturas/Headers/Listas/Lista.hpp"
#include "../../Estruturas/Headers/Resultado.hpp"
#include <iostream>
#include <string>

using namespace std;
/*******************************************
 * Autor: João Pedro de Carvalho Lima
 * Desde: 11/07/2022
 *******************************************/
class BuscaEmLargura {
public:
  static void run(Estado *inicial, Estado *final) {
    short status = 0; // -1 = FRACASSO; 1 = SUCESSO; 0 = EM PROCESSO
    Fila<Estado *> *abertos = new Fila<Estado *>();
    Lista<Estado *> *fechados = new Lista<Estado *>();
    Estado *atual;
    Estado *aux;
    abertos->inserir(inicial);
    while (status == 0) {
      if (abertos->estaVazio()) {
        cout << "FRACASSO" << endl;

        status = -1;
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

              aux = atual->movimentar(i, false, NULL);
              if (aux != NULL && !fechados->contem(aux)) {
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
  static void run(Estado *inicial, Estado *final, fstream &outputFile) {
    Resultado resultado;
    short status = 0; // -1 = FRACASSO; 1 = SUCESSO; 0 = EM PROCESSO
    Fila<Estado *> *abertos = new Fila<Estado *>();
    Lista<Estado *> *fechados = new Lista<Estado *>();
    Estado *atual;
    Estado *aux;
    abertos->inserir(inicial);
    while (status == 0) {
      if (abertos->estaVazio()) {
        cout << "FRACASSO" << endl;
        outputFile << "FRACASSO" << endl;
        resultado.sucesso = false;
        resultado.custoDaSolucao = -1;
        status = -1;
      } else {
        atual = abertos->remover();
        if (fechados->contem(atual)) {
          delete atual;
        } else {
          atual->print();
          atual->print(outputFile);
          cout << "-->";
          outputFile << "-->";
          if (atual->equals(final)) {
            cout << "SUCESSO" << endl;
            outputFile << "SUCESSO" << endl;
            resultado.sucesso = true;
            resultado.custoDaSolucao = atual->getCusto();
            status = 1;
          } else {
            for (int i = inicial->getNumMovimentos(); i >= 1; i--) {

              aux = atual->movimentar(i, false, NULL);
              if (aux != NULL && !fechados->contem(aux)) {
                aux->print();
                aux->print(outputFile);
                resultado.nosVisitados += 1;
                abertos->inserir(aux);
              }
            }
            resultado.nosExpandidos += 1;
            cout << endl;
            outputFile << endl;
            fechados->inserir(atual);
          }
        }
      }
    }
    if (resultado.sucesso) {
      outputFile << "CAMINHO:\n" << endl;
      aux = atual;
      while (aux != NULL) {
        resultado.profundidade += 1;
        aux->print(outputFile);
        outputFile << endl;
        aux = aux->getPai();
      }
      outputFile << "PROFUNDIDADE: " << resultado.profundidade << endl;
      outputFile << "CUSTO DA SOLUÇÃO: " << resultado.custoDaSolucao << endl;
    }
    outputFile << "NÓS EXPANDIDOS: " << resultado.nosExpandidos << endl;
    outputFile << "NÓS VISITADOS: " << resultado.nosVisitados << endl;
    outputFile << "FATOR DE RAMIFICAÇÃO (VISTADOS/EXPANDIDOS): "
               << (float)resultado.nosVisitados / resultado.nosExpandidos
               << endl;
  }
};
#endif