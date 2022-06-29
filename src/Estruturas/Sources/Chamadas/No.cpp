#include "../../Headers/Chamadas/No.hpp"

No::No(){
    this->estado = NULL;
    this->prox = NULL;
    this->idPai = -1;
    this->fechado = false;
}

No::No(Estado* estado, No* prox, int idPai, bool fechado)
{
    this->estado = estado;
    this->prox = prox;
    this->idPai = idPai;
    this->fechado = fechado;
}