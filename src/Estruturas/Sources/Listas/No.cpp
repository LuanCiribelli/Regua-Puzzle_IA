#include "../../Headers/Listas/No.hpp"

template<class T> No<T>::No(){
    this->info = NULL;
    this->prox = NULL;
}

template<class T> No<T>::No(T* info, No<T>* prox)
{
    this->info = info;
    this->prox = prox;
}