
#ifndef REGUAPUZZLE_HPP
#define REGUAPUZZLE_HPP
#include "./Headers/Estado.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*******************************************
 * Autor: Luan Reis Ciribelli
 * Desde: 16/07/2022
 *******************************************/
class ReguaPuzzle : public Estado {

private:
  // Funções

  void calculaEstadoFinal();
  bool validade();
  Estado *movimentar(int indexMovimento);

  // Variaveis
  int n;
  int numMov;
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
  int getNumMovimentos();


  bool equals(Estado *estado);
  // Imprimir estado atual
  void print();
};
#endif