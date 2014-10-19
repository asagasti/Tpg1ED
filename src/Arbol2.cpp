#include "Arbol2.h"
/*
Crear (tipo�rbol A)
Efecto: Inicializa en memoria un contenedor de tipo �rbol vac�o
Requiere: A no inicializado
Modifica: A*/
Arbol2::Arbol2()
{
    ultimo=0;
}


/*Destruir (tipo�rbol A)
Efecto: Elimina l�gicamente a A de la memoria
Requiere: A inicializado
Modifica: A.*/
Arbol2::~Arbol2()
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

/*Vaciar(tipo�rbol A)
Efecto: Vacia a A de contenido
Requiere: A inicializado
Modifica: A.*/
void Arbol2::Vaciar()
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
/*Vac�o(tipo�rbol A)
Devuelve: Un booleano
Efecto: Devuelve verdadero si A est� vac�o y falso si no
Requiere: A inicializado
Modifica: N/A*/
bool Arbol2::Vacio()
{
    return ultimo==0;
}
/*PoneRa�z(tipoEtquieta e, tipo�rbol A)
Efecto: Crea un TipoNodo n que contiene la etiqueta e, y lo establece como la ra�z.
Requiere: A inicializado y vac�o, y e v�lida en A.
Modifica: A.*/
void Arbol2::PoneRaiz(int elem)
{
    cout<<"1"<<endl;
    miArbol[0]=new nodo(elem);
    cout<<"2"<<endl;
    ultimo=1;
    cout<<"3"<<endl;
}
/*AgregaHijo(tipoNodo n, tipoEtiqueta e, tipo�rbol A)
Efecto: Agrega un nodo con la etiqueta e como hijo del nodo n en el �rbol A
Requiere: A inicializado, n v�lido en A
Modifica: A*/
void Arbol2::AgregaHijo(nodo *padre, int e)
{
    nodo *nuevo=new nodo(e);
    CajSubLSE2 *nuevoHMI=new CajSubLSE2(nuevo,padre->HMI);
    padre->HMI=nuevoHMI;
    miArbol[ultimo]=nuevo;
    ultimo=ultimo+1;
}
/*BorraHoja(tipoNodo n, tipo�rbol A)
Efecto: Elimina n del �rbol A
Requiere: A inicializado, n v�lido en A y que n sea una hoja
Modifica: A*/
void Arbol2::BorraHoja(nodo *aBorrar)
{
    int j=0;
    if(aBorrar!=miArbol[0])
    {
        bool noEncontrado=true;
        while((j<ultimo)&&(noEncontrado))
        {
            if(miArbol[j]->HMI->ptrMiElem==aBorrar)
            {
                miArbol[j]->HMI=0;
                noEncontrado=false;
            }
            else
            {
                CajSubLSE2 *iter=miArbol[j]->HMI;
                while((iter!=0)&&(iter->sig!=0)&&(noEncontrado))
                {
                    if(iter->sig->ptrMiElem==aBorrar)
                    {
                        noEncontrado=false;
                        iter->sig=iter->sig->sig;
                    }
                    else
                    {
                        iter=iter->sig;
                    }
                }
                j=j+1;
            }
        }
        noEncontrado=true;
        int k=j+1;
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
        for(int i=k; i<ultimo; ++i)
        {
            miArbol[i]=miArbol[i+1];
        }
        delete a;
    }
    ultimo=ultimo-1;
}

/*ModificaEtiqueta(tipoNodo n, tipoEtiqueta e, tipo�rbol A)
Efecto: Actualiza la etiqueta de n a e
Requiere: A inicializado, n v�lido en A.
Modifica: A*/
void Arbol2::ModificaEtiqueta(nodo *aCambiar, int elem)
{
    aCambiar->miElem=elem;
}
/*Ra�z(tipo�rbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo ra�z de A.
Requiere: A inicializado y no vac�o
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

/*Padre(tipoNodo n, tipo�rbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo padre de n.
Requiere: A inicializado y n v�lido en A
Modifica: N/A*/
nodo *Arbol2::Padre(nodo *hijo)
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

/*HijoM�sIzquierdo(tipoNodo n, tipo�rbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo hijo m�s izquierdo de n
Requiere: A inicializado y n v�lido en A
Modifica: N/A
*/
nodo *Arbol2::HijoMasIzquierdo(nodo *padre)
{
    return padre->HMI->ptrMiElem;
}
/*HermanoDerecho(tipoNodo n, tipo�rbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo hermano derecho de n
Requiere: A inicializado y n v�lido en A
Modifica: N/A.*/
nodo *Arbol2::HermanoDerecho(nodo *hermano)
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
/*Etiqueta(tipoNodo n, tipo�rbol A)
Devuelve: tipoEtiqueta
Efecto: Devuelve la etiqueta de n
Requiere: A inicializado y n v�lido en A
Modifica: N/A*/
int Arbol2::Etiqueta(nodo *yo)
{
    return yo->miElem;
}
/*
EsHoja(tipoNodo n, tipo�rbol A)
Devuelve: tipoBooleano
Efecto: Devuelve verdadero si n no tiene hijos y falso si no
Requiere: A inicializado y n v�lido en A
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

nodo *Arbol2::Pertenece(int i)
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
