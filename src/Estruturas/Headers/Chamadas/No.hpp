#ifndef NO_ESTADO_HPP
#define NO_ESTADO_HPP
#include <string>
#include <iostream>
#include "../Estado.hpp"

using namespace std;

class No{
    private:
        Estado* estado;
        No* prox;
        int idPai;
        bool fechado;
    public:
        No();
        No(Estado* estado, No* prox, int idPai, bool fechado);
        ~No() {};
        Estado* getEstado() { return this->estado; };
        No* getProx() { return this->prox; };
        int getIdPai() { return this->idPai; };
        bool getFechado() { return this->fechado; };
        void setEstado(Estado* estado) { this->estado = estado; };
        void setProx(No *prox) { this->prox = prox; };
        void setIdPai(int idPai) { this->idPai = idPai; };
        void setFechado(bool fechado) { this->fechado = fechado; };
};
#endif