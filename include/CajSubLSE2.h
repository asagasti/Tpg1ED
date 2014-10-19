#ifndef CAJSUBLSE2_H
#define CAJSUBLSE2_H
#include "CajaLisArray.h"
class nodo;
class CajSubLSE2
{
public:
    CajSubLSE2();
    CajSubLSE2(nodo *h);
    CajSubLSE2(nodo *h, CajSubLSE2 *miSig);
    virtual ~CajSubLSE2();
    nodo *ptrMiElem;
    CajSubLSE2 * sig;
protected:
private:
};

#endif // CAJSUBLSE2_H
