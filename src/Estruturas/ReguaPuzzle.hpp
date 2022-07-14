
#ifndef REGUAPUZZLE_HPP
#define REGUAPUZZLE_HPP
#include "./Headers/Estado.hpp"
#include <iostream>
#include <string>

using namespace std;

class ReguaPuzzle : public Estado {

private:
  // Funções
  ReguaPuzzle();
  ReguaPuzzle(int n, char *regua);
  ~ReguaPuzzle();
  void calculaEstadoFinal();
  bool validade();

  // Variaveis
  int n;
  char *regua;
  char *estadoFinal;

public:

 //Setters
  void setN(int novoN);
  void setRegua(char *regua);

  //getters  
  int getN(int novoN);
  char *getRegua();
};
#endif