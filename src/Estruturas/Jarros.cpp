#ifndef JARROS_HPP
#define JARROS_HPP
#include "./Headers/Estado.hpp"
#include <iostream>
#include <string>
using namespace std;

class Jarros : public Estado
{
private:
  const int MAX_JARRO1 = 5;
  const int MAX_JARRO2 = 3;
  int jarro1;
  int jarro2;
  int custo;

public:
  Jarros(int a, int b)
  {
    this->jarro1 = a;
    this->jarro2 = b;
    this->custo = 0;
  }
  Jarros(int a, int b, int custo)
  {
    this->jarro1 = a;
    this->jarro2 = b;
    this->custo = custo;
  }
  ~Jarros() {}
  void print() { cout << "(" << this->jarro1 << " , " << this->jarro2 << ")[" << this->custo << "]"; }
  void setJarro1(int quantidade) { this->jarro1 = quantidade; }
  void setJarro2(int quantidade) { this->jarro2 = quantidade; }
  int getJarro1() { return this->jarro1; }
  int getJarro2() { return this->jarro2; }
  int getCusto() { return this->custo; }
  void setCusto(int custo) { this->custo = custo; }
  int getNumMovimentos() { return 6; };
  Estado *movimentar(int indexMovimento, bool custo)
  {
    Jarros *jarros = new Jarros(this->jarro1, this->jarro2);
    switch (indexMovimento)
    {
    case 1:
    {
      jarros->setJarro1(MAX_JARRO1);
      if(custo)
        jarros->setCusto(1 + this->custo);
      break;
    }
    case 2:
    {
      jarros->setJarro2(MAX_JARRO2);
      if(custo)
        jarros->setCusto(1 + this->custo);
      break;
    }
    case 3:
    {
      jarros->setJarro1(0);
      if(custo)
        jarros->setCusto(2 + this->custo);
      break;
    }
    case 4:
    {
      jarros->setJarro2(0);
      if(custo)
        jarros->setCusto(2 + this->custo);
      break;
    }
    case 5:
    {
      jarros->setJarro2(jarros->getJarro2() + jarros->getJarro1());
      jarros->setJarro1(0);
      if (jarros->getJarro2() - MAX_JARRO2 > 0)
      {
        jarros->setJarro1(jarros->getJarro2() - MAX_JARRO2);
        jarros->setJarro2(MAX_JARRO2);
      }
      if(custo)
        jarros->setCusto(3 + this->custo);
      break;
    }
    case 6:
    {
      jarros->setJarro1(jarros->getJarro1() + jarros->getJarro2());
      jarros->setJarro2(0);
      if (jarros->getJarro1() - MAX_JARRO1 > 0)
      {
        jarros->setJarro2(jarros->getJarro1() - MAX_JARRO1);
        jarros->setJarro1(MAX_JARRO1);
      }
      if(custo)
        jarros->setCusto(3 + this->custo);
      break;
    }
    default:
      break;
    }
    if (this->equals(jarros))
    {
      delete jarros;
      return NULL;
    }
    else
    {
      return jarros;
    }
  }

  bool equals(Estado *estado)
  {
    Jarros *outroJarro = dynamic_cast<Jarros *>(estado);
    return ((this->jarro1 == outroJarro->getJarro1() || this->jarro1 < 0 ||
             outroJarro->getJarro1() < 0) &&
            (this->jarro2 == outroJarro->getJarro2() || this->jarro2 < 0 ||
             outroJarro->getJarro2() < 0));
  }
};
#endif