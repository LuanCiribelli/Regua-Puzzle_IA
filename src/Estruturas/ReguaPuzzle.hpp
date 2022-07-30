
#ifndef REGUAPUZZLE_HPP
#define REGUAPUZZLE_HPP
#include "./Headers/Estado.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
    this->custo = 0;
    this->heuristica = 0;
  };

  ReguaPuzzle(int n, vector<char> regua) {
    this->n = n;
    this->regua = regua;
    this->numMov = 4;
    this->custo = 0;
    this->heuristica = funcaoHeuristica();
  };
  ~ReguaPuzzle() { this->regua.clear(); };

  // Setters
  void setN(int novoN) { this->n = novoN; };
  void setRegua(vector<char> regua) { this->regua = regua; };
  void setHeuristica(int heuristica) { this->heuristica = heuristica; }
  void setCusto(int custo) { this->custo = custo; }

  // getters
  int getN() { return this->n; };
  vector<char> getRegua() { return this->regua; };
  int getNumMovimentos() { return this->numMov; };
  Estado *getEstadoFinal() {
    return new ReguaPuzzle(this->n, this->calculaEstadoFinal());
  };
  int getCusto() { return this->custo; };
  int getHeuristica() { return this->heuristica; };

  // Função que verifica se os estados estão iguais
  bool equals(Estado *estado) {
    ReguaPuzzle *outraRegua = dynamic_cast<ReguaPuzzle *>(estado);
    return std::equal(this->regua.begin(), this->regua.end(),
                      outraRegua->getRegua().begin());
  };

  // Imprimir estado atual
  void print() {

    for (int i = 0; i <= n; i++) {
      cout << this->regua[i] << " ";
    }
  };

    // Imprimir estado atual
  void print(fstream& outputFile) {
    if(outputFile.is_open()){
    for (int i = 0; i <= n; i++) {
      outputFile << this->regua[i] << " ";
    }}
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
          */
          if (this->regua[i] == '-')
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

      if (custo)
        reguaNova->setCusto(1 + this->custo);
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

      if (custo)
        reguaNova->setCusto(1 + this->custo);
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

      if (custo)
        reguaNova->setCusto(2 + this->custo);
      break;
    }
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
      if (custo)
        reguaNova->setCusto(2 + this->custo);
      break;
    }
    default:

      break;
    }

    reguaNova->setHeuristica(reguaNova->funcaoHeuristica());

    return reguaNova;
  };

  int funcaoHeuristica() {
    if (this->calculaEstadoFinal().empty()) {
      return 0;
    } else {
      int heuristica = 0;
      int j;
      vector<char> estFinal = this->calculaEstadoFinal();
      for (j = 0; j <= ((n - 1) / 2) - 1; j++) {
        if (estFinal[j] == 'B') {
          heuristica++;
        } else {
          if (estFinal[j] != '-') {
            heuristica--;
          }
        }
      }
      if (estFinal[j + 1] == '-') {
        heuristica++;
      }

      for (int j = ((n + 1) / 2); j < (n); j++) {
        if (estFinal[j] == 'B') {
          heuristica++;
        }

        else {
          if (estFinal[j] != '-') {
            heuristica--;
          }
        }
      }

      return heuristica;
    }
  }

private:
  // Funções

  vector<char> calculaEstadoFinal() {
    vector<char> estadoFinal;

    for (int j = 0; j <= ((n - 1) / 2) - 1; j++) {
      estadoFinal.push_back('B');
    }
    estadoFinal.push_back('-');
    for (int j = ((n + 1) / 2); j < (n); j++) {
      estadoFinal.push_back('P');
    }

    return estadoFinal;
  };

  // Variaveis
  int n;
  int numMov;
  vector<char> regua;
  int heuristica;
  int custo;
};
#endif