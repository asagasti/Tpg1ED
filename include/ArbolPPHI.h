#ifndef ARBOLPPHI_H
#define ARBOLPPHI_H

#include <string>


struct nodo{
    int etiqueta;
    nodo * hermanoDerecho;
    nodo * hijoMasIzquierdo = NULL;
    nodo * padre;
    nodo * hermanoIzquierdo;
    bool operator==(const nodo& other);
    nodo();
};

nodo::nodo(){
    hermanoDerecho = NULL;
    hijoMasIzquierdo = NULL;
    padre = NULL;
    hermanoIzquierdo = NULL;
}

bool nodo::operator==(const nodo& other){
    if (etiqueta != other.etiqueta){
        return false;
    }
    if (hermanoDerecho != other.hermanoDerecho){
        return false;
    }
    if (hermanoIzquierdo != other.hermanoIzquierdo){
        return false;
    }
    if (hijoMasIzquierdo != other.hijoMasIzquierdo){
        return false;
    }
    if (padre != other.padre){
        return false;
    }
    else {
        return true;
    }
}



class arbolPPHI{
    nodo * root = new nodo;
public:
    arbolPPHI();
    ~arbolPPHI();
    void vaciar();
    bool vacia();
    nodo* hijoMasIzquierdo(nodo*);
    nodo* hermanoDerecho(nodo*);
    void agregarHijo(nodo*, int);
    void borrarNodo(nodo*);
    int etiqueta(nodo*);
    nodo* raiz();
    void poneRaiz(int);
    nodo* encuentraNodo(int);

};



#endif // ARBOLPPHI_H
