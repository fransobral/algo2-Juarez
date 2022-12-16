#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"


class Lista {
    // Atributos
private:
    Nodo* primero;
    int cantidad;

    // Metodos
public:
    //Constructor
    //PRE: -
    //POS: tope = 0
    Lista();

    //PRE: 1 <= pos <= cantidad + 1
    //POS: agrega d arriba de la pila e incrementa tope en 1
    void alta(Dato d, int pos);

    //PRE: 1 <= pos <= cantidad
    //POS: devuelve el dato que esta arriba
    Dato consulta(int pos);

    //PRE: 1 <= pos <= cantidad
    //POS: devuelve el dato que esta arriba y decrementa tope
    void baja(int pos);


    //PRE: -
    //POS: devuelve true si la pila esta vacia, false si no
    bool vacia();

    //Destructor
    ~Lista();

    //NO VA COMO PRIMITIVA DE LISTAº
    void mostrar();

private:
    Nodo* obtener_nodo(int pos);
};



#endif // LISTA_H_INCLUDED
