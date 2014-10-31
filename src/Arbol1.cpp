#include "Arbol1.h"
/*Crear (tipoÁrbol A)
Efecto: Inicializa en memoria un contenedor de tipo árbol vacío
Requiere: A no inicializado
Modifica: A*/
Arbol::Arbol()
{
    raiz=0;//ctor
    numElem=0;
}

/*Destruir (tipoÁrbol A)
Efecto: Elimina lógicamente a A de la memoria
Requiere: A inicializado
Modifica: A.*/
Arbol::~Arbol()
{
    //dtor
    nodo *iter;
    while (!Vacio())
    {
        iter=raiz;
        while (!iter->EsHoja())
        {
            iter=iter->sig;
        }
        BorraHoja(iter);
    }
}

/*
Vaciar(tipoÁrbol A)
Efecto: Vacia a A de contenido
Requiere: A inicializado
Modifica: A.*/
void Arbol::Vaciar()
{
   nodo *iter;
    while (!Vacio())
    {
        iter=raiz;
        while (!iter->EsHoja())
        {
            iter=iter->sig;
        }
        BorraHoja(iter);
    }
}

/*Vacío(tipoÁrbol A)
Devuelve: Un booleano
Efecto: Devuelve verdadero si A está vacío y falso si no
Requiere: A inicializado
Modifica: N/A*/
bool Arbol::Vacio()
{
    return raiz==0;
}

/*PoneRaíz(tipoEtquieta e, tipoÁrbol A)
Efecto: Crea un TipoNodo n que contiene la etiqueta e, y lo establece como la raíz.
Requiere: A inicializado y vacío, y e válida en A.
Modifica: A.
*/
void Arbol::PoneRaiz(int elem)
{
    raiz=new CajLSE(elem);
}


/*AgregaHijo(tipoNodo n, tipoEtiqueta e, tipoÁrbol A)
Efecto: Agrega un nodo con la etiqueta e como hijo del nodo n en el árbol A
Requiere: A inicializado, n válido en A
Modifica: A*/
void Arbol::AgregaHijo(nodo *padre, int e)
{
    nodo *nuevo=new nodo(e);
    nuevo->sig=raiz->sig;
    raiz->sig=nuevo;
    padre->HMI=new CajSubLSE1(nuevo,padre->HMI);
    numElem=numElem+1;
}

/*BorraHoja(tipoNodo n, tipoÁrbol A)
Efecto: Elimina n del árbol A
Requiere: A inicializado, n válido en A y que n sea una hoja
Modifica: A*/
void Arbol::BorraHoja(nodo *aBorrar)
{
    if(aBorrar!=raiz)
    {
        bool noEncontrado=true;
        CajLSE *iter=raiz;
        while((iter!=0)&&(noEncontrado))
        {
            if(iter->HMI!=0)
            {
                if(iter->HMI->ptrMiElem==aBorrar)
                {
                    CajSubLSE1 *aBorrar=iter->HMI;
                    iter->HMI=iter->HMI->sig;
                    delete aBorrar;
                    noEncontrado=false;
                }
                else
                {
                    CajSubLSE1 *iter1=iter->HMI;
                    while((iter1!=0)&&(iter1->sig!=0)&&(noEncontrado))
                    {
                        if(iter1->sig->ptrMiElem==aBorrar)
                        {
                            noEncontrado=false;
                            iter1->sig=iter1->sig->sig;
                        }
                        else
                        {
                            iter1=iter1->sig;
                        }
                    }
                }
            }
            iter=iter->sig;
        }
        noEncontrado=true;
        iter=raiz;
        while((noEncontrado)&&(iter!=0)&&(iter->sig!=0))
        {
            if(iter->sig==aBorrar)
            {
                noEncontrado=false;
                iter->sig=iter->sig->sig;
            }
            else
            {
                iter=iter->sig;
            }
        }
        delete aBorrar;
    }
    else
    {
        raiz=0;
        delete aBorrar;
    }
    numElem=numElem-1;
}

/*ModificaEtiqueta(tipoNodo n, tipoEtiqueta e, tipoÁrbol A)
Efecto: Actualiza la etiqueta de n a e
Requiere: A inicializado, n válido en A.
Modifica: A*/
void Arbol::ModificaEtiqueta(nodo *aCambiar, int elem)
{
    aCambiar->miElem=elem;
}

