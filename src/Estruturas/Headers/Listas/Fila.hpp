#ifndef FILA_HPP
#define FILA_HPP
#include <string>
#include <iostream>
#include "No.hpp"

using namespace std;

template<class T> class Fila{
    public:
        Fila();
        ~Fila();
        void inserir(T info);
        T remover();
        bool estaVazio(){return this->topo == NULL};
        
    private:
        No<T> *primeiro;
};
#endif