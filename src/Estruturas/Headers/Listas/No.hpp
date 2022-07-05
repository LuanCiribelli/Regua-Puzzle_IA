#ifndef NO_HPP
#define NO_HPP
#include <string>
#include <iostream>

using namespace std;
template<class T>

class No{
    private:
        T* info;
        No* prox;
        int idPai;
        bool fechado;
    public:
        No();
        No(T* info, No* prox);
        ~No() {};
        T* getInfo() { return this->info; };
        No* getProx() { return this->prox; };
        void setInfo(T* info) { this->T = info; };
        void setProx(No *prox) { this->prox = prox; };
};
#endif