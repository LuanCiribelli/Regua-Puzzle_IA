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
  int heuristica;

public:
  Jarros(int a, int b)
  {
    this->jarro1 = a;
    this->jarro2 = b;
    this->custo = 0;
    this->heuristica = 0;
  }
  Jarros(int a, int b, Jarros *jarrosFinal)
  {
    this->jarro1 = a;
    this->jarro2 = b;
    this->custo = 0;
    this->heuristica = funcaoHeuristica(jarrosFinal);
  }
  Jarros(int a, int b, int custo, int heuristica)
  {
    this->jarro1 = a;
    this->jarro2 = b;
    this->custo = custo;
    this->heuristica = heuristica;
  }
  ~Jarros() {}
  void print() { cout << "(" << this->jarro1 << " , " << this->jarro2
                      << ")[Custo: " << this->custo << "]"
                      << "[Heuristica: " << this->heuristica << "]"; }
  int getJarro1() { return this->jarro1; }
  void setJarro1(int quantidade) { this->jarro1 = quantidade; }
  int getJarro2() { return this->jarro2; }
  void setJarro2(int quantidade) { this->jarro2 = quantidade; }
  int getCusto() { return this->custo; }
  void setCusto(int custo) { this->custo = custo; }
  int getHeuristica() { return this->heuristica; }
  void setHeuristica(int heuristica) { this->heuristica = heuristica; }

  int getNumMovimentos() { return 6; };
  Estado *movimentar(int indexMovimento, bool custo, Estado* estadoFinal)
  {
    Jarros *jarrosFinal = dynamic_cast<Jarros *>(estadoFinal);
    Jarros *jarros = new Jarros(this->jarro1, this->jarro2, jarrosFinal);
    switch (indexMovimento)
    {
    case 1:
    {
      jarros->setJarro1(MAX_JARRO1);
      if (custo)
        jarros->setCusto(1 + this->custo);
      break;
    }
    case 2:
    {
      jarros->setJarro2(MAX_JARRO2);
      if (custo)
        jarros->setCusto(1 + this->custo);
      break;
    }
    case 3:
    {
      jarros->setJarro1(0);
      if (custo)
        jarros->setCusto(2 + this->custo);
      break;
    }
    case 4:
    {
      jarros->setJarro2(0);
      if (custo)
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
      if (custo)
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
      if (custo)
        jarros->setCusto(3 + this->custo);
      break;
    }
    default:
      break;
    }
    jarros->setHeuristica(jarros->funcaoHeuristica(jarrosFinal));
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

  int funcaoHeuristica(Jarros *jarrosFinal)
  {
    if (jarrosFinal == NULL)
    {
      return 0;
    }
    else
    {
      int hj1 = jarrosFinal->getJarro1() < 0 ? 0 : abs(jarrosFinal->getJarro1() - this->jarro1);
      int hj2 = jarrosFinal->getJarro2() < 0 ? 0 : abs(jarrosFinal->getJarro2() - this->jarro2);
      return hj1 + hj2;
    }
  }
};
#endif