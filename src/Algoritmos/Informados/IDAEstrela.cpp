#ifndef IDAESTRELA_CPP
#define IDAESTRELA_CPP
#include "../../Estruturas/Headers/Estado.hpp"
#include "../../Estruturas/Headers/Listas/Lista.hpp"
#include "../../Estruturas/Headers/Listas/Pilha.hpp"
#include "../../Estruturas/Headers/Resultado.hpp"
#include <iostream>
#include <string>

using namespace std;
/*******************************************
 * Autores: João Pedro Lima e Luan Reis Ciribelli
 * Desde: 25/07/2022
 *******************************************/

class IDAEstrela
{
public:
  static void run(Estado *inicial, Estado *final)
  {
    short status = 0; // -1 = FRACASSO; 1 = SUCESSO; 0 = EM PROCESSO
    int patamar_old = -1;
    int patamar = inicial->getPatamar(final);
    Estado *atual;
    Estado *aux;
    Pilha<Estado *> *abertos = new Pilha<Estado *>();
    Pilha<int> *movimentos = new Pilha<int>();
    Lista<Estado *> *descartados = new Lista<Estado *>();

    abertos->inserir(inicial);
    movimentos->inserir(inicial->getNumMovimentos());
    while (status == 0)
    {
      cout << "[Patamar: " << patamar << "][Patamar_Old: " << patamar_old << "]"
           << endl;

      if (patamar_old == patamar)
      {
        cout << "FRACASSO" << endl;

        status = -1;
      }
      else
      {
        atual = abertos->get();
        atual->print();

        if (atual->equals(final))
        {
          cout << "\nSUCESSO" << endl;

          status = 1;
        }
        else
        {
          if (atual->getPatamar(final) > patamar)
          {
            descartados->inserir(abertos->remover());
            movimentos->remover();
            atual = abertos->get();
          }
          while (movimentos->get() > 0)
          {
            aux = atual->movimentar(movimentos->get(), true, final);
            movimentos->inserir(movimentos->remover() - 1);
            if (aux != NULL && !abertos->contem(aux))
            {
              abertos->inserir(aux);
              movimentos->inserir(inicial->getNumMovimentos());
              cout << "-->";

              aux->print();

              cout << endl;

              break;
            }
          }
          if (movimentos->get() == 0)
          {
            if (abertos->get() == inicial)
            {
              patamar_old = patamar;
              if (!descartados->estaVazio())
              {
                patamar = descartados->get(0)->getPatamar(final);
                for (int i = 1; i < descartados->getTamanho(); i++)
                {
                  if (descartados->get(i)->getPatamar(final) < patamar)
                  {
                    patamar = descartados->get(i)->getPatamar(final);
                  }
                }
                descartados->limpar();
              }
              movimentos->inserir(inicial->getNumMovimentos());
              cout << "--> NULL (Atualizando Patamar_Old)" << endl;
            }
            else
            {
              delete abertos->remover();
              movimentos->remover();
              cout << "--> NULL" << endl;
            }
          }
        }
      }
    }
  }
  static void run(Estado *inicial, Estado *final, fstream &outputFile)
  {
    Resultado resultado;
    short status = 0; // -1 = FRACASSO; 1 = SUCESSO; 0 = EM PROCESSO
    int patamar_old = -1;
    int patamar = inicial->getPatamar(final);
    Estado *atual;
    Estado *aux;
    Pilha<Estado *> *abertos = new Pilha<Estado *>();
    Pilha<int> *movimentos = new Pilha<int>();
    Lista<Estado *> *descartados = new Lista<Estado *>();

    abertos->inserir(inicial);
    movimentos->inserir(inicial->getNumMovimentos());
    while (status == 0)
    {
      cout << "[Patamar: " << patamar << "][Patamar_Old: " << patamar_old << "]"
           << endl;
      outputFile << "[Patamar: " << patamar << "][Patamar_Old: " << patamar_old
                 << "]" << endl;
      if (patamar_old == patamar)
      {
        cout << "FRACASSO" << endl;
        outputFile << "FRACASSO" << endl;
        resultado.sucesso = false;
        resultado.custoDaSolucao = -1;
        status = -1;
      }
      else
      {
        atual = abertos->get();
        atual->print();
        atual->print(outputFile);
        if (atual->equals(final))
        {
          cout << "\nSUCESSO" << endl;
          outputFile << "\nSUCESSO" << endl;
          resultado.sucesso = true;
          resultado.custoDaSolucao = atual->getCusto();
          status = 1;
        }
        else
        {
          if (atual->getPatamar(final) > patamar)
          {
            descartados->inserir(abertos->remover());
            movimentos->remover();
            atual = abertos->get();
          }
          while (movimentos->get() > 0)
          {
            aux = atual->movimentar(movimentos->get(), true, final);
            movimentos->inserir(movimentos->remover() - 1);
            if (aux != NULL && !abertos->contem(aux))
            {
              abertos->inserir(aux);
              movimentos->inserir(inicial->getNumMovimentos());
              resultado.nosVisitados += 1;
              cout << "-->";
              outputFile << "-->";
              aux->print();
              aux->print(outputFile);
              cout << endl;
              outputFile << endl;
              break;
            }
          }
          if (movimentos->get() == 0)
          {
            resultado.nosExpandidos += 1;
            if (abertos->get() == inicial)
            {
              patamar_old = patamar;
              if (!descartados->estaVazio())
              {
                patamar = descartados->get(0)->getPatamar(final);
                for (int i = 1; i < descartados->getTamanho(); i++)
                {
                  if (descartados->get(i)->getPatamar(final) < patamar)
                  {
                    patamar = descartados->get(i)->getPatamar(final);
                  }
                }
                descartados->limpar();
              }
              movimentos->inserir(inicial->getNumMovimentos());
              cout << "--> NULL (Atualizando Patamar_Old)" << endl;
              outputFile << "--> NULL (Atualizando Patamar_Old)" << endl;
            }
            else
            {
              delete abertos->remover();
              movimentos->remover();
              cout << "--> NULL" << endl;
              outputFile << "--> NULL" << endl;
            }
          }
        }
      }
    }
    if (resultado.sucesso)
        {
            outputFile << "CAMINHO:\n"
                 << endl;
            aux = atual;
            while (aux != NULL)
            {
                resultado.profundidade += 1;
                aux->print(outputFile);
                outputFile << endl;
                aux = aux->getPai();
            }
            outputFile << "PROFUNDIDADE: " << resultado.profundidade << endl;
            outputFile << "CUSTO DA SOLUÇÃO: " << resultado.custoDaSolucao << endl;
        }
        outputFile << "NÓS EXPANDIDOS: " << resultado.nosExpandidos << endl;
        outputFile << "NÓS VISITADOS: " << resultado.nosVisitados << endl;
        outputFile << "FATOR DE RAMIFICAÇÃO (VISTADOS/EXPANDIDOS): " << (float)resultado.nosVisitados / resultado.nosExpandidos << endl;
    }
  };

#endif