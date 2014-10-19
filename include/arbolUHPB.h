#ifndef ARBOLUHPB_H
#define ARBOLUHPB_H


struct nodo{
    int etiqueta;
    nodo * hermanoDerecho = NULL;
    nodo * hijoMasIzquierdo = NULL;
    bool apunta = false;
    bool operator==(const nodo& other);
    nodo();
};

nodo::nodo(){
    hermanoDerecho = NULL;
    hijoMasIzquierdo = NULL;
    apunta = false;
}

bool nodo::operator==(const nodo& other){
    if (etiqueta != other.etiqueta){
        return false;
    }
    if (hermanoDerecho != other.hermanoDerecho){
        return false;
    }
    if (hijoMasIzquierdo != other.hijoMasIzquierdo){
        return false;
    }
    if (apunta != other.apunta){
        return false;
    }
    else {
        return true;
    }
}



class arbolUHPB{
    nodo * root = new nodo;
public:
    arbolUHPB();
    ~arbolUHPB();
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

#endif // ARBOLUHPB_H
