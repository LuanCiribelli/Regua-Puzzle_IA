#ifndef JARROS_HPP
#define JARROS_HPP
#include <string>
#include <iostream>

using namespace std;

class Jarros: public Estado {
    private:
        int* jarros;
    public:
        Jarros(){
            jarros = new int[2];
            jarros[0] = 0;
            jarros[1] = 0;
        }
        ~Jarros(){
            delete [] this->jarros;
        }
        void toString(){
            cout << jarros[0] << " , " << jarros[1] << endl;
        }
        void set(int jarro, int quantidade){
            this->jarros[jarro] = quantidade;
        }
        int get(int jarro){
            return this->jarros[jarro];
        }
        Estado* movimentar(int indexMovimento){
            Jarros* newJarros = new Jarros();
            newJarros->set(0, jarros[0]);
            newJarros->set(1, jarros[1]);
            switch(indexMovimento){
                case 1:{
                    newJarros->set(0,5);
                    break;
                }
                case 2:{
                    newJarros->set(1,3);
                }
                case 3:{
                    newJarros->set(0,newJarros->get(1));
                    newJarros->set(1,newJarros->get(0) - 5);
                    if(newJarros->get(1) < 0){
                        newJarros->set(1,0);
                    } else {
                        newJarros->set(0,5);
                    }
                    break;
                }
                case 4:{
                    newJarros->set(1,newJarros->get(0));
                    newJarros->set(0,newJarros->get(1) - 3);
                    if(newJarros->get(0) < 0){
                        newJarros->set(0,0);
                    } else {
                        newJarros->set(1,3);
                    }
                    break;
                }
                default:
                    return NULL;
            }
            newJarros->toString();
            return newJarros;
        }
};
#endif