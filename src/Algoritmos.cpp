
#include "Algoritmos.h"
#include <algorithm>
/**
ya a. Averiguar cuál es el hermano izquierdo de un nodo.
ya b. Averiguar la altura de un nodo (distancia que hay desde el nodo hasta la hoja
descendiente más alejada).
c. Averiguar si el árbol tiene etiquetas repetidas.
ya d. Averiguar cuántos niveles tiene el árbol.
ya e. Averiguar cuántos hijos tiene un nodo.
f. Listar las etiquetas correspondientes a los hijos de un nodo.
ya g. Borrar el Sub-Árbol que se genera a partir de un nodo.
h. Copiar un Árbol.
*/


Algoritmos::Algoritmos()
{
}

Algoritmos::~Algoritmos()
{
}

nodo *Algoritmos::HermanoIzquierdoM(Arbol *a,  nodo *n)
{
    nodo *HI;
    if (n==a->Raiz())
    {
        HI= 0;
    }
    else
    {
        nodo *q=a->Padre(n);
        if (a->HijoMasIzquierdo(q)==n)
        {
            HI=0;
        }
        else
        {
            nodo *iter=a->HijoMasIzquierdo(q);
            nodo *iterHD=a->HermanoDerecho(iter);
            bool encontrado=false;
            while ((iterHD!=0)&&(!encontrado))
            {
                if(iterHD==n)
                {
                    HI=iter;
                    encontrado=true;
                }
                else
                {
                    iter=iterHD;
                    iterHD=a->HermanoDerecho(iter);
                }
            }
        }
    }
    return HI;
}

int Algoritmos::AlturaNodo(Arbol *a, nodo *n)
{
    return AlturaNodoRe(a,n);
}


bool Algoritmos::etiquetasRepetidas(Arbol *a)
{
    list<int> coll;
    list<int>::iterator pos;
    Cola *cOrig=new Cola();
    nodo *nActOrig;
    nodo *hijOrig=0;
    int etiqueta;
    bool repetidos=false;
    if (!(a->Vacio()))
    {
        nActOrig=a->Raiz();
        cOrig->Agregar(nActOrig);
        while ((!(cOrig->Vacia()))&&(!repetidos))
        {
            nActOrig=cOrig->Sacar();
            etiqueta=a->Etiqueta(nActOrig);
            pos = find (coll.begin(), coll.end(), etiqueta);
            if(pos!=coll.end())
            {
                repetidos=true;
            }
            else
            {
                coll.push_back(etiqueta);
            }
            hijOrig=a->HijoMasIzquierdo(nActOrig);
            while ((hijOrig!=0)&&(!repetidos))
            {
                etiqueta=a->Etiqueta(hijOrig);
                cout << etiqueta<<endl;
                cOrig->Agregar(hijOrig);
                hijOrig=a->HermanoDerecho(hijOrig);
            }
        }
    }
    return repetidos;
}


int Algoritmos::nivelesArbol(Arbol *a)
{
    return AlturaNodo(a,a->Raiz());
}


int Algoritmos::hijosNodo(Arbol *a, nodo *n)
{
    int hijos=0;
    if(!n->EsHoja())
    {
        nodo *iter=a->HijoMasIzquierdo(n);
        while (iter!=0)
        {
            hijos=hijos+1;
            iter=a->HermanoDerecho(iter);
        }
    }
    return hijos;
}


void Algoritmos::listarHijosNodo(Arbol *a, nodo *n)
{
    nodo *hijo=a->HijoMasIzquierdo(n);
    if(hijo==0)
    {
        cout<<"Este nodo no tiene hijos"<<endl;
    }
    else
    {
        cout<<"Hijos del nodo con etiqueta "<<a->Etiqueta(n)<<":"<<endl;
        while(hijo!=0)
        {
            cout<<a->Etiqueta(hijo)<<endl;
            hijo=a->HermanoDerecho(hijo);
        }
        cout<<"Fin de lista de hijos"<<endl;
        cout<<endl<<endl<<endl;
    }
}


