
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

public:
  ReguaPuzzle() {
    this->n = 0;
    this->regua[0] = '\0';
    this->numMov = 4;
    calculaEstadoFinal();
  };

  ReguaPuzzle(int n, vector<char> regua) {
    this->n = n;
    this->regua = regua;
    this->numMov = 4;
    // calculaEstadoFinal();
  };
  ~ReguaPuzzle() {
    this->regua.clear();
    this->estadoFinal.clear();
  };

  // Setters
  void setN(int novoN) { this->n = novoN; };
  void setRegua(vector<char> regua) { this->regua = regua; };

  // getters
  int getN() { return this->n; };
  vector<char> getRegua() { return this->regua; };
  int getNumMovimentos() { return this->numMov; };
  vector<char> getEstadoFinal() { return this->estadoFinal; };
  int getCusto() { return -1; };
  int getHeuristica() { return -1; };

  bool equals(Estado *estado) {
    cout << "Estado vazio: equals" << endl;
    return false;
  };

  // Imprimir estado atual
  void print() {

    for (int i = 0; i <= n; i++) {
      cout << this->regua[i] << " ";
    }
    cout << endl;
  };

  bool validade() {
    if (this->n > 0) {
      // Array que conta o numero de brancos, Pretos e espaços. Nessa ordem;
      int conta[3] = {0, 0, 0};
      for (int i = 0; i <= n; i++) {

        if (this->regua[i] == 'B')
          conta[0] += 1;

        else if (this->regua[i] == 'P')
          conta[1] += 1;

        else 
/*
          cout << "DEBUG" << '\n';
          cout << this->regua[i] << " ";
*/      if (this->regua[i] == '-')
          conta[2] += 1;
        
      }

      if (conta[0] == (((n - 1) / 2)) && conta[1] == (((n - 1) / 2)) &&
          conta[2] == 1) {
        return true;
      } else {

        cout << "Peças brancas " << conta[0] << " Peças Pretas " << conta[1]
             << " Espaço " << conta[2] << endl;
        return false;
      }
    } else {
      return false;
    }
  };

  // Funções de estado
  Estado *movimentar(int indexMovimento, bool custo, Estado *estadoFinal) {

    ReguaPuzzle *reguaNova = new ReguaPuzzle(this->n, this->regua);

    switch (indexMovimento) {

    case 1: {
      // Bloco a esquerda move para o buraco, se tiver membro a esquerda
      int pos = 0;

      for (char &c : reguaNova->getRegua()) {
        if (c == '-') {
          break;
        } else {
          pos++;
        }
      }

      if (pos <= reguaNova->getRegua().size()) {
        if (pos - 1 >= 0) {
          vector<char> aux = reguaNova->getRegua();
          iter_swap(aux.begin() + pos - 1, aux.begin() + pos);
          reguaNova->setRegua(aux);
        }

      } else {
        reguaNova = NULL;
      }
      break;
    }
    case 2: {
      // Bloco a Direita move para o buraco, se tiver membro a direita
      int pos = 0;

      for (char &c : reguaNova->getRegua()) {
        if (c == '-') {
          break;
        } else {
          pos++;
        }
      }

      if (pos <= reguaNova->getRegua().size()) {
        if (pos + 1 <= reguaNova->getRegua().size()) {
          vector<char> aux = reguaNova->getRegua();
          iter_swap(aux.begin() + pos + 1, aux.begin() + pos);
          reguaNova->setRegua(aux);
        }

      } else {
        reguaNova = NULL;
      }
      break;
    }
    case 3: {
      // Bloco dois a esquerda move para o buraco, se tiver como
      int pos = 0;

      for (char &c : reguaNova->getRegua()) {
        if (c == '-') {
          break;
        } else {
          pos++;
        }
      }

      if (pos <= reguaNova->getRegua().size()) {
        if (pos - 2 >= 0) {
          vector<char> aux = reguaNova->getRegua();
          iter_swap(aux.begin() + pos - 2, aux.begin() + pos);
          reguaNova->setRegua(aux);
        }
      } else {
        reguaNova = NULL;
      }
      break;
    } break;
    case 4: {
      // Bloco dois a Direita move para o buraco
      int pos = 0;

      for (char &c : reguaNova->getRegua()) {
        if (c == '-') {
          break;
        } else {
          pos++;
        }
      }

      if (pos <= reguaNova->getRegua().size()) {
        if (pos + 2 <= reguaNova->getRegua().size()) {
          vector<char> aux = reguaNova->getRegua();
          iter_swap(aux.begin() + pos + 2, aux.begin() + pos);
          reguaNova->setRegua(aux);
        }

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

private:
  // Funções

  void calculaEstadoFinal() {
    if (n % 2 != 0) {
      for (int j = 0; j <= (n / 2) - 1; j++) {
        this->estadoFinal[j] = 'B';
      }
      this->estadoFinal[n / 2] = '-';
      for (int j = (n / 2) + 1; j < (n); j++) {
        this->estadoFinal[j] = 'P';
      }
    } else {
      for (int j = 0; j <= (n % 2) - 1; j++) {
        this->estadoFinal[j] = 'B';
      }
      this->estadoFinal[n % 2] = '-';
      for (int j = (n / 2) % 1; j < (n); j++) {
        this->estadoFinal[j] = 'P';
      }
    }
  };

  // Variaveis
  int n;
  int numMov;
  vector<char> regua;
  vector<char> estadoFinal;
};
#endif