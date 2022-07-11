#ifndef PILHA_HPP
#define PILHA_HPP
#include <string>
#include <iostream>
#include "No.hpp"

using namespace std;
/*******************************************
 * Autor: João Pedro de Carvalho Lima
 * Desde: 11/05/2022
*******************************************/
template <class T>
class Pilha
{
public:
    Pilha()
    {
        this->topo = NULL;
    };
    ~Pilha()
    {
        while (this->topo != NULL)
        {
            remover();
        }
    };
    void inserir(T info)
    {
        if (this->topo == NULL)
        {
            this->topo = new No<T>(info, NULL);
        }
        else
        {
            No<T> *p = new No<T>(info, this->topo);
            this->topo = p;
        }
    };
    T remover()
    {
        if (this->topo == NULL)
        {
            cout << "[ERROR] Pilha vazia! Impossivel remover!" << endl;
            exit(-1);
        }
        else
        {
            No<T> *p = this->topo;
            T info = p->getInfo();
            this->topo = p->getProx();
            delete p;
            return info;
        }
    };
    bool estaVazio() { return this->topo == NULL; };

private:
    No<T> *topo;
};
#endif