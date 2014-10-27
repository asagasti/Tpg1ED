Enter file contents here#ifndef ALGORITMOSHASTAJ
#define ALGORITMOSHASTAJ
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <algorithm>
#include "Arbol2.h"
#include "CajLisArray.h"
#include "Cola.h"
using std::cout;
using std::endl;
using std::list;
using std::vector;
using namespace std;

/**-Especificar los siguientes algoritmos para el modelo Árbol tal que NO importa el orden entre
los hijos de un nodo. Para cada algoritmo debe incluir: nombre, parámetros con sus tipos y
las cláusulas Efecto (claro, completo y conciso), Requiere y Modifica.
*/

/**a. Averiguar cuál es el hermano izquierdo de un nodo.
b. Averiguar la altura de un nodo (distancia que hay desde el nodo hasta la hoja
descendiente más alejada).
c. Averiguar si el árbol tiene etiquetas repetidas.
d. Averiguar cuántos niveles tiene el árbol.
e. Averiguar cuántos hijos tiene un nodo.
f. Listar las etiquetas correspondientes a los hijos de un nodo.
g. Borrar el Sub-Árbol que se genera a partir de un nodo.
h. Copiar un Árbol.
*/
class Cola;
class Algoritmos
{
    public:
        Algoritmos();
        virtual ~Algoritmos();
        nodo * HermanoIzquierdoM(Arbol *a, nodo *n);
        int AlturaNodo(Arbol *a, nodo *n);
        bool etiquetasRepetidas(Arbol *a);
        int nivelesArbol(Arbol *a);
        int hijosNodo(Arbol *a, nodo *n);
        void listarHijosNodo(Arbol *a, nodo *n);
        void borrarSubArbol(Arbol *a, nodo *n);
        void copiarArbol (Arbol *aOriginal, Arbol *aCopia);
        /**Averiguar cual es el hermano izquierdo de un nodo.
        Parametros: tipoNodo n
        Efecto:Averigua cual es el hermano izquierdo de un nodo y lo devuelve(o devuelve un nulo de no tenerlo)
        Requiere: Arbol inicializado, que la etiqueta enviada como parametro este en algun nodo del arbol y no sea repetida.
        Modifica: N/A*/
        int HermanoIzquierdo(Arbol *a, int HD);
        int AlturaNodo(Arbol *a, int etiqueta);
        int AlturaNodoRe(Arbol *a, nodo *n);
        void borrarSubArbolRe(Arbol *a, nodo *n);
        nodo *direccionNodo(Arbol *a, nodo *padre, int etiqueta);
//        int numHijos(Arbol *a, int i);
//        int numHijos(Arbol *a, nodo *n);
//        //Arbol2 *a;

    protected:
    private:
};

#endif // ALGORITMOS DEL A AL J_H
/**Averiguar cual es el hermano izquierdo de un nodo.
        Parametros: tipoNodo n
        Efecto:Averigua cual es el hermano izquierdo de un nodo y lo devuelve(o devuelve un nulo de no tenerlo)
        Requiere: Arbol inicializado, que la etiqueta enviada como parametro este en algun nodo del arbol y no sea repetida.
        Modifica: N/A*/
