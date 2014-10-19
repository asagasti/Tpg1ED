#include "ArbolUHPB.h"
#include "pila.h"

using namespace std;



arbolUHPB::arbolUHPB(){
    root = NULL;
};



arbolUHPB::~arbolUHPB(){
    if (root != NULL){
        pila<nodo*> nivel;
        pila<nodo*> paraBorrar;
        nodo *actual = root;
        nodo *hijo;
        nivel.agregar(actual);
        while (!nivel.vacia()){
            actual = nivel.sacar();
            hijo = actual->hijoMasIzquierdo;
            while (hijo != NULL){
                nivel.agregar(hijo);
                hijo = hijo->hermanoDerecho;
            }
            paraBorrar.agregar(actual);
        }
        while (!paraBorrar.vacia()){
            actual = paraBorrar.sacar();
            delete actual;
        }
        actual = NULL;
        root = NULL;
    }
};




void arbolUHPB::vaciar(){
       if (root != NULL){
        pila<nodo*> nivel;
        pila<nodo*> paraBorrar;
        nodo *actual = root;
        nodo *hijo;
        nivel.agregar(actual);
        while (!nivel.vacia()){
            actual = nivel.sacar();
            hijo = actual->hijoMasIzquierdo;
            while (hijo != NULL){
                nivel.agregar(hijo);
                hijo = hijo->hermanoDerecho;
            }
            paraBorrar.agregar(actual);
        }
        while (!paraBorrar.vacia()){
            actual = paraBorrar.sacar();
            delete actual;
        }
        actual = NULL;
        root = NULL;
    }
};


bool arbolUHPB::vacia(){
    if (root == NULL){
        return true;
    }
    else {
        return false;
    }
};



nodo* arbolUHPB::hijoMasIzquierdo(nodo* padre){
    pila<nodo*> nivel;
    nodo *actual = root;
    nivel.agregar(actual);
    nodo *hijo;
    while (!nivel.vacia()){
        actual = nivel.sacar();
        if (actual == padre){
            return actual->hijoMasIzquierdo;
        }
        hijo = actual->hijoMasIzquierdo;
        while (hijo != NULL){
            nivel.agregar(hijo);
            hijo = hijo->hermanoDerecho;
        }
    }
    return NULL;
}


nodo* arbolUHPB::hermanoDerecho(nodo* hermano){
    pila<nodo*> nivel;
    nodo *actual = root;
    nivel.agregar(actual);
    nodo *hijo;
    while (!nivel.vacia()){
        actual = nivel.sacar();
        if (actual == hermano){
            if (actual->apunta){
                return NULL;
            }
            else{
                return actual->hermanoDerecho;
            }
        }
        hijo = actual->hijoMasIzquierdo;
        while (hijo != NULL){
            nivel.agregar(hijo);
            hijo = hijo->hermanoDerecho;
        }
    }
    return NULL;
}


void arbolUHPB::agregarHijo(nodo* padre, int nombre){
    pila<nodo*> nivel;
    nodo *actual = root;
    nodo *hijo;
    nivel.agregar(actual);
    nodo * hijoAgregado = new nodo;
    hijoAgregado->etiqueta = nombre;
    hijoAgregado->hermanoDerecho = NULL;
    hijoAgregado->hijoMasIzquierdo = NULL;
    while (!nivel.vacia()){
        actual = nivel.sacar();
        if (actual == padre){
            if (actual->hijoMasIzquierdo != NULL){
                actual->hijoMasIzquierdo = hijoAgregado;
                hijoAgregado->hermanoDerecho = actual;
                hijoAgregado->apunta = true;
            }
            else {
                hijo = actual->hijoMasIzquierdo;
                while (!hijo->apunta){
                    hijo = hijo->hermanoDerecho;
                }
                hijo->apunta = false;
                hijo->hermanoDerecho = hijoAgregado;
                hijoAgregado->apunta = true;
                hijoAgregado->hermanoDerecho = actual;
            }
        }
        hijo = actual->hijoMasIzquierdo;
        while (hijo != NULL){
            nivel.agregar(hijo);
            hijo = hijo->hermanoDerecho;
        }
    }
    return;
};



void arbolUHPB::borrarNodo(nodo* borrado){
    pila<nodo*> nivel;
    nodo *actual = root;
    nivel.agregar(actual);
    nodo *hijo;
    nodo *paraBorrar;
    paraBorrar = NULL;
    if (actual == borrado){
        delete actual;
        return;
    }
    while (!nivel.vacia()){
        actual = nivel.sacar();
        hijo = actual->hijoMasIzquierdo;
        while (hijo != NULL){
            if (hijo->hermanoDerecho == borrado){
                paraBorrar = hijo->hermanoDerecho;
                if (paraBorrar->apunta){
                    hijo->apunta = true;
                }
                hijo->hermanoDerecho = paraBorrar->hermanoDerecho;
                return;
            }
            if (hijo == borrado){
                    if (actual->hijoMasIzquierdo == hijo){
                        if (hijo->apunta){
                            paraBorrar = hijo;
                            delete paraBorrar;
                            actual->hijoMasIzquierdo = NULL;
                            return;
                        }
                        else {
                            paraBorrar = hijo;
                            actual->hijoMasIzquierdo = hijo->hermanoDerecho;
                            delete paraBorrar;
                            return;
                        }
                    }
            }
            nivel.agregar(hijo);
            hijo = hijo->hermanoDerecho;
        }
    }
};


int arbolUHPB::etiqueta(nodo* nombre){
    pila<nodo*> nivel;
    nodo *actual = root;
    nivel.agregar(actual);
    nodo *hijo;
    while (!nivel.vacia()){
        actual = nivel.sacar();
        if (actual == nombre){
            return actual->etiqueta;
        }
        hijo = actual->hijoMasIzquierdo;
        while (hijo != NULL){
            nivel.agregar(hijo);
            hijo = hijo->hermanoDerecho;
        }
    }
    return NULL;
};


nodo* arbolUHPB::raiz(){
    return root;
};




void arbolUHPB::poneRaiz(int nombre){
    nodo *raizNueva = new nodo;
    raizNueva->etiqueta = nombre;
    raizNueva->hijoMasIzquierdo = NULL;
    raizNueva->hermanoDerecho = NULL;
    raizNueva->apunta = false;
    root = raizNueva;
};


nodo* arbolUHPB::encuentraNodo(int nombre){
    pila<nodo*> nivel;
    nodo *actual = root;
    nivel.agregar(actual);
    nodo *hijo;
    while (!nivel.vacia()){
        actual = nivel.sacar();
        if (actual->etiqueta = nombre){
            return actual;
        }
        hijo = actual->hijoMasIzquierdo;
        while (hijo != NULL){
            nivel.agregar(hijo);
            hijo = hijo->hermanoDerecho;
        }
    }
    return NULL;

};


