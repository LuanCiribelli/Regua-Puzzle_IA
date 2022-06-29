#ifndef ESTADO_HPP
#define ESTADO_HPP
#include <string>
#include <iostream>

using namespace std;

class Estado{
    public:
        virtual ~Estado(){};
        virtual Estado* movimentar(int indexMovimento){
            cout << "Estado vazio: movimentar" << endl;
            return NULL;
        };
        virtual void toString(){
            cout << "Estado vazio: toString" << endl;
        };
        virtual bool equals(Estado* estado){
            cout << "Estado vazio: equals" << endl;
            return false;
        }
};
#endif