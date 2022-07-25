#ifndef LISTA_HPP
#define LISTA_HPP
#include <string>
#include <iostream>
#include "No.hpp"

using namespace std;
/*******************************************
 * Autor: João Pedro de Carvalho Lima
 * Desde: 11/05/2022
 *******************************************/
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
        limpar();
    };
    void limpar(){
        No<T> *p = this->primeiro;
        while (this->primeiro != NULL)
        {
            this->primeiro = this->primeiro->getProx();
            delete p;
            p = this->primeiro;
        }
    }
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
    void inserir(T info, int index)
    {
        if (index < 0)
        {
            cout << "[ERROR] Index negativo! Impossível adicionar na lista" << endl;
            exit(-1);
        }
        else if (index == 0 && this->primeiro == NULL)
        {
            this->primeiro = new No<T>(info, NULL);
        }
        else if (index == 0 && this->primeiro != NULL)
        {
            No<T> *p = this->primeiro;
            No<T> *t = new No<T>(info, p);
            this->primeiro = t;
        }
        else if (index == this->getTamanho())
        {
            this->inserir(info);
        }
        else
        {
            No<T> *p = this->primeiro;
            int count = 1;
            while (p->getProx() != NULL && count < index - 1)
            {
                p = p->getProx();
                count += 1;
            }
            if (p->getProx() == NULL)
            {
                cout << "[ERROR] Index maior que o tamanho da lista! Impossível adicionar na lista" << endl;
                exit(-1);
            }
            else
            {
                No<T> *t = new No<T>(info, p->getProx());
                p->setProx(t);
            }
        }
    }
    T remover(int index)
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
        else if (index == 0)
        {
            No<T> *t = this->primeiro;
            this->primeiro = this->primeiro->getProx();
            T result = t->getInfo();
            delete t;
            return result;
        }
        else
        {
            No<T> *p = this->primeiro;
            int count = 1;
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
                No<T> *t = p->getProx();
                p->setProx(t->getProx());
                T result = t->getInfo();
                delete t;
                return result;
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
                count += 1;
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
    int getTamanho()
    {
        int tamanho = 0;
        No<T> *p = this->primeiro;
        while (p != NULL)
        {
            p = p->getProx();
            tamanho += 1;
        }
        return tamanho;
    }

private:
    No<T> *primeiro;
};
#endif