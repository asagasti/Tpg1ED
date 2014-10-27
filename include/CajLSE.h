#ifndef NODO_H
#define NODO_H
#include "CajSubLSE1.h"
#include <iostream>


using namespace std;
class CajSubLSE1;
class nodo
{
public:
    nodo();
    nodo(int i);
    virtual ~nodo();
    void borrarHijo(nodo *aBorrar);
    void agregarHijo(nodo *h);
    bool esPadreDe(nodo *posibleHijo);
    bool EsHoja();
    void mostrarHijosPantalla();
    CajSubLSE1 * HMI;
    nodo * sig;
    int miElem;
protected:
private:
};

#endif // CAJLSE_H
