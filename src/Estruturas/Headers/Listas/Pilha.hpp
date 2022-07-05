#ifndef PILHA_HPP
#define PILHA_HPP
#include <string>
#include <iostream>
#include "No.hpp"

using namespace std;

template<class T> class Pilha{
    public:
        Pilha();
        ~Pilha();
        T getTopo(){ return this->topo; };
        void inserir(T info);
        T remover();
        bool estaVazio(){return this->topo == NULL};
        
    private:
        No<T> *topo;
};
#endif