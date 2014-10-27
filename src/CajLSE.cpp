#include "CajLSE.h"

nodo::nodo()
{
    HMI=0;
    sig=0;//ctor
}

nodo::nodo(int i)
{
    HMI=0;
    sig=0;//ctor
    miElem=i;
}

nodo::~nodo()
{
    //dtor
}

void nodo::borrarHijo(nodo *aBorrar)
{
    if(aBorrar==HMI->ptrMiElem){
        HMI=HMI->sig;
    } else {
        CajSubLSE1 *iter=HMI;
        bool borrado=false;
        while ((iter->sig!=0)&&!borrado){
            if(iter->sig->ptrMiElem==aBorrar){
                iter->sig=iter->sig->sig;
                borrado=true;
            } else {
                iter=iter->sig;
            }
        }
    }
}

void nodo::agregarHijo(nodo *h)
{
    CajSubLSE1 *nuevo=new CajSubLSE1(h,HMI);
    HMI=nuevo;
}

bool nodo::esPadreDe(nodo *posibleHijo)
{
    CajSubLSE1 *iter=HMI;
    bool noEncontrado=true;
    while((iter!=0)&&(noEncontrado)){
        if(iter->ptrMiElem==posibleHijo){
            noEncontrado=false;
        } else {
            iter=iter->sig;
        }
    }
    return !noEncontrado;
}

bool nodo::EsHoja()
{
    bool hoja=false;
    if(HMI==0)
    {
        hoja=true;
    }
    return hoja;
}

void nodo::mostrarHijosPantalla()
{
    if(HMI==0)
    {
        cout <<"   No tiene hijos"<<endl;
    }
    else
    {
        cout << "Hijos"<<endl;
        cout << ""<<endl;
        CajSubLSE1 *iter = HMI;
        while (iter != 0)
        {
            cout << "    "<<iter->ptrMiElem->miElem<<endl;
            iter=iter->sig;
        }
        cout << "Fin"<<endl;
        cout <<""<<endl;
    }
}
