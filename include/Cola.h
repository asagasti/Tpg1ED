#ifndef COLA_H
#define COLA_H
#include <iostream>
#include "CajaCola.h"
using namespace std;

class CajaCola;

class Cola
{
public:
    Cola();//Constructor de Cola
    virtual ~Cola();//Destructor de la cola.
    void Vaciar();
    bool Vacia();
    void Agregar(int elem);
    int Sacar();
    int Frente();
    void mostrarEnPantalla();
    CajaCola *ultim;
    CajaCola *prim;
protected:
private:
};

#endif // COLA_H


