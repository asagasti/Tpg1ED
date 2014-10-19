#include"Pila.h"
pila::pila()
{
    cabeza = 0;
}


//esto va antes de cada funcion
pila::~pila()
{
    cajaPila *borrar;           // pila<T>::vaciar significa el metodo vaciar dentro de la clase pila con template T
    if(!vacia())
    {
        while(cabeza != 0)
        {
            borrar = cabeza;
            cabeza = cabeza->siguiente;
            delete borrar;
        }
        delete cabeza;
    }
}


void pila::vaciar()
{
    cajaPila *borrar;
    while(cabeza != 0)
    {
        borrar = cabeza;
        cabeza = cabeza->siguiente;
        delete borrar;
    }
}


bool pila::vacia()
{
    if (cabeza == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void pila::agregar(int  elemento)
{
    cajaPila *n = new cajaPila;
    n->contenido = elemento;
    n->siguiente = cabeza;
    cabeza = n;
}


int pila::sacar()
{
    cajaPila *borrar = cabeza;
    int ret = cabeza->contenido;
    cabeza = cabeza->siguiente;
    delete borrar;
    borrar = 0;
    return ret;
}


int pila::tope()
{
    int ret = cabeza->contenido;
    return ret;
}

void pila::mostrarEnPantalla()
{
    if(vacia())
    {
        cout <<"La pila esta vacia"<<endl;
    }
    else
    {
        cout << "Inicio de la pila"<<endl;
        cout << ""<<endl;
        cajaPila *iter = cabeza;
        while (iter != 0)
        {
            cout << iter->contenido<<endl;
            iter=iter->siguiente;
        }
        cout << "Fin de la pila"<<endl;
        cout <<""<<endl;
    }
}
