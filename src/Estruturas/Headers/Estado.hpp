#ifndef ESTADO_HPP
#define ESTADO_HPP
#include <string>
#include <iostream>

using namespace std;
/*******************************************
 * Autor: João Pedro de Carvalho Lima
 * Desde: 11/05/2022
*******************************************/
class Estado
{
public:
    virtual ~Estado(){};
    virtual int numMovimentos() { return -1; };
    virtual Estado *movimentar(int indexMovimento)
    {
        cout << "Estado vazio: movimentar" << endl;
        return NULL;
    };
    virtual void print()
    {
        cout << "Estado vazio: toString" << endl;
    };

    virtual bool equals(Estado *estado)
    {
        cout << "Estado vazio: equals" << endl;
        return false;
    }
    bool operator==(Estado &rhs)
    {
        return this->equals(&rhs);
    };
    bool operator==(Estado *rhs)
    {
        return this->equals(rhs);
    };
};
#endif