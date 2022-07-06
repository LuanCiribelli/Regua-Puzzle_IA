#include <iostream>
#include <cstdlib>
#include <fstream>
#include "../../Headers/Listas/Lista.hpp"
#include "../../Headers/Listas/No.hpp"

using namespace std;

template<class T> Lista<T>::Lista(){
    this->primeiro = NULL;
}

template<class T> Lista<T>::~Lista(){
    while(this->primeiro != NULL){
        remover();
    }
}

template<class T> void Lista<T>::inserir(T info){
    if(this->primeiro == NULL){
        this->primeiro = new No<T>(info, NULL);
    } else {
        No<T> p = this->primeiro;
        while(p->getProx() != NULL){
            p = p->getProx();
        }
        p->setProx(new No<T>(info, NULL));
    }
}

template<class T> void Lista<T>::remover(int index){
    if(this->primeiro == NULL){
        cout << "[ERROR] Lista vazia! Impossivel remover!" << endl
        exit(-1);
    } else if (index < 0) {
        cout << "[ERROR] Index menor que zero! Impossivel remover!" << endl
        exit(-1);
    } else {
        No<T> p = this->primeiro;
        int count = 0;
        while(p->getProx() != NULL && count < index - 1){
            p = p->getProx();
        }
        if(p->getProx() == NULL){
            cout << "[ERROR] Index maior que o tamanho da lista! Impossivel remover!" << endl
            exit(-1);
        } else {
            No<T> t = p->getProx();
            p->setProx(t->getProx());
            delete t;
        }
    }
}

template<class T> T Lista<T>::get(int index){
    if(this->primeiro == NULL){
        cout << "[ERROR] Lista vazia! Impossivel obter!" << endl
        exit(-1);
    } else if (index < 0) {
        cout << "[ERROR] Index menor que zero! Impossivel obter!" << endl
        exit(-1);
    } else {
        No<T> p = this->primeiro;
        int count = 0;
        while(p != NULL && count < index){
            p = p->getProx();
        }
        if(p == NULL){
            cout << "[ERROR] Index maior que o tamanho da lista! Impossivel obter!" << endl
            exit(-1);
        } else {
            return p->getInfo();
        }
    }
}

template<class T> bool Lista<T>::contem(T info){
    No<T> p = this->primeiro;
    while(p != NULL){
        if(p->getInfo() == info){
            return true;
        } else {
            p = p->getProx();
        }
    }
    return false;
}