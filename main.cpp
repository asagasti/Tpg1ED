
    #include <iostream>
#include "Cola.h"
//#include "Arbol1.h"
#include "Arbol2.h"
#include "CajLisArray.h"

#include "Algoritmos.h"
using namespace std;
using std::cout;
using std::endl;
class Arbol2;
class nodo;
class Algoritmos;
int main()
{
    cout << "Hello world!" << endl;
    cout<<"¡¡Bienvenido a las pruebas de las clases Cola, Pila y Arbol!! :)"<<endl;
    cout<<"    ¡¡ Que lo disfrutes!! =D"<<endl;
    cout<<endl<<endl<<endl;

//using std::list;

/**-Especificar los siguientes algoritmos para el modelo Árbol tal que NO importa el orden entre
los hijos de un nodo. Para cada algoritmo debe incluir: nombre, parámetros con sus tipos y
las cláusulas Efecto (claro, completo y conciso), Requiere y Modifica.
*/

/**a. Averiguar cuál es el hermano izquierdo de un nodo. prob
b. Averiguar la altura de un nodo (distancia que hay desde el nodo hasta la hoja
descendiente más alejada). prob
c. Averiguar si el árbol tiene etiquetas repetidas. prob
d. Averiguar cuántos niveles tiene el árbol.prob
e. Averiguar cuántos hijos tiene un nodo. prob
f. Listar las etiquetas correspondientes a los hijos de un nodo. prob
g. Borrar el Sub-Árbol que se genera a partir de un nodo. no fun todavia
h. Copiar un Árbol. prob
*/





    Arbol2 *a=new Arbol2();
    cout <<"Inicio de la prueba de Arbol"<<endl;
    a2->PoneRaiz(7);
    cout << endl;
    cout << endl;
    a2->AgregaHijo((a2->Raiz()),8);
    a2->AgregaHijo((a2->Raiz()),9);
    a2->AgregaHijo((a2->Raiz()),10);
    a2->AgregaHijo((a2->Raiz()),11);
    //a2->AgregaHijo((a2->Raiz()),67);
    nodo *n=(a2->Pertenece(8));
    a2->AgregaHijo(n,12);
    a2->AgregaHijo(n,13);
    a2->AgregaHijo(n,14);
    n=(a2->Pertenece(12));
    a2->AgregaHijo(n,18);
    n=(a2->Pertenece(18));
    a2->AgregaHijo(n,19);
    a2->AgregaHijo(n,20);
    n=(a2->Pertenece(20));
    a2->AgregaHijo(n,21);
    a2->AgregaHijo(n,22);
    a2->AgregaHijo(n,23);
    n=(a2->Pertenece(10));
    a2->AgregaHijo(n,15);
    n=(a2->Pertenece(11));
    cout << "Repetidos?"<<((alg->etiquetasRepetidas(a2))?"True":"False")<<endl;
    cout << "Debio dar falso"<<endl;
//    cout<<"desp pert 11"<<endl;
    a2->AgregaHijo(n,16);
    a2->AgregaHijo(n,17);
    cout << "Repetidos?"<<((alg->etiquetasRepetidas(a2))?"True":"False")<<endl;
    cout << "Debio dar falso"<<endl;
    n=(a2->Pertenece(11));
    a2->AgregaHijo(n,7);
    cout <<"agrego 7"<< endl;
    cout << "Repetidos?"<<((alg->etiquetasRepetidas(a2))?"True":"False")<<endl;
    cout << "Debio dar true"<<endl;
    cout<<"HermanoIzquierdo del nodo con etiqueta 9"<<endl;
    cout<<alg->HermanoIzquierdo(a2,9)<<endl;
//////    cout<<"Resultado esperado en arboles 1 y 2: 10"<<endl;
//////    cout<<"Resultado esperado en arboles 3,4 y 5: 8"<<endl;
////////    cout<<alg->AlturaNodo(n)<<endl;
    cout<<"Altura del nodo con etiqueta 11=";
    cout<<alg->AlturaNodo(a2,11)<<endl;
    cout<<"Altura esperada:2"<<endl;
    cout<<"Cuantos niveles tiene un arbol=";
    cout<<alg->nivelesArbol(a2)<<endl;
    cout<<"Niveles esperados:6"<<endl;
    cout<<"Cuantos hijos tiene la raiz=";
    cout<<alg->hijosNodo(a2,a2->Raiz())<<endl;
    cout<<"Hijos esperados:4"<<endl;
    cout<<"Cuantos hijos tiene el nodo con etiqueta 8=";
    cout<<alg->hijosNodo(a2,a2->Pertenece(8))<<endl;
    cout<<"Hijos esperados:3"<<endl;
    cout<<"Cuantos hijos tiene el nodo con etiqueta 9=";
    cout<<alg->hijosNodo(a2,a2->Pertenece(9))<<endl;
    cout<<"Hijos esperados:0"<<endl;
    cout<<"Cuantos hijos tiene el nodo con etiqueta 10=";
    cout<<alg->hijosNodo(a2,a2->Pertenece(10))<<endl;
    cout<<"Hijos esperados:1"<<endl;
    cout<<"Lista de hijos del nodo con etiqueta 10=>";
    n=a2->Pertenece(10);
    alg->listarHijosNodo(a2,n);
    cout<<"Hijos esperados:15"<<endl;
    cout<<"Lista de hijos del nodo con etiqueta 19=>";
    n=a2->Pertenece(19);
    alg->listarHijosNodo(a2,n);
    cout<<"Hijos esperados:no tiene"<<endl;
    cout<<"Lista de hijos del nodo con etiqueta 10=>";
    n=a2->Pertenece(11);
    alg->listarHijosNodo(a2,n);
    cout<<"Hijos esperados:7,17,16 en los arboles 1 y 2"<<endl;
    cout<<"Hijos esperados:16,17,7 en los arboles 3,4y5"<<endl;
    cout << endl;
    cout << endl;
    cout<<"Debido a las diferentes estructuras de datos con que se implementaron los arboles los resultados de las funciones hijoMasIzquierdo y HermanoDerecho pueden variar. Cada nodo siempre va a tener al mismo padre, a los mismo hermanos, a los mismo hijos pero el orden en que sus hijos y hermanos varia por lo que eso cambia."<<endl;
    cout << endl;
    Arbol2 *aCopia=new Arbol2();
    cout<<"Arbol copiado:"<<endl;
    alg->copiarArbol(a2,aCopia);
    n=a2->Pertenece(17);
    cout << "antes de entrar a borrar sub arbol"<< endl;
    alg->borrarSubArbol(a2,n);
    cout << "antes de entrar a borrar sub arbol"<< endl;
    n=a2->Pertenece(20);
    alg->borrarSubArbol(a2,n);
    cout<<"Final de la prueba de Arbol"<<endl;



}

