
#include "ArbolHIHD.h"
#include "pila.h"


arbolHIHD::arbolHIHD(){
    root = NULL;
};


arbolHIHD::~arbolHIHD(){
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
    }
};


void arbolHIHD::vaciar(){
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




nodo* arbolHIHD::hijoMasIzquierdo(nodo * padre){
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

};



nodo* arbolHIHD::hermanoDerecho(nodo * hermano){
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

};


void arbolHIHD::agregarHijo(nodo* padre, int nombre){
    pila<nodo*> nivel;
    nodo *actual = root;
    nivel.agregar(actual);
    nodo *hijo;
    nodo * hijoAgregado = new nodo;
    hijoAgregado->etiqueta = nombre;
    hijoAgregado->hermanoDerecho = NULL;
    hijoAgregado->hijoMasIzquierdo = NULL;
    while (!nivel.vacia()){
        actual = nivel.sacar();
        if (actual == padre){
            if (actual->hijoMasIzquierdo == NULL){
                actual->hijoMasIzquierdo = hijoAgregado;
            }
            else {
                hijo = actual->hijoMasIzquierdo;
                while (hijo->hermanoDerecho != NULL){
                    hijo = hijo->hermanoDerecho;
                }
                hijo->hermanoDerecho = hijoAgregado;
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


void arbolHIHD::borrarNodo(nodo* borrado){
    pila<nodo*> nivel;
    nodo *actual = root;
    nivel.agregar(actual);
    nodo *hijo;
    nodo *paraBorrar = new nodo;
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
                hijo->hermanoDerecho = paraBorrar->hermanoDerecho;
                delete paraBorrar;
                paraBorrar = NULL;
                return;
            }
            else if (hijo == borrado){
                paraBorrar = hijo;
                actual->hijoMasIzquierdo = hijo->hermanoDerecho;
                delete paraBorrar;
                paraBorrar = NULL;
                return;
            }
            nivel.agregar(hijo);
            hijo = hijo->hermanoDerecho;
        }
    }
};


int arbolHIHD::etiqueta(nodo* buscado){
    pila<nodo*> nivel;
    nodo *actual = root;
    nivel.agregar(actual);
    nodo *hijo;
    while (!nivel.vacia()){
        actual = nivel.sacar();
        if (actual == buscado){
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


nodo* arbolHIHD::raiz(){
    return root;

};



void arbolHIHD::poneRaiz(int raizPuesta){
    nodo* raizNueva = new nodo;
    raizNueva->etiqueta = raizPuesta;
    raizNueva->hermanoDerecho = NULL;
    raizNueva->hijoMasIzquierdo = NULL;
    root = raizNueva;
};


bool arbolHIHD::vacia(){
    if (root == NULL){
        return true;
    }
    else{
        return false;
    }
};
