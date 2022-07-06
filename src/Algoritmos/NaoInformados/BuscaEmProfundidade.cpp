#ifndef BUSCA_EM_PROFUNDIDADE_CPP
#define BUSCA_EM_PROFUNDIDADE_CPP
#include <string>
#include <iostream>
#include "../../Estruturas/Headers/Estado.hpp"
#include "../../Estruturas/Headers/Listas/Pilha.hpp"
#include "../../Estruturas/Headers/Listas/Lista.hpp"

using namespace std;

class BuscaEmProfundidade{
    public:
        static void run(Estado* inicial, Estado* final){
            short status = 0; // -1 = FRACASSO; 1 = SUCESSO; 0 = EM PROCESSO
            Pilha<Estado*>* abertos = new Pilha<Estado*>();
            Lista<Estado*>* fechados = new Lista<Estado*>();           
            Estado* atual;
            Estado* aux;
            abertos->inserir(inicial);
            while(status != 0){
                if(abertos->estaVazio()){
                    status = -1;
                } else {
                    atual = abertos->remover();
                    if(atual->equals(final)){
                        status = 1;
                    } else {
                        for(int i = 1; i <= inicial->numMovimentos(); i++){
                            aux = atual->movimentar(i);
                            if(aux != NULL && !fechados->contem(aux)){
                                abertos->inserir(aux);
                            }
                        }
                        fechados->inserir(atual);
                    }
                }
            }
        }
};
#endif