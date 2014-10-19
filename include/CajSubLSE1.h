#ifndef CAJSUBLSE1_H
#define CAJSUBLSE1_H
#include "CajLSE.h"

class CajLSE;

class CajSubLSE1
{
public:
    CajSubLSE1();
    CajSubLSE1(CajLSE *h);
    CajSubLSE1(CajLSE *h, CajSubLSE1 *miSig);
    virtual ~CajSubLSE1();
    CajLSE *ptrMiElem;
    CajSubLSE1 *sig;
protected:
private:
};

#endif // CAJSUBLSE1_H
