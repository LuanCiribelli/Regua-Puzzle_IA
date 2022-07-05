#ifndef BUSCA_EM_PROFUNDIDADE_CPP
#define BUSCA_EM_PROFUNDIDADE_CPP
#include <string>
#include <iostream>
#include "../../Estruturas/Headers/Estado.hpp"
#include "../../Estruturas/Headers/Listas/Pilha.hpp"

using namespace std;

class BuscaEmProfundidade{
    public:
        static void run(Estado* inicial, Estado* final){
            short status = 0; // -1 = FRACASSO; 1 = SUCESSO; 0 = EM PROCESSO
            Pilha<Estado*> abertos;
            Estado* atual;
            abertos.inserir(inicial);
            while(status != 0){
                if(abertos.estaVazio()){
                    status = -1;
                } else {
                    atual = abertos.getTopo();
                    if(atual->equals(final)){
                        status = 1;
                    } else {
                        
                    }
                }
            }
        }
};
#endif