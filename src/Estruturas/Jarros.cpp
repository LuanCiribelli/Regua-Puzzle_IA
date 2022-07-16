#ifndef JARROS_HPP
#define JARROS_HPP
#include <string>
#include <iostream>
#include "./Headers/Estado.hpp"
using namespace std;

class Jarros : public Estado
{
private:
    const int MAX_JARRO1 = 5;
    const int MAX_JARRO2 = 3;
    int jarro1;
    int jarro2;

public:
    Jarros(int a, int b)
    {
        this->jarro1 = a;
        this->jarro2 = b;
    }
    ~Jarros()
    {
    }
    void print()
    {
        cout << "(" << this->jarro1 << " , " << this->jarro2 << ")";
    }
    void setJarro1(int quantidade)
    {
        this->jarro1 = quantidade;
    }
    void setJarro2(int quantidade)
    {
        this->jarro2 = quantidade;
    }
    int getJarro1()
    {
        return this->jarro1;
    }
    int getJarro2()
    {
        return this->jarro2;
    }

    int getNumMovimentos() { return 6; };
    Estado *movimentar(int indexMovimento)
    {
        Jarros *jarros = new Jarros(this->jarro1, this->jarro2);
        switch (indexMovimento)
        {
        case 1:
        {
            jarros->setJarro1(MAX_JARRO1);
            break;
        }
        case 2:
        {
            jarros->setJarro2(MAX_JARRO2);
            break;
        }
        case 3:
        {
            jarros->setJarro1(0);
            break;
        }
        case 4:
        {
            jarros->setJarro2(0);
            break;
        }
        case 5:
        {
            jarros->setJarro2(jarros->getJarro1());
            jarros->setJarro1(0);
            if (jarros->getJarro2() - MAX_JARRO2 > 0)
            {
                jarros->setJarro1(jarros->getJarro2() - MAX_JARRO2);
                jarros->setJarro2(MAX_JARRO2);
            }
            break;
        }
        case 6:
        {
            jarros->setJarro1(jarros->getJarro2());
            jarros->setJarro2(0);
            if (jarros->getJarro1() - MAX_JARRO1 > 0)
            {
                jarros->setJarro2(jarros->getJarro1() - MAX_JARRO1);
                jarros->setJarro1(MAX_JARRO1);
            }
            break;
        }
        default:
            break;
        }
        if (this->equals(jarros))
        {
            delete jarros;
            return NULL;
        }
        else
        {
            return jarros;
        }
    }

    bool equals(Estado *estado)
    {
        Jarros *outroJarro = dynamic_cast<Jarros *>(estado);
        return ((this->jarro1 == outroJarro->getJarro1() || this->jarro1 < 0 || outroJarro->getJarro1() < 0) 
        && (this->jarro2 == outroJarro->getJarro2() || this->jarro2 < 0 || outroJarro->getJarro2() < 0));
    }
};
#endif