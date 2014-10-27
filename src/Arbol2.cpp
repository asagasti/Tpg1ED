#include "Arbol2.h"
/*
Crear (tipoÁrbol A)
Efecto: Inicializa en memoria un contenedor de tipo árbol vacío
Requiere: A no inicializado
Modifica: A*/
Arbol::Arbol()
{
    ultimo=0;
}


/*Destruir (tipoÁrbol A)
Efecto: Elimina lógicamente a A de la memoria
Requiere: A inicializado
Modifica: A.*/
Arbol::~Arbol()
{
    //dtor
    nodo *iter;
    for (int i=0; i<ultimo; ++i)
    {
        iter=miArbol[i];
        delete iter;
        miArbol[i]=0;
    }
}

/*Vaciar(tipoÁrbol A)
Efecto: Vacia a A de contenido
Requiere: A inicializado
Modifica: A.*/
void Arbol::Vaciar()
{
    nodo *iter;
    for (int i=0; i<ultimo; ++i)
    {
        iter=miArbol[i];
        delete iter;
        miArbol[i]=0;
    }
    ultimo=0;
}
/*Vacío(tipoÁrbol A)
Devuelve: Un booleano
Efecto: Devuelve verdadero si A está vacío y falso si no
Requiere: A inicializado
Modifica: N/A*/
bool Arbol::Vacio()
{
    return ultimo==0;
}
/*PoneRaíz(tipoEtquieta e, tipoÁrbol A)
Efecto: Crea un TipoNodo n que contiene la etiqueta e, y lo establece como la raíz.
Requiere: A inicializado y vacío, y e válida en A.
Modifica: A.*/
void Arbol::PoneRaiz(int elem)
{
    cout<<"1"<<endl;
    miArbol[0]=new nodo(elem);
    cout<<"2"<<endl;
    ultimo=1;
    cout<<"3"<<endl;
}
/*AgregaHijo(tipoNodo n, tipoEtiqueta e, tipoÁrbol A)
Efecto: Agrega un nodo con la etiqueta e como hijo del nodo n en el árbol A
Requiere: A inicializado, n válido en A
Modifica: A*/
void Arbol::AgregaHijo(nodo *padre, int e)
{
    nodo *nuevo=new nodo(e);
    CajSubLSE2 *nuevoHMI=new CajSubLSE2(nuevo,padre->HMI);
    padre->HMI=nuevoHMI;
    miArbol[ultimo]=nuevo;
    ultimo=ultimo+1;
}
/*BorraHoja(tipoNodo n, tipoÁrbol A)
Efecto: Elimina n del árbol A
Requiere: A inicializado, n válido en A y que n sea una hoja
Modifica: A*/
void Arbol::BorraHoja(nodo *aBorrar)
{
    int j=0;
    if(aBorrar!=miArbol[0])
    {
        bool noEncontrado=true;
        while((j<ultimo)&&(noEncontrado))
        {
            if((miArbol[j]->HMI!=0)&&(miArbol[j]->HMI->ptrMiElem==aBorrar))
            {
                miArbol[j]->HMI=0;
                noEncontrado=false;
            }
            else if((miArbol[j]->HMI!=0))
            {
                if(miArbol[j]->HMI->ptrMiElem==aBorrar)
                {
                    miArbol[j]->HMI=miArbol[j]->HMI->sig;
                    noEncontrado=false;
                }
                else
                {
                    CajSubLSE2 *iter=miArbol[j]->HMI;
                    while((iter!=0)&&(noEncontrado))
                    {
                        if((iter->sig!=0)&&(iter->sig->ptrMiElem->miElem==aBorrar->miElem))
                        {
                            noEncontrado=false;
                            CajSubLSE2 *t=iter->sig;
                            t=t->sig;
                            iter->sig=t;
                        }
                        else
                        {
                            iter=iter->sig;
                        }
                    }
                }
            }
            j=j+1;
        }
        noEncontrado=true;
        int k=j-1;
        while(noEncontrado&&k<ultimo)
        {
            if(miArbol[k]==aBorrar)
            {
                noEncontrado=false;
            }
            else
            {
                k=k+1;
            }
        }
        nodo *a=miArbol[k];
        for(int i=k; i<ultimo-1; ++i)
        {
            miArbol[i]=miArbol[i+1];
        }
        delete a;
    }
    ultimo=ultimo-1;
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
nodo *Arbol2::Raiz()
{
    return miArbol[0];
}

nodo *Arbol2::Padre(int hijo)
{
    nodo *hij=Pertenece(hijo);
    if (hij!=0)
    {
        return Padre(hij);
    }
    else
    {
        return 0;
    }
}

/*Padre(tipoNodo n, tipoÁrbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo padre de n.
Requiere: A inicializado y n válido en A
Modifica: N/A*/
nodo *Arbol::Padre(nodo *hijo)
{
    nodo *padre=0;
    cout<<"a"<<endl;
    int j=0;
    if(hijo!=miArbol[0])
    {
        cout<<"if1"<<endl;
        bool noEncontrado=true;
        while((j<ultimo)&&(noEncontrado))
        {
            noEncontrado=!(miArbol[j]->esPadreDe(hijo));
            j=j+1;
        }
        if(!noEncontrado){
            padre=miArbol[j-1];
        }
    }
    return padre;
}

/*HijoMásIzquierdo(tipoNodo n, tipoÁrbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo hijo más izquierdo de n
Requiere: A inicializado y n válido en A
Modifica: N/A
*/
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
nodo *Arbol::HermanoDerecho(nodo *hermano)
{
    nodo *padre=Padre(hermano);
    CajSubLSE2 *iter=padre->HMI;
    bool encontrado=false;
    while (!encontrado)
    {
        if(!(iter->ptrMiElem==hermano))
        {
            iter=iter->sig;
        }
        else
        {
            encontrado=true;
        }
    }
    return iter->sig->ptrMiElem;
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
/*
EsHoja(tipoNodo n, tipoÁrbol A)
Devuelve: tipoBooleano
Efecto: Devuelve verdadero si n no tiene hijos y falso si no
Requiere: A inicializado y n válido en A
Modifica: N/A*/
bool Arbol2::EsHoja(nodo *c)
{
    return c->EsHoja();
}



void Arbol2::mostrarLprincipal()
{

    if(Vacio())
    {
        cout <<"El arbol2 esta vacio"<<endl;
    }
    else
    {
        cout << "Inicio"<<endl;
        cout <<endl;
        int i=0;
        while (i<ultimo)
        {
            cout << miArbol[i]->miElem<<endl;
            miArbol[i]->mostrarHijosPantalla();
            i=i+1;
        }
        cout <<endl;
    }
}

nodo *Arbol::Pertenece(int i)
{
    int j=0;
    nodo *miembro=0;
    bool noEncontrado=true;
    while ((j<ultimo)&&(noEncontrado))
    {
        if(miArbol[j]->miElem==i)
        {
            noEncontrado=false;
        }
        else
        {
            j=j+1;
        }
    }
    if(!noEncontrado)
    {
        miembro=miArbol[j];
    }
    cout<<"saliendo de pertence"<<endl;
    return miembro;
}
//
/*

















*/