void Algoritmos::borrarSubArbol(Arbol *a, nodo *n)
{
    cout << "entro iter"<< endl;
    borrarSubArbolRe(a,n);
    cout << "salio iter"<< endl;
}



void Algoritmos::copiarArbol (Arbol *aOriginal, Arbol *aCopia)  //requiere aCopia vacio
{
    Cola *cOrig=new Cola();
    Cola *cCop=new Cola ();
    nodo *nActOrig;
    nodo *nActCop;
    nodo *hijOrig=0;
    nodo *hijCop=0;
    int etiqueta;
    if (!(aOriginal->Vacio()))
    {
//        cout<<""<<endl;
        aCopia->PoneRaiz(aOriginal->Etiqueta(aOriginal->Raiz()));
//        cout<<""<<endl;
        nActOrig=aOriginal->Raiz();
        nActCop=aCopia->Raiz();
        cOrig->Agregar(nActOrig);
//        cout<<""<<endl;
        cCop->Agregar(nActCop);
//        cout<<""<<endl;
        while (!cOrig->Vacia())
        {
//            cout<<""<<endl;
            nActOrig=cOrig->Sacar();
//            cout<<""<<endl;
            nActCop=cCop->Sacar();
//            cout<<""<<endl;
            hijOrig=aOriginal->HijoMasIzquierdo(nActOrig);
            while (hijOrig!=0)
            {
                etiqueta=aOriginal->Etiqueta(hijOrig);
                aCopia->AgregaHijo(nActCop,etiqueta);
                hijCop=direccionNodo(aCopia,nActCop,etiqueta);
                cOrig->Agregar(hijOrig);
                cCop->Agregar(hijCop);
                hijOrig=aOriginal->HermanoDerecho(hijOrig);
            }
        }
    }
}




int Algoritmos::HermanoIzquierdo(Arbol *a,  int HD)
{
    nodo *n=a->Pertenece(HD);
    n=HermanoIzquierdoM(a,n);
    int j=(a->Etiqueta(n));
    return j;
}


int Algoritmos::AlturaNodo(Arbol *a, int etiqueta)
{
    nodo *n=a->Pertenece(etiqueta);
    //cout<<"antes return (Arbol *a, int etiqueta)"<<endl;
    return AlturaNodo(a,n);
}


int Algoritmos::AlturaNodoRe(Arbol *a, nodo *n)
{
    int nivelMayor=1;
    if(a->Etiqueta(n)!=(17))
    {
        if(!n->EsHoja())
        {
            nodo *iter=a->HijoMasIzquierdo(n);
            int nivelIter=1;
            while (iter!=0)
            {
                nivelIter=AlturaNodoRe(a,iter);
                if (nivelIter>nivelMayor)
                {
                    nivelMayor=nivelIter;
                }
                iter=a->HermanoDerecho(iter);
            }
            nivelMayor=nivelMayor+1;
        }
    }
    else
    {
        return 0;
    }
    return nivelMayor;
}

void Algoritmos::borrarSubArbolRe(Arbol *a, nodo *n)
{
    cout << "entro"<< endl;
    cout << a->Etiqueta(n)<< endl;
    if((a->HijoMasIzquierdo(n)!=0))
    {
        cout << "1"<< endl;
        nodo *iter=a->HijoMasIzquierdo(n);
        while (iter!=0)
        {
            cout << "2"<< endl;
            borrarSubArbolRe(a,iter);
            cout << "3"<< endl;
            iter=a->HermanoDerecho(iter);
            cout << "4"<< endl;
        }
    }
    cout << "5"<< endl;
    a->BorraHoja(n);
    cout << "6"<< endl;
}


nodo *Algoritmos::direccionNodo(Arbol *a, nodo *padre, int etiqueta)
{
    nodo *n=a->HijoMasIzquierdo(padre);
    bool noEncontrado=true;
    while(n!=0&&noEncontrado)
    {
        if(a->Etiqueta(n)==etiqueta)
        {
            noEncontrado=false;
        }
        else
        {
            n=a->HermanoDerecho(n);
        }
    }
    return n;
}
