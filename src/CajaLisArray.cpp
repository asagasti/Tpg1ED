#include "CajaLisArray.h"

nodo::nodo()
{
    HMI=0;//ctor
}

nodo::nodo(int i)
{
    miElem=i;
    HMI=0;
}

nodo::~nodo()
{
    //dtor
}
void nodo::agregarHijo(nodo *h)
{
    CajSubLSE2 *nuevo=new CajSubLSE2(h,HMI);
    HMI=nuevo;
}

void nodo::borrarHijo(nodo *aBorrar)
{
}

bool nodo::esPadreDe(nodo *posibleHijo)
{
    CajSubLSE2 *iter=HMI;
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
    if(HMI==0){
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
        cout << "Hijos:"<<endl;
        cout << ""<<endl;
        CajSubLSE2 *iter = HMI;
        while (iter != 0)
        {
            cout << "    "<<iter->ptrMiElem->miElem<<endl;
            iter=iter->sig;
        }
        cout << "Fin"<<endl;
        cout <<""<<endl;
    }
}
