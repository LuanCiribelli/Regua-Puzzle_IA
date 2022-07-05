#include <iostream>
#include <cstdlib>
#include <fstream>
#include "../../Headers/Listas/Pilha.hpp"
#include "../../Headers/Listas/No.hpp"

using namespace std;

template<class T> Pilha<T>::Pilha(){
    this->topo = NULL;
}

template<class T> Pilha<T>::~Pilha(){
    while(this->topo != NULL){
        remover();
    }
}

template<class T> void Pilha<T>::inserir(T info){
    if(this->topo == NULL){
        this->topo = new No<T>(info, NULL);
    } else {
        No<T> p = new No<T>(info, this->topo);
        this->topo = p;
    }
}

template<class T> T Pilha<T>::remover(){
    if(this->topo == NULL){
        cout << "[ERROR] Pilha vazia! Impossivel remover!" << endl
        exit(-1);
    } else {
        No<T> p = this->topo;
        T* info = p->getInfo();
        this->topo = p->getProx();
        delete p;
    }
}

