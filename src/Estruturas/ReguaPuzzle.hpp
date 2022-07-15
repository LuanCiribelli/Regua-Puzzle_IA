
#ifndef REGUAPUZZLE_HPP
#define REGUAPUZZLE_HPP
#include "./Headers/Estado.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReguaPuzzle : public Estado {

private:
  // Funções

  void calculaEstadoFinal();
  bool validade();

  // Variaveis
  int n;
  vector<char> regua;
  vector<char> estadoFinal;

public:
  ReguaPuzzle();
  ReguaPuzzle(int n, vector<char> regua);
  ~ReguaPuzzle();

  // Setters
  void setN(int novoN);
  void setRegua(vector<char> regua);

  // getters
  int getN();
  vector<char> getRegua();
};
#endif