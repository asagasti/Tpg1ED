#ifndef CAJACOLA_H
#define CAJACOLA_H


class CajaCola
{
public:
    CajaCola();
    CajaCola(int v);           //constructor con valor
    virtual ~CajaCola();       //destructor de memoria
    void ponValor(int v);  //asigna valor al caja
    int obValor();        //recupera el valor del caja
    bool estaUsado();         //indica si el caja esta siendo usado o esta libre
    CajaCola *obSig();       //obtiene apuntador al siguiente caja
    void ponSig(CajaCola *c);

    //Atributos publicos se consideran una falla de seguridad, pero a pesar de esto se usan en este ejemplo
    int val;               //valor guardado en el caja
    bool usado;             //bandera de uso
    CajaCola *ptrSig;         //puntero o apuntador a la siguiente caja
protected:
private:

};

#endif
