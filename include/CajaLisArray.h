#ifndef CAJALISARRAY_H
#define CAJALISARRAY_H
#include "CajSubLSE2.h"
#include <iostream>


using namespace std;
class CajSubLSE2;

class nodo
{
public:
    nodo();
    nodo(int i);
    virtual ~nodo();
    void agregarHijo(nodo *h);
    void borrarHijo(nodo *aBorrar);
    nodo *Padre();
    bool esPadreDe(nodo *posibleHijo);
    bool EsHoja();
    void mostrarHijosPantalla();
    CajSubLSE2 * HMI;
    int miElem;
protected:
private:
};

#endif // nodo_H

/*
Crear (tipo¡rbol A)
Efecto: Inicializa en memoria un contenedor de tipo ·rbol vacÌo
Requiere: A no inicializado
Modifica: A

Destruir (tipo¡rbol A)
Efecto: Elimina lÛgicamente a A de la memoria
Requiere: A inicializado
Modifica: A.

Vaciar(tipo¡rbol A)
Efecto: Vacia a A de contenido
Requiere: A inicializado
Modifica: A.

VacÌo(tipo¡rbol A)
Devuelve: Un booleano
Efecto: Devuelve verdadero si A est· vacÌo y falso si no
Requiere: A inicializado
Modifica: N/A

PoneRaÌz(tipoEtquieta e, tipo¡rbol A)
Efecto: Crea un TipoNodo n que contiene la etiqueta e, y lo establece como la raÌz.
Requiere: A inicializado y vacÌo, y e v·lida en A.
Modifica: A.

AgregaHijo(tipoNodo n, tipoEtiqueta e, tipo¡rbol A)
Efecto: Agrega un nodo con la etiqueta e como hijo del nodo n en el ·rbol A
Requiere: A inicializado, n v·lido en A
Modifica: A

BorraHoja(tipoNodo n, tipo¡rbol A)
Efecto: Elimina n del ·rbol A
Requiere: A inicializado, n v·lido en A y que n sea una hoja
Modifica: A

ModificaEtiqueta(tipoNodo n, tipoEtiqueta e, tipo¡rbol A)
Efecto: Actualiza la etiqueta de n a e
Requiere: A inicializado, n v·lido en A.
Modifica: A


RaÌz(tipo¡rbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo raÌz de A.
Requiere: A inicializado y no vacÌo
Modifica: N/A

Padre(tipoNodo n, tipo¡rbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo padre de n.
Requiere: A inicializado y n v·lido en A
Modifica: N/A

HijoM·sIzquierdo(tipoNodo n, tipo¡rbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo hijo m·s izquierdo de n
Requiere: A inicializado y n v·lido en A
Modifica: N/A

HermanoDerecho(tipoNodo n, tipo¡rbol A)
Devuelve: tipoNodo
Efecto: Devuelve el nodo hermano derecho de n
Requiere: A inicializado y n v·lido en A
Modifica: N/A.

Etiqueta(tipoNodo n, tipo¡rbol A)
Devuelve: tipoEtiqueta
Efecto: Devuelve la etiqueta de n
Requiere: A inicializado y n v·lido en A
Modifica: N/A

EsHoja(tipoNodo n, tipo¡rbol A)
Devuelve: tipoBooleano
Efecto: Devuelve verdadero si n no tiene hijos y falso si no
Requiere: A inicializado y n v·lido en A
Modifica: N/A

*/
