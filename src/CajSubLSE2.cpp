#include "CajSubLSE2.h"

CajSubLSE2::CajSubLSE2()
{
    ptrMiElem=0;
    sig=0;//ctor
}

CajSubLSE2::CajSubLSE2(nodo *h){
    ptrMiElem=h;
    sig=0;//ctor
}

CajSubLSE2::CajSubLSE2(nodo *h, CajSubLSE2 *miSig){
    ptrMiElem=h;
    sig=miSig;//ctor
}

CajSubLSE2::~CajSubLSE2()
{
    delete this;//dtor
}
