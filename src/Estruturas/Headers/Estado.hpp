#ifndef ESTADO_HPP
#define ESTADO_HPP
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
/*******************************************
 * Autor: João Pedro de Carvalho Lima
 * Desde: 11/07/2022
 *******************************************/
class Estado {
public:
  virtual ~Estado(){};
  virtual int getNumMovimentos() { return -1; };
  virtual int getCusto() { return -1; };
  virtual int getHeuristica() { return -1;};
  int getPatamar(Estado* estadoFinal){ return this->getHeuristica() + this->getCusto(); };
  virtual Estado *movimentar(int indexMovimento, bool custo, Estado* estadoFinal) {
    cout << "Estado vazio: movimentar" << endl;
    return NULL;
  };
  virtual void print() { cout << "Estado vazio: toString" << endl; };
  virtual void print(fstream& outputFile) { cout << "Estado vazio: toString" << endl; };

  virtual bool equals(Estado *estado) {
    cout << "Estado vazio: equals" << endl;
    return false;
  }
  bool operator==(Estado &rhs) { return this->equals(&rhs); };
  bool operator==(Estado *rhs) { return this->equals(rhs); };
};
#endif