#ifndef LISTA_HPP
#define LISTA_HPP
#include <string>
#include <iostream>
#include "No.hpp"

using namespace std;

template <class T>
class Lista
{
public:
    Lista()
    {
        this->primeiro = NULL;
    };
    ~Lista()
    {
        while (this->primeiro != NULL)
        {
            remover();
        }
    };
    T getPrimeiro() { return this->primeiro; };
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
    void remover(int index)
    {
        if (this->primeiro == NULL)
        {
            cout << "[ERROR] Lista vazia! Impossivel remover!" << endl;
            exit(-1);
        }
        else if (index < 0)
        {
            cout << "[ERROR] Index menor que zero! Impossivel remover!" << endl;
            exit(-1);
        }
        else
        {
            No<T> p = this->primeiro;
            int count = 0;
            while (p->getProx() != NULL && count < index - 1)
            {
                p = p->getProx();
            }
            if (p->getProx() == NULL)
            {
                cout << "[ERROR] Index maior que o tamanho da lista! Impossivel remover!" << endl;
                exit(-1);
            }
            else
            {
                No<T> t = p->getProx();
                p->setProx(t->getProx());
                delete t;
            }
        }
    };
    T get(int index)
    {
        if (this->primeiro == NULL)
        {
            cout << "[ERROR] Lista vazia! Impossivel obter!" << endl;
            exit(-1);
        }
        else if (index < 0)
        {
            cout << "[ERROR] Index menor que zero! Impossivel obter!" << endl;
            exit(-1);
        }
        else
        {
            No<T> *p = this->primeiro;
            int count = 0;
            while (p != NULL && count < index)
            {
                p = p->getProx();
            }
            if (p == NULL)
            {
                cout << "[ERROR] Index maior que o tamanho da lista! Impossivel obter!" << endl;
                exit(-1);
            }
            else
            {
                return p->getInfo();
            }
        }
    };
    bool contem(T info)
    {
        No<T> *p = this->primeiro;
        while (p != NULL)
        {
            if (p->getInfo()->operator==(info))
            {
                return true;
            }
            else
            {
                p = p->getProx();
            }
        }
        return false;
    };
    bool estaVazio() { return this->primeiro == NULL; };

private:
    No<T> *primeiro;
};
#endif