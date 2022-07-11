#ifndef FILA_HPP
#define FILA_HPP
#include <string>
#include <iostream>
#include "No.hpp"

using namespace std;
/*******************************************
 * Autor: João Pedro de Carvalho Lima
 * Desde: 11/05/2022
*******************************************/
template <class T>
class Fila
{
public:
    Fila()
    {
        this->primeiro = NULL;
    };
    ~Fila()
    {
        while (this->primeiro != NULL)
        {
            remover();
        }
    };
    void inserir(T info)
    {
        if (this->primeiro == NULL)
        {
            this->primeiro = new No<T>(info, NULL);
        }
        else
        {
            No<T> *p = this->primeiro;
            while (p->getProx() != NULL)
            {
                p = p->getProx();
            }
            p->setProx(new No<T>(info, NULL));
        }
    };
    T remover()
    {
        if (this->primeiro == NULL)
        {
            cout << "[ERROR] Fila vazia! Impossivel remover!" << endl;
            exit(-1);
        }
        else
        {
            No<T> *p = this->primeiro;
            T info = p->getInfo();
            this->primeiro = p->getProx();
            delete p;
            return info;
        }
    };
    bool estaVazio() { return this->primeiro == NULL; };

private:
    No<T> *primeiro;
};
#endif