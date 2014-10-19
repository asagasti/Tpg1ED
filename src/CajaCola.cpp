#include <new>        //requerido para crear Memoria dinámica
#include "CajaCola.h"

//definición del método que crea un caja vacío
CajaCola::CajaCola()
{
    usado=false;
    ptrSig=0;
}

//definición del método que crea un caja con un valor asignado
CajaCola::CajaCola(int v)
{
    val=v;
    usado=true;
    ptrSig=0;
}


CajaCola::~CajaCola()
{
    //delete this;
}


void CajaCola::ponValor(int v)
{
    val=v;
    usado=true;
    ptrSig=0;
}


int CajaCola::obValor()
{
    return val;
}


bool CajaCola::estaUsado()
{
    return usado;
}


CajaCola *CajaCola::obSig()
{
    return ptrSig;
}

void CajaCola::ponSig(CajaCola *c)
{
    ptrSig=c;
}
