#include <new>        //requerido para crear Memoria din�mica
#include "CajaCola.h"

//definici�n del m�todo que crea un caja vac�o
CajaCola::CajaCola()
{
    usado=false;
    ptrSig=0;
}

//definici�n del m�todo que crea un caja con un valor asignado
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
