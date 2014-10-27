#ifndef ARBOL1_H
#define ARBOL1_H
#include "CajLSE.h"
#include <iostream>


using namespace std;
class nodo;
class Arbol
{
public:
    Arbol();///probado
    virtual ~Arbol();///probado
    void Vaciar();///probado
    bool Vacio();///probado
    void PoneRaiz(int elem);///probado
    void AgregaHijo(nodo *padre, int e);///probado
    void BorraHoja(nodo *aBorrar);///probado
    void ModificaEtiqueta(nodo *aCambiar, int elem);///probado
    nodo * Raiz();///probado
    nodo *Padre(nodo *hijo);///probado
    nodo *Pertenece(int i);///probado
    nodo *HijoMasIzquierdo(nodo *padre);///probado
    nodo *HermanoDerecho(nodo *hermano);
    int Etiqueta(nodo *yo);///probado
    bool EsHoja(nodo *c);///probado
    void mostrarLprincipal();///probado

    nodo *raiz;
    int numElem;
protected:
private:
};

#endif // Arbol_H
