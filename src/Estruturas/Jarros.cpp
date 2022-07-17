#ifndef JARROS_HPP
#define JARROS_HPP
#include "./Headers/Estado.hpp"
#include <iostream>
#include <string>
using namespace std;

class Jarros : public Estado {
private:
  const int MAX_JARRO1 = 5;
  const int MAX_JARRO2 = 3;
  int jarro1;
  int jarro2;
  int peso;

public:
  Jarros(int a, int b) {
    this->jarro1 = a;
    this->jarro2 = b;
    this->peso = -1;
  }
  Jarros(int a, int b, int peso) {
    this->jarro1 = a;
    this->jarro2 = b;
    this->peso = peso;
  }
  ~Jarros() {}
  void print() { cout << "(" << this->jarro1 << " , " << this->jarro2 << ")"; }
  void setJarro1(int quantidade) { this->jarro1 = quantidade; }
  void setJarro2(int quantidade) { this->jarro2 = quantidade; }
  int getJarro1() { return this->jarro1; }
  int getJarro2() { return this->jarro2; }
  int getpeso() { return this->peso; }
  void setPeso(int peso) { this->peso = peso; }
  int getNumMovimentos() { return 6; };
  Estado *movimentar(int indexMovimento) {
    Jarros *jarros = new Jarros(this->jarro1, this->jarro2);
    switch (indexMovimento) {
    case 1: {
      jarros->setJarro1(MAX_JARRO1);
      this->peso = 0.5*2;
      break;
    }
    case 2: {
      jarros->setJarro2(MAX_JARRO2);
      this->peso = 0.5*3;
      break;
    }
    case 3: {
      jarros->setJarro1(0);
      this->peso = 0.5*4;
      break;
    }
    case 4: {
      jarros->setJarro2(0);
      this->peso = 0.5*5;
      break;
    }
    case 5: {
      jarros->setJarro2(jarros->getJarro1());
      jarros->setJarro1(0);
      if (jarros->getJarro2() - MAX_JARRO2 > 0) {
        jarros->setJarro1(jarros->getJarro2() - MAX_JARRO2);
        jarros->setJarro2(MAX_JARRO2);
      }
      this->peso = 0.5*6;
      break;
    }
    case 6: {
      jarros->setJarro1(jarros->getJarro2());
      jarros->setJarro2(0);
      if (jarros->getJarro1() - MAX_JARRO1 > 0) {
        jarros->setJarro2(jarros->getJarro1() - MAX_JARRO1);
        jarros->setJarro1(MAX_JARRO1);
      }
      this->peso = 0.5*7;
      break;
    }
    default:
      break;
    }
    if (this->equals(jarros)) {
      delete jarros;
      return NULL;
    } else {
      return jarros;
    }
  }

  bool equals(Estado *estado) {
    Jarros *outroJarro = dynamic_cast<Jarros *>(estado);
    return ((this->jarro1 == outroJarro->getJarro1() || this->jarro1 < 0 ||
             outroJarro->getJarro1() < 0) &&
            (this->jarro2 == outroJarro->getJarro2() || this->jarro2 < 0 ||
             outroJarro->getJarro2() < 0));
  }
};
#endif