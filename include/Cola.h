#ifndef COLA_H
#define COLA_H
#include <iostream>
#include "CajaCola.h"
#include "CajaCola.h"
using namespace std;

class CajaCola;
class nodo;
class Cola
{
public:
    Cola();//Constructor de Cola
    virtual ~Cola();//Destructor de la cola.
    void Vaciar();
    bool Vacia();
    void Agregar(nodo *n);
    nodo * Sacar();
    nodo * Frente();
    void mostrarEnPantalla();
    CajaCola *ultim;
    CajaCola *prim;
protected:
private:
};

#endif // COLA_H
