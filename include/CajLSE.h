#ifndef CAJLSE_H
#define CAJLSE_H
#include "CajSubLSE1.h"
#include <iostream>


using namespace std;
class CajSubLSE1;
class CajLSE
{
public:
    CajLSE();
    CajLSE(int i);
    virtual ~CajLSE();
    void borrarHijo(CajLSE *aBorrar);
    void agregarHijo(CajLSE *h);
    bool esPadreDe(CajLSE *posibleHijo);
    bool EsHoja();
    void mostrarHijosPantalla();
    CajSubLSE1 * HMI;
    CajLSE * sig;
    int miElem;
protected:
private:
};

#endif // CAJLSE_H
