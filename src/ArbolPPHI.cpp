#include "ArbolPPHI.h"
#include "pila.h"

using namespace std;



arbolPPHI::arbolPPHI(){
    root = NULL;
};



arbolPPHI::~arbolPPHI(){
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




void arbolPPHI::vaciar(){
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


bool arbolPPHI::vacia(){
    if (root == NULL){
        return true;
    }
    else {
        return false;
    }
};



nodo* arbolPPHI::hijoMasIzquierdo(nodo* padre){
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


nodo* arbolPPHI::hermanoDerecho(nodo* hermano){
    pila<nodo*> nivel;
    nodo *actual = root;
    nivel.agregar(actual);
    nodo *hijo;
    while (!nivel.vacia()){
        actual = nivel.sacar();
        if (actual == hermano){
            return actual->hermanoDerecho;
        }
        hijo = actual->hijoMasIzquierdo;
        while (hijo != NULL){
            nivel.agregar(hijo);
            hijo = hijo->hermanoDerecho;
        }
    }
    return NULL;
}


void arbolPPHI::agregarHijo(nodo* padre, int nombre){
    pila<nodo*> nivel;
    nodo *actual = root;
    nivel.agregar(actual);
    nodo *hijo;
    nodo * hijoAgregado = new nodo;
    hijoAgregado->etiqueta = nombre;
    hijoAgregado->hermanoDerecho = NULL;
    hijoAgregado->hijoMasIzquierdo = NULL;
    hijoAgregado->padre = padre;
    while (!nivel.vacia()){
        actual = nivel.sacar();
        if (actual == padre){
            if (actual->hijoMasIzquierdo == NULL){
                actual->hijoMasIzquierdo = hijoAgregado;
                hijoAgregado->hermanoIzquierdo = NULL;
            }
            else {
                hijo = actual->hijoMasIzquierdo;
                while (hijo->hermanoDerecho != NULL){
                    hijo = hijo->hermanoDerecho;
                }
                hijo->hermanoDerecho = hijoAgregado;
                hijoAgregado->hermanoIzquierdo = hijo;
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



void arbolPPHI::borrarNodo(nodo* borrado){
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
            if (hijo == borrado){
                    if (hijo->hermanoIzquierdo != NULL){
                        paraBorrar = hijo;
                        hijo = hijo->hermanoIzquierdo;
                        hijo->hermanoDerecho = paraBorrar->hermanoDerecho;
                        delete paraBorrar;
                        return;

                    }
                    else if (hijo->hermanoDerecho != NULL){
                        paraBorrar = hijo;
                        hijo = hijo->hermanoDerecho;
                        hijo->hermanoIzquierdo = NULL;
                        actual->hijoMasIzquierdo = hijo;
                        delete paraBorrar;
                        return;
                    }
            }
            nivel.agregar(hijo);
            hijo = hijo->hermanoDerecho;
        }
    }
};


int arbolPPHI::etiqueta(nodo* nombre){
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


nodo* arbolPPHI::raiz(){
    return root;
};




void arbolPPHI::poneRaiz(int nombre){
    nodo *raizNueva = new nodo;
    raizNueva->etiqueta = nombre;
    raizNueva->padre = NULL;
    raizNueva->hijoMasIzquierdo = NULL;
    raizNueva->hermanoDerecho = NULL;
    raizNueva->hermanoIzquierdo = NULL;
    root = raizNueva;
};


nodo* arbolPPHI::encuentraNodo(int nombre){
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


