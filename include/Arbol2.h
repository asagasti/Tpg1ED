#ifndef ARBOL2_H
#define ARBOL2_H
#include "CajaLisArray.h"
#include <iostream>


using namespace std;

class nodo;
class Arbol2
{
public:
    Arbol2();///probado
    virtual ~Arbol2();///probado
    void Vaciar();///probado
    bool Vacio();///probado
    void PoneRaiz(int elem);///probado
    void AgregaHijo(nodo *padre, int e);///probado
    void BorraHoja(nodo *aBorrar);///probado
    void ModificaEtiqueta(nodo *aCambiar, int elem);///probado
    nodo *Raiz();///probado
    nodo *Padre(int hijo);///probado
    nodo *Padre(nodo *hijo);///probado
    nodo *HijoMasIzquierdo(nodo *padre);///probado
    nodo *HermanoDerecho(nodo *hermano);///probado
    int Etiqueta(nodo *yo);///probado
    bool EsHoja(nodo *c);///probado
    void mostrarLprincipal();///probado
    nodo *Pertenece(int i);///probado
    nodo *miArbol[100];
    int ultimo;
protected:
private:
};

#endif // ARBOL2_H
