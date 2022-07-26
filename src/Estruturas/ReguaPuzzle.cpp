#include "ReguaPuzzle.hpp"

/*******************************************
 * Autor: Luan Reis Ciribelli
 * Desde: 13/07/2022
 *******************************************/

ReguaPuzzle::ReguaPuzzle() {
  this->n = 0;
  this->regua[0] = NULL;
  this->numMov = 4;
  calculaEstadoFinal();
};

ReguaPuzzle::ReguaPuzzle(int n, vector<char> regua) {
  this->n = n;
  this->regua = regua;
  this->numMov = 4;
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
  this->estadoFinal[n / 2] = '-';
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
};

// Setters
void ReguaPuzzle::setN(int novoN) { this->n = novoN; };
void ReguaPuzzle::setRegua(vector<char> regua) { this->regua = regua; };

// getters
int ReguaPuzzle::getN() { return this->n; };
vector<char> ReguaPuzzle::getRegua() { return this->regua; };
int ReguaPuzzle::getNumMovimentos() { return this->numMov; };

bool ReguaPuzzle::equals(Estado *estado) {

  ReguaPuzzle *regua = dynamic_cast<ReguaPuzzle *>(estado);
  return false;
};

void ReguaPuzzle::print() {

  for (int i = 0; i <= n; i++) {
    cout << this->regua[i] << " ";
  }
  cout << endl;
};

vector<char> ReguaPuzzle::getEstadoFinal() { return this->estadoFinal; };

Estado *ReguaPuzzle::movimentar(int indexMovimento, bool custo,
                                Estado *estadoFinal) {

  ReguaPuzzle *reguaNova = new ReguaPuzzle(this->n, this->regua);

  switch (indexMovimento) {

  case 1: {
    // Bloco a esquerda move para o buraco
    ptrdiff_t pos = std::find_if(reguaNova->getRegua().cbegin(),
                                 reguaNova->getRegua().cend(), "-") -
                    reguaNova->getRegua().begin();

    if (pos <= reguaNova->getRegua().size()) {
      vector<char> aux = reguaNova->getRegua();
      iter_swap(aux.begin() + pos - 1, aux.begin() + pos);
      reguaNova->setRegua(aux);
    } else {
      reguaNova = NULL;
    }
    break;
  }
  case 2: {
    // Bloco a Direita move para o buraco
    ptrdiff_t pos = std::find_if(reguaNova->getRegua().cbegin(),
                                 reguaNova->getRegua().cend(), "-") -
                    reguaNova->getRegua().begin();

    if (pos <= reguaNova->getRegua().size()) {
      vector<char> aux = reguaNova->getRegua();
      iter_swap(aux.begin() + pos + 1, aux.begin() + pos);
      reguaNova->setRegua(aux);
    } else {
      reguaNova = NULL;
    }
    break;
  }
  case 3: {
    // Bloco dois a esquerda move para o buraco
    ptrdiff_t pos = std::find_if(reguaNova->getRegua().cbegin(),
                                 reguaNova->getRegua().cend(), "-") -
                    reguaNova->getRegua().begin();

    if (pos <= reguaNova->getRegua().size()) {
      vector<char> aux = reguaNova->getRegua();
      iter_swap(aux.begin() + pos - 2, aux.begin() + pos);
      reguaNova->setRegua(aux);
    } else {
      reguaNova = NULL;
    }
    break;
  } break;
  case 4: {
    // Bloco dois a Direita move para o buraco
    ptrdiff_t pos = std::find_if(reguaNova->getRegua().cbegin(),
                                 reguaNova->getRegua().cend(), "-") -
                    reguaNova->getRegua().begin();

    if (pos <= reguaNova->getRegua().size()) {
      vector<char> aux = reguaNova->getRegua();
      iter_swap(aux.begin() + pos + 2, aux.begin() + pos);
      reguaNova->setRegua(aux);
    } else {
      reguaNova = NULL;
    }
    break;
  }
  default:

    break;
  }

  return reguaNova;
};