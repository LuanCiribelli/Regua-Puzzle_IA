#include <iostream>
#include <cstdlib>
#include <fstream>
#include "../../Headers/Listas/Fila.hpp"
#include "../../Headers/Listas/No.hpp"

using namespace std;

template<class T> Fila<T>::Fila(){
    this->primeiro = NULL;
}

template<class T> Fila<T>::~Fila(){
    while(this->primeiro != NULL){
        remover();
    }
}

template<class T> void Fila<T>::inserir(T info){
    if(this->primeiro == NULL){
        this->primeiro = new No<T>(info, NULL);
    } else {
        No<T> p = this->primeiro;
        while(p->getProx() != NULL){
            p = p->getProx();
        }
        p->setProx(new No<T>(info, this->primeiro));
    }
}

template<class T> T Fila<T>::remover(){
    if(this->primeiro == NULL){
        cout << "[ERROR] Fila vazia! Impossivel remover!" << endl
        exit(-1);
    } else if {
        No<T> p = this->primeiro;
        T* info = p->getInfo();
        this->primeiro = p->getProx();
        delete p;
    }
}

