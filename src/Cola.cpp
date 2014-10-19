#include "Cola.h"
/*Crear(tipoCola C)
Efecto: inicializa en memoria un contenedor de tipo cola vacío
Requiere: C no inicializada
Modifica: C*/
Cola::Cola()//ctor
{
    ultim=0;
    prim=0;
}
/*Destruir(tipoCola C)
Efecto: Elimina lógicamente a C de la memoria
Requiere: C inicializada
Modifica: C*/
Cola::~Cola() //dtor
{
    if(!Vacia())
    {
        CajaCola *iter=prim;
        CajaCola *aBorrar;
        while (iter!=0)
        {
            aBorrar=iter;
            iter=iter->obSig();
            delete aBorrar;
        }
    }
}
/*Vaciar(tipoCola C)
Efecto: Vacía a C de contenido
Requiere: C inicializada
Modifica: C*/
void Cola::Vaciar()
{
    while (!Vacia())
    {
        Sacar();
    }
}

/*
Vacía(tipoCola C)
Devuelve: Un booleano
Efecto: Devuelve verdadero si C está vacía y falso si no
Requiere: C inicializada
Modifica: N/A*/
bool Cola::Vacia()
{
    return (prim==0);
}

/*Agregar(tipoElemento e, tipoCola C)
Efecto: Agrega el elemento e a la cola C
Requiere: C inicializada
Modifica: C*/
void Cola::Agregar(int elem)  //enColar
{
    CajaCola *c=new CajaCola();
    c->ponValor(elem);
    if(Vacia())
    {
        prim=ultim=c;
    }
    else
    {
        ultim->ponSig(c);
        ultim=c;
    }
}

/*Sacar(tipoCola C)
Devuelve: TipoElemento e (opcional)
Efecto: Elimina el primer elemento de C, y opcionalmente lo devuelve
Requiere: C inicializada y no vacía
Modifica: C*/
int Cola::Sacar()  //desEncolar
{
    CajaCola *c=prim;
    int fren=Frente();
    prim=prim->obSig();
    delete c;
    return fren;
}

/*Frente(tipoCola C)
Devuelve: TipoElemento e
Efecto: Retorna e, el primer elemento de la cola C
Requiere: C inicializada y no vacía
Modifica: N/A*/
int Cola::Frente()
{
    return prim->obValor();
}

void Cola::mostrarEnPantalla()
{
    if(Vacia())
    {
        cout <<"La cola esta vacia"<<endl;
    }
    else
    {
        cout << "Inicio"<<endl;
        cout << ""<<endl;
        CajaCola *iter = prim;
        while (iter != 0)
        {
            cout << iter->obValor()<<endl;
            iter=iter->obSig();
        }
        cout << "Fin"<<endl;
        cout <<""<<endl;
    }
}
/*












*/
