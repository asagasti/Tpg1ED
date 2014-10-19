#include "CajSubLSE1.h"

CajSubLSE1::CajSubLSE1()
{
    ptrMiElem=0;
    sig=0;//ctor
}

CajSubLSE1::CajSubLSE1(CajLSE *h){
    ptrMiElem=h;
    sig=0;//ctor
}

CajSubLSE1::CajSubLSE1(CajLSE *h, CajSubLSE1 *miSig){
    ptrMiElem=h;
    sig=miSig;//ctor
}

CajSubLSE1::~CajSubLSE1()
{
    delete this;//dtor
}


