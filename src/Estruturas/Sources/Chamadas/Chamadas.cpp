#include <iostream>
#include <cstdlib>
#include <fstream>
#include "../../Headers/Chamadas/Chamadas.hpp"
#include "../../Headers/Chamadas/No.hpp"

using namespace std;

Chamadas::Chamadas(){
    this->primeiro = NULL;
}

Chamadas::~Chamadas(){
    No* p = this->primeiro;
    No* t;
    while(p != NULL){
        t = p->getProx();
        delete p;
        p = t;
    }
}

No* Chamadas::get(int index){
    if(index < 0) {
        cout << "[ERROR]: Index menor que 0" << endl;
    } else if(this->primeiro == NULL) {
        return NULL;
    } else {
        No* p = this->primeiro;
        for(int i = 0; i < index; i++){
            p = p->getProx();
        }
        return p;
    } 
}
