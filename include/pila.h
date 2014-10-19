#ifndef PILA
#define PILA

using namespace std;



template <class T>
class pila{
private:					//nadie mas puede ver el forward_list
    struct nodo{
        T contenido;
        nodo *siguiente;
    };
    nodo *cabeza = new nodo;
public:
    pila();
    ~pila();			//declarar las funciones
    bool vacia();
    void vaciar();
    void agregar(T);
    T sacar();
    T tope();

};

template <class T>
pila<T>::pila(){
    cabeza = NULL;
}


template <class T>				//esto va antes de cada funcion
    pila<T>::~pila(){
        nodo *borrar;           // pila<T>::vaciar significa el metodo vaciar dentro de la clase pila con template T
        while(cabeza != NULL){
            borrar = cabeza;
            cabeza = cabeza->siguiente;
            delete borrar;
        }
        delete cabeza;
    }

template <class T>
    void pila<T>::vaciar(){
        nodo *borrar;
        while(cabeza != NULL){
            borrar = cabeza;
            cabeza = cabeza->siguiente;
            delete borrar;
        }
    }

template <class T>
    bool pila<T>::vacia(){
        if (cabeza == NULL){
            return true;
        }
        else{
            return false;
        }
    }

template <class T>
void pila<T>::agregar(T elemento){
    nodo *n = new nodo;
    n->contenido = elemento;
    n->siguiente = cabeza;
    cabeza = n;
}

template <class T>
    T pila<T>::sacar(){
    nodo *borrar = new nodo;
    borrar = cabeza;
    T ret = cabeza->contenido;
    cabeza = cabeza->siguiente;
    delete borrar;
    borrar = NULL;
    return ret;
    }

template <class T>
    T pila<T>::tope(){
    T ret = cabeza->contenido;
    return ret;
}
#endif // PILA