/*Raíz(tipoÁrbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo raíz de A.
Requiere: A inicializado y no vacío
Modifica: N/A*/
nodo *Arbol::Raiz()
{
    return raiz;
}

/*Padre(tipoNodo n, tipoÁrbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo padre de n.
Requiere: A inicializado y n válido en A
Modifica: N/A*/
nodo *Arbol::Padre(nodo *hijo)
{
    nodo *padre=0;
    if(hijo!=raiz)
    {
        bool noEncontrado=true;
        nodo *iter=raiz;
        while((iter!=0)&&(noEncontrado))
        {
            if(iter->HMI!=0)
            {
                if(iter->HMI->ptrMiElem==hijo)
                {
                    padre=iter;
                    noEncontrado=false;
                }
                else
                {
                    CajSubLSE1 *iter1=iter->HMI;
                    while((iter1!=0)&&(iter1->sig!=0)&&(noEncontrado))
                    {
                        if(iter1->sig->ptrMiElem==hijo)
                        {
                            noEncontrado=false;
                            padre=iter;
                        }
                        else
                        {
                            iter1=iter1->sig;
                        }
                    }
                }
            }
            iter=iter->sig;
        }
    }
    return padre;
}

/*HijoMásIzquierdo(tipoNodo n, tipoÁrbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo hijo más izquierdo de n
Requiere: A inicializado y n válido en A
Modifica: N/A*/
nodo *Arbol::HijoMasIzquierdo(nodo *padre)
{
         if(padre->HMI==0)
    {
        return 0;
    }
    else
    {
        return padre->HMI->ptrMiElem;
    }
}


/*HermanoDerecho(tipoNodo n, tipoÁrbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo hermano derecho de n
Requiere: A inicializado y n válido en A
Modifica: N/A.*/
nodo *Arbol::HermanoDerecho(nodo *hermano)/// ////////////////////////////////ya lo arregle
{
    nodo *padre=Padre(hermano);
    CajSubLSE1 *iter=padre->HMI;
    bool encontrado=false;
    while ((!encontrado)&&(iter!=0))
    {
        if((iter->ptrMiElem->miElem==hermano->miElem))
        {
            encontrado=true;
        }
        else
        {
            iter=iter->sig;
        }
    }
    if(!encontrado)
    {
        return 0;
    }
    else if ((iter->sig==0)&&encontrado)
    {
        return 0;
    }
    else
    {
        return iter->sig->ptrMiElem;
    }
}

/*Etiqueta(tipoNodo n, tipoÁrbol A)
Devuelve: tipoEtiqueta
Efecto: Devuelve la etiqueta de n
Requiere: A inicializado y n válido en A
Modifica: N/A*/
int Arbol::Etiqueta(nodo *yo)
{
    return yo->miElem;
}

/*EsHoja(tipoNodo n, tipoÁrbol A)
Devuelve: tipoBooleano
Efecto: Devuelve verdadero si n no tiene hijos y falso si no
Requiere: A inicializado y n válido en A
Modifica: N/A*/
bool Arbol::EsHoja(nodo *c)
{
    return (c->HMI==0);
}

void Arbol::mostrarLprincipal()
{
    if(Vacio())
    {
        cout <<"El Arbol esta vacio"<<endl;
    }
    else
    {
        cout << "Inicio"<<endl;
        cout << ""<<endl;
        CajLSE *iter = raiz;
        while (iter != 0)
        {
            cout << iter->miElem<<endl;
            iter->mostrarHijosPantalla();
            iter=iter->sig;
        }
        cout << ".."<<endl;
        cout <<""<<endl;
    }
}

CajLSE *Arbol::Pertenece(int i)
{

    CajLSE *miembro=0;
    CajLSE *iter=raiz;
    bool noEncontrado=true;
    while ((iter!=0)&&(noEncontrado))
    {
        if(iter->miElem==i)
        {
            noEncontrado=false;
            miembro=iter;
        }
        else
        {
            iter=iter->sig;
        }
    }
    return miembro;
}

/*


















*/
