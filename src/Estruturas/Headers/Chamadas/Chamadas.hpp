#ifndef LISTA_ADJACENCIA_ESTADO_HPP
#define LISTA_ADJACENCIA_ESTADO_HPP
#include <string>
#include <iostream>
#include "No.hpp"
#include "../Estado.hpp"

using namespace std;

class Chamadas{
    public:
        Chamadas();
        ~Chamadas();
        No* get(int inserir);
        void inserir(Estado* estado, No* prox, int idPai, bool fechado);
    private:
        No *primeiro;
};
#endif