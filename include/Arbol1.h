#ifndef ARBOL1_H
#define ARBOL1_H
#include "CajLSE.h"
#include <iostream>


using namespace std;
class CajLSE;
class Arbol
{
public:
    Arbol();///probado
    virtual ~Arbol();///probado
    void Vaciar();///probado
    bool Vacio();///probado
    void PoneRaiz(int elem);///probado
    void AgregaHijo(CajLSE *padre, int e);///probado
    void BorraHoja(CajLSE *aBorrar);///probado
    void ModificaEtiqueta(CajLSE *aCambiar, int elem);///probado
    CajLSE * Raiz();///probado
    CajLSE *Padre(CajLSE *hijo);///probado
    CajLSE *Pertenece(int i);///probado
    CajLSE *HijoMasIzquierdo(CajLSE *padre);///probado
    CajLSE *HermanoDerecho(CajLSE *hermano);
    int Etiqueta(CajLSE *yo);///probado
    bool EsHoja(CajLSE *c);///probado
    void mostrarLprincipal();///probado

    CajLSE *raiz;
    int numElem;
protected:
private:
};

#endif // Arbol_H
