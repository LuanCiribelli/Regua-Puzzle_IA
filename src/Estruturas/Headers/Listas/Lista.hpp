#ifndef LISTA_HPP
#define LISTA_HPP
#include <string>
#include <iostream>
#include "No.hpp"

using namespace std;

template<class T> class Lista{
    public:
        Lista();
        ~Lista();
        T getPrimeiro(){ return this->primeiro; };
        void inserir(T info);
        void remover(int index);
        T get(int index);
        bool contem(T info);
        bool estaVazio(){return this->primeiro == NULL};
        
    private:
        No<T> *primeiro;
};
#endif