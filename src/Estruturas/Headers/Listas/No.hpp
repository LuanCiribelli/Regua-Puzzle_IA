#ifndef NO_HPP
#define NO_HPP
#include <string>
#include <iostream>

using namespace std;
template <class T>
class No
{
private:
    T info;
    No<T> *prox;

public:
    No()
    {
        this->info = NULL;
        this->prox = NULL;
    }
    No(T info, No<T> *prox)
    {
        this->info = info;
        this->prox = prox;
    };
    ~No(){};
    T getInfo() { return this->info; };
    No *getProx() { return this->prox; };
    void setInfo(T info) { this->info = info; };
    void setProx(No *prox) { this->prox = prox; };
};
#endif