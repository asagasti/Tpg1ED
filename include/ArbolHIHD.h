#ifndef ARBOLHIHD_H_INCLUDED
#define ARBOLHIHD_H_INCLUDED


struct nodo{
    int etiqueta;
    nodo *hermanoDerecho = NULL;
    nodo *hijoMasIzquierdo = NULL;
};



class arbolHIHD{
    nodo *root = new nodo;
public:
    arbolHIHD();
    ~arbolHIHD();
    void poneRaiz(int);
    void vaciar();
    bool vacia();
    nodo* hijoMasIzquierdo(nodo*);
    nodo* hermanoDerecho(nodo*);
    void agregarHijo(nodo*, int);
    void borrarNodo(nodo*);
    int etiqueta(nodo*);
    nodo* raiz();

};




#endif // ARBOLHIHD_H_INCLUDED
