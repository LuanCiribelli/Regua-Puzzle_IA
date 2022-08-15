
#ifndef REGUAPUZZLE_HPP
#define REGUAPUZZLE_HPP
#include "./Headers/Estado.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*******************************************
 * Autor: Luan Reis Ciribelli
 * Desde: 16/07/2022
 *******************************************/
class ReguaPuzzle : public Estado
{

public:
  ReguaPuzzle()
  {
    this->n = 0;
    this->regua[0] = '\0';
    this->numMov = 0;
    this->custo = 0;
    this->heuristica = 0;
    this->pai = NULL;
  };

  ReguaPuzzle(int n, vector<char> regua)
  {
    this->n = n;
    this->regua = regua;
    this->numMov = n - 1;
    this->custo = 0;
    this->heuristica = funcaoHeuristica();
    this->pai = NULL;
  };
  ReguaPuzzle(int n, vector<char> regua, int custo, int heuristica)
  {
    this->n = n;
    this->regua = regua;
    this->numMov = n - 1;
    this->custo = custo;
    this->heuristica = heuristica;
    this->pai = NULL;
  };
  ~ReguaPuzzle() { this->regua.clear(); };

  // Setters
  void setN(int novoN) { this->n = novoN; };
  void setRegua(vector<char> regua) { this->regua = regua; };
  void setHeuristica(int heuristica) { this->heuristica = heuristica; }
  void setCusto(int custo) { this->custo = custo; }
  void setPai(Estado *pai) { this->pai = pai; };

  // getters
  int getN() { return this->n; };
  vector<char> getRegua() { return this->regua; };
  int getNumMovimentos() { return this->numMov; };
  Estado *getEstadoFinal()
  {
    return new ReguaPuzzle(this->n, this->calculaEstadoFinal());
  };
  int getCusto() { return this->custo; };
  int getHeuristica() { return this->heuristica; };
  Estado *getPai() { return this->pai; };

  // Função que verifica se os estados estão iguais
  bool equals(Estado *estado)
  {
    ReguaPuzzle *outraRegua = dynamic_cast<ReguaPuzzle *>(estado);
    return this->regua == outraRegua->getRegua();
  };

  // Imprimir estado atual
  void print()
  {
    cout << "(";
    if (this->custo == 0 && this->heuristica == 0)
    {
      for (int i = 0; i <= this->n - 1; i++)
      {
        if (this->regua[i] == 'B')
        {
          cout << "B ";
        }
        else if (this->regua[i] == 'P')
        {
          cout << "P ";
        }
        else
        {
          cout << "- ";
        }
      }
      cout << ")";
    }
    else
    {
      for (int i = 0; i <= this->n - 1; i++)
      {
        if (this->regua[i] == 'B')
        {
          cout << "B ";
        }
        else if (this->regua[i] == 'P')
        {
          cout << "P ";
        }
        else
        {
          cout << "- ";
        }
      }
      cout << ")";
      cout << "[Custo: " << this->custo << "]"
           << "[Heuristica: " << this->heuristica << "] ";
    }
  };

  // Imprimir estado atual
  void print(fstream &outputFile)
  {
    outputFile << "(";
    if (outputFile.is_open())
    {
      if (this->custo == 0)
      {
        for (int i = 0; i < this->n; i++)
        {
          if (this->regua[i] == 'B')
          {
            outputFile << "B ";
          }
          else if (this->regua[i] == 'P')
          {
            outputFile << "P ";
          }
          else
          {
            outputFile << "- ";
          }
        }
        outputFile << ")";
      }
      else
      {
        for (int i = 0; i < this->n; i++)
        {
          if (this->regua[i] == 'B')
          {
            outputFile << "B ";
          }
          else if (this->regua[i] == 'P')
          {
            outputFile << "P ";
          }
          else
          {
            outputFile << "- ";
          }
        }
        outputFile << ")";
        outputFile << "[Custo: " << this->custo << "]"
                   << "[Heuristica: " << this->heuristica << "] ";
      }
    }
  };

  bool validade()
  {
    if (this->n > 0)
    {
      // Array que conta o numero de brancos, Pretos e espaços. Nessa ordem;
      int conta[3] = {0, 0, 0};
      for (int i = 0; i < this->n; i++)
      {

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

      if (conta[0] == (((this->n - 1) / 2)) &&
          conta[1] == (((this->n - 1) / 2)) && conta[2] == 1)
      {
        return true;
      }
      else
      {

        cout << "Peças brancas " << conta[0] << " Peças Pretas " << conta[1]
             << " Espaço " << conta[2] << endl;
        return false;
      }
    }
    else
    {
      return false;
    }
  };

  // Funções de estado
  Estado *movimentar(int indexMovimento, bool custo, Estado *estadoFinal)
  {
    ReguaPuzzle *reguaNova = new ReguaPuzzle(this->n, this->regua);
    reguaNova->setPai(this);
    int pos = 0;
    bool direita;
    int move;

    for (char &c : reguaNova->getRegua())
    {
      if (c == '-')
      {
        break;
      }
      else
      {
        pos++;
      }
    }

    if (indexMovimento % 2 == 0)
    {
      direita = true;
      move = (indexMovimento) / 2;
    }
    else
    {
      direita = false;
      move = (indexMovimento + 1) / 2;
    }

    /* cout<<'\n'<<"O index é: "<<indexMovimento
         <<"\n A posição do traço é: "<<pos<<'\n'
         <<"É para mover: "<<move<<" casa(s) \n";
  */
    if (direita)
    {

      if (abs(move) > ((this->n - 1) / 2) || move + pos > this->n - 1 ||
          pos > this->n - 1 || pos < 0)
      {
        reguaNova = NULL;
      }
      else
      {

        vector<char> aux = reguaNova->getRegua();
        iter_swap(aux.begin() + pos + move, aux.begin() + pos);
        reguaNova->setRegua(aux);

        if (custo)
          reguaNova->setCusto(move + this->custo);
      }
    }
    else
    {

      if (abs(move) > ((this->n - 1) / 2) || pos - move < 0 ||
          pos > this->n - 1 || pos < 0)
      {
        reguaNova = NULL;
      }
      else
      {

        vector<char> aux = reguaNova->getRegua();
        iter_swap(aux.begin() + pos - move, aux.begin() + pos);
        reguaNova->setRegua(aux);

        if (custo)
          reguaNova->setCusto(move + this->custo);
      }
    }
    if (reguaNova != NULL)
    {
      reguaNova->setHeuristica(reguaNova->funcaoHeuristica());
    }

    return reguaNova;
  };

  int funcaoHeuristica()
  {
    vector<char> heu = this->regua;
    if (heu.empty())
    {
      return 0;
    }
    else
    {
      int heuristica = 0;
      for (int j = 0; j < this->n; j++)
      {
        if (j < ((this->n - 1) / 2) && heu[j] != 'B')
        {
          heuristica += 1;
        }
        else
        {
          if (j == ((this->n - 1) / 2) && heu[j] != '-')
          {
            heuristica += 1;
          }
          else
          {
            if (j > ((this->n - 1) / 2) && heu[j] != 'P')
            {
              heuristica += 1;
            }
          }
        }
      }

      return heuristica;
    }
  }

private:
  // Funções

  vector<char> calculaEstadoFinal()
  {
    vector<char> estadoFinal;

    for (int j = 0; j <= ((n - 1) / 2) - 1; j++)
    {
      estadoFinal.push_back('B');
    }
    estadoFinal.push_back('-');
    for (int j = ((n + 1) / 2); j < (n); j++)
    {
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
  Estado *pai;
};
#endif