/*
//    CajLSE *HijoMasIzquierdo(CajLSE *padre);
//    CajLSE *HermanoDerecho(CajLSE *hermano);

    Arbol *a2=new Arbol();
    cout <<"Inicio de la prueba de Arbol"<<endl;
    a2->PoneRaiz(7);
    cout << endl;
    cout << endl;
    a2->AgregaHijo((a2->Raiz()),5);
    a2->AgregaHijo((a2->Raiz()),67);
    a2->AgregaHijo((a2->Pertenece(67)),8);
    cout << endl;
    cout << endl;
    cout << "Raiz:"<<a2->Raiz()->miElem << endl;
    cout << "Raiz()==7?True"<<((a2->Etiqueta(a2->Raiz())==7)?"Bien":"Mal")<<endl;
    cout << "Raiz()==9?False"<<((a2->Etiqueta(a2->Raiz())==9)?"Mal":"Bien")<<endl;
    cout << "Etiqueta(Pertenece(5))==5"<<((a2->Etiqueta(a2->Pertenece(5))==5)?"Bien":"Mal")<<endl;
    cout << "Etiqueta(Pertenece(5))==9"<<((a2->Etiqueta(a2->Pertenece(5))==9)?"Mal":"Bien")<<endl;
    cout << "EtiquetaRaiz:"<<a2->Etiqueta(a2->Raiz()) <<"(valor esperado 7)"<< endl;
    a2->ModificaEtiqueta(a2->Raiz(),1000);
    cout << "EtiquetaRaiz:"<<a2->Etiqueta(a2->Raiz()) <<"(valor esperado 1000, por el cambio de etiqueta)"<< endl;
    cout << "Etiqueta(Pertenece(5))==5"<<((a2->Etiqueta(a2->Pertenece(5))==5)?"Bien":"Mal")<<endl;
    cout << "Vacia()?True"<<(a2->Vacio()?"Bien":"Mal")<<endl;
    cout << "Padre(Pertenece(5))==1000?False"<<((a2->Etiqueta(a2->Padre(a2->Pertenece(5)))==1000)?"Bien":"Mal")<<endl;
    cout << "Padre(Pertenece(5))==455?(la Raiz)True"<<((a2->Etiqueta(a2->Padre(a2->Pertenece(5)))==455)?"Mal":"Bien")<<endl;
    cout << "Padre(Pertenece(8))==67?False"<<((a2->Etiqueta(a2->Padre(a2->Pertenece(8)))==67)?"Bien":"Mal")<<endl;
    cout << "Padre(Pertenece(8))==5?(la Raiz)True"<<(((a2->Etiqueta(a2->Padre(a2->Pertenece(8)))==5))?"Mal":"Bien")<<endl;
    cout << "a2->HijoMasIzquierdo(a2->Pertenece(1000)):"<<(a2->HijoMasIzquierdo(a2->Pertenece(67))->miElem)<< endl;
    cout << "a2->HermanoDerecho(a2->Pertenece(67)):"<<(a2->HermanoDerecho(a2->Pertenece(67))->miElem)<< endl;
    if (a2->EsHoja(a2->Pertenece(8)))
    {
        cout << "si es hoja (bien)";
    }
    else
    {
        cout << "no es hoja (mal)"<< endl;
    }
    if (a2->EsHoja(a2->Pertenece(1000)))
    {
        cout << "si es hoja (mal)";
    }
    else
    {
        cout << "no es hoja (bien)"<< endl;
    }
    cout << "Vacia()?False"<<(a2->Vacio()?"Mal":"Bien")<<endl;
    a2->Vaciar();
    a2->mostrarLprincipal();
    cout<<"Debido a las diferentes estructuras de datos con que se implementaron los arboles los resultados de las funciones hijoMasIzquierdo y HermanoDerecho pueden variar. Cada nodo siempre va a tener al mismo padre, a los mismo hermanos, a los mismo hijos pero el orden en que sus hijos y hermanos varia por lo que eso cambia."<<endl;
    cout << endl;

    cout<<"Final de la prueba de Arbol"<<endl;







    cout<<"Inicia prueba de Cola"<<endl;
    Cola *c=new Cola();
    c->mostrarEnPantalla();
    cout << "Cola esta vacia?True"<<((c->Vacia())?"Bien":"Mal")<<endl;
    c->Agregar(3);
    cout << "Cola esta vacia?False"<<((c->Vacia())?"Mal":"Bien")<<endl;
    cout << "c->tope()==3?True"<<((c->Frente()==3)?"Bien":"Mal")<<endl;
    cout << "c->tope()==8?False"<<((c->Frente()==8)?"Mal":"Bien")<<endl;
    c->mostrarEnPantalla();
    c->Agregar(9);
    c->mostrarEnPantalla();
    c->Agregar(50);
    c->mostrarEnPantalla();
    c->Agregar(80);
    c->mostrarEnPantalla();
    //  int i=p->sacar();
    cout << "c->sacar==8?False"<<((c->Sacar()==8)?"Mal":"Bien")<<endl;
    c->mostrarEnPantalla();
    cout << "c->sacar==8?False"<<((c->Sacar()==9)?"Bien":"Mal")<<endl;
    c->mostrarEnPantalla();
    c->Vaciar();
    c->mostrarEnPantalla();
    cout << "Cola esta vacia?True"<<((c->Vacia())?"Bien":"Mal")<<endl;
    delete c;
    cout<<"Termina prueba de cola. Si salio bien es que dio el resultado esperado."<<endl;
    cout<<endl<<endl<<endl;

    cout << "Fin de la prueba de Cola" << endl;
    cout<<endl<<endl<<endl;
    /*Inicia prueba de pila*/


/*


    cout<<"Inicia prueba de pila"<<endl;
    pila *p=new pila();
    p->mostrarEnPantalla();
    cout << "Pila esta vacia?True"<<((p->vacia())?"Bien":"Mal")<<endl;
    p->agregar(3);
    cout << "Pila esta vacia?False"<<((p->vacia())?"Mal":"Bien")<<endl;
    cout << "p->tope()==3?True"<<((p->tope()==3)?"Bien":"Mal")<<endl;
    cout << "p->tope()==8?False"<<((p->tope()==8)?"Mal":"Bien")<<endl;
    p->mostrarEnPantalla();
    p->agregar(9);
    p->mostrarEnPantalla();
    cout << "p->tope()==8?False"<<((p->tope()==3)?"Mal":"Bien")<<endl;
    cout << "p->tope()==3?True"<<((p->tope()==9)?"Bien":"Mal")<<endl;
    p->mostrarEnPantalla();
    p->agregar(50);
    p->mostrarEnPantalla();
    p->agregar(80);
    p->mostrarEnPantalla();
    cout << "p->sacar==8?False"<<((p->sacar()==8)?"Mal":"Bien")<<endl;
    p->mostrarEnPantalla();
    cout << "p->sacar==8?False"<<((p->sacar()==9)?"Bien":"Mal")<<endl;
    p->mostrarEnPantalla();
    p->vaciar();
    p->mostrarEnPantalla();
    p->agregar(5);
    cout << "Pila esta vacia?True"<<((p->vacia())?"Bien":"Mal")<<endl;
    delete p;
    cout<<"Termina prueba de pila. Si salio bien es que dio el resultado esperado."<<endl;

    cout<<endl<<endl<<endl;
    /*Fin de la prueba de pila*/

    return 0;
}


//    c->mostrarEnPantalla();
//    if(c->Vacia())
//    {
//        cout<<"C esta vacia"<<endl;
//    }
//    else
//    {
//        cout<<"C no esta vacia"<<endl;
//    }
//    c->Agregar(8);
//    c->mostrarEnPantalla();
//    c->Agregar(10);
//    c->mostrarEnPantalla();
//    c->Agregar(50);
//    c->mostrarEnPantalla();
//    c->Agregar(40);
//    c->mostrarEnPantalla();
//    c->Agregar(80);
//    c->mostrarEnPantalla();
//    c->Agregar(1);
//    c->mostrarEnPantalla();
//    c->Agregar(0);
//    c->mostrarEnPantalla();
//    cout<<"Salio"<<c->Sacar()<<endl;
//    c->mostrarEnPantalla();
//    cout<<"Salio"<<c->Sacar()<<endl;
//    c->mostrarEnPantalla();
//    cout<<"Salio"<<c->Sacar()<<endl;
//    c->mostrarEnPantalla();
//    cout<<"Salio"<<c->Sacar()<<endl;
//    c->mostrarEnPantalla();
//    cout<<"Salio"<<c->Sacar()<<endl;
//    c->mostrarEnPantalla();
//    if(c->Vacia())
//    {
//        cout<<"C esta vacia"<<endl;
//    }
//    else
//    {
//        cout<<"C no esta vacia"<<endl;
//    }
//    cout<<"Salio"<<c->Sacar()<<endl;
//    c->mostrarEnPantalla();
//    c->Agregar(7);
//    c->mostrarEnPantalla();
//    c->Agregar(9);
//    c->mostrarEnPantalla();
//    c->Vaciar();
//    cout<<"Vaciando c"<<endl;
//    if(c->Vacia())
//    {
//        cout<<"C esta vacia"<<endl;
//    }
//    else
//    {
//        cout<<"C no esta vacia"<<endl;
//    }
//    c->Agregar(7);
//    c->mostrarEnPantalla();
//    c->Agregar(9);
//    c->mostrarEnPantalla();
//    if(c->Vacia())
//    {
//        cout<<"C esta vacia"<<endl;
//    }
//    else
//    {
//        cout<<"C no esta vacia"<<endl;
//    }



//cout << "EtiquetaRaiz:"<<a2->Etiqueta(a2->Raiz()) << endl;
//    if (a2->Raiz()->esPadreDe(a2->Pertenece(67)))
//    {
//        cout << "raiz es padre de 1" << endl;
//    }
//    else
//    {
//        cout << "nop padre de 5"<< endl;
//    }
//    if (a2->Padre(a2->Pertenece(5))!=0)
//    {
//        cout << "Padre de 5:"<<a2->Padre(a2->Pertenece(5))->miElem << endl;
//    }
//    else
//    {
//        cout << "Padre de 5==0"<< endl;
//    }
//    if (a2->Padre(a2->Pertenece(8))!=0)
//    {
//        cout << "Padre de 8:"<<a2->Padre(a2->Pertenece(8))->miElem << endl;
//    }
//    else
//    {
//        cout << "Padre de 8==0"<< endl;
//    }
