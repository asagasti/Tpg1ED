#include "CajLSE.h"

CajLSE::CajLSE()
{
    HMI=0;
    sig=0;//ctor
}

CajLSE::CajLSE(int i)
{
    HMI=0;
    sig=0;//ctor
    miElem=i;
}

CajLSE::~CajLSE()
{
    //dtor
}

void CajLSE::borrarHijo(CajLSE *aBorrar)
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

void CajLSE::agregarHijo(CajLSE *h)
{
    CajSubLSE1 *nuevo=new CajSubLSE1(h,HMI);
    HMI=nuevo;
}

bool CajLSE::esPadreDe(CajLSE *posibleHijo)
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

bool CajLSE::EsHoja()
{
    bool hoja=false;
    if(HMI==0)
    {
        hoja=true;
    }
    return hoja;
}

void CajLSE::mostrarHijosPantalla()
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
