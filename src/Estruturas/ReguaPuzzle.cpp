#include "ReguaPuzzle.hpp"


ReguaPuzzle::ReguaPuzzle() {
  this->n = 0;
  this->regua[0] = NULL;
  calculaEstadoFinal();
};

ReguaPuzzle::ReguaPuzzle(int n, vector<char> regua) {
  this->n = n;
  this->regua = regua;
  calculaEstadoFinal();
};
ReguaPuzzle::~ReguaPuzzle() {
this->regua.clear();
this->estadoFinal.clear();
};

void ReguaPuzzle::calculaEstadoFinal() {

  for (int j = 0; j <= (n / 2) - 1; j++) {
    this->estadoFinal[j] = 'B';
  }
  this->estadoFinal[n / 2] = ' ';
  for (int j = (n / 2) + 1; j < (n); j++) {
    this->estadoFinal[j] = 'P';
  }
};

bool ReguaPuzzle::validade() {

  if (this->n > 0) {
    int tamanho = this->n;
    // Array que conta o numero de brancos, Pretos e espaços. Nessa ordem;
    int conta[3] = {0, 0, 0};
    for (int i = 0; i <= n; i++) {
      if (this->regua[n] == 'B')
        conta[0] += 1;
      else if (this->regua[n] == 'P')
        conta[1] += 1;
      else
        conta[2] += 1;
    }

    if (conta[0] == ((n / 2) - 1) && conta[1] == ((n / 2) - 1) &&
        conta[2] == 1) {
      return true;
    } else {
      return false;
    }
  } else {
    this->estadoFinal[0] = NULL;
    return false;
  }

}; // Setters
void ReguaPuzzle::setN(int novoN) { this->n = novoN; };
void ReguaPuzzle::setRegua(vector<char> regua) { this->regua = regua; };

// getters
int ReguaPuzzle::getN() { return this->n; };
vector<char> ReguaPuzzle::getRegua() { return this->regua; };