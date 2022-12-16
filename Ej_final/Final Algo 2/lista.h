#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

class Lista {

private:
    // atributos
    Nodo* primero;
    int longitud;

public:
    // Constructor sin parametros
    // PRE:
    // POS: crea una Lista de longitud 0 y primero apunta a NULL
    Lista ( );

    // Constructor de copia
    // PRE: lista es una Lista valida
    // POS: crea una Lista igual a lista
    Lista (const Lista& lista);

    // Destructor
    // PRE:
    // POS: libera la memoria solicitada
    ~Lista ( );

    // Lista vacia?
    // PRE:
    // POS: devuelve verdadero si la lista esta vacia, falso de lo contrario
    bool vacia( );

    // obtener longitud de la lista
    // PRE:
    // POS: devuelve la longitud de la lista
    int obtener_longitud( );

    // insertar un dato en cierta posicion
    // PRE: d dato valido y 0 < pos <= longitud + 1
    // POS: inserta el Dato d en la posicion pos (la 1 es la primera),
    //      inrementa en 1 la longitud
    void insertar (Dato d, int pos);

    // eliminar un Nodo en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: elimina el Nodo en la posicion pos (la 1 es la primera),
    //      libera memoria y decrementa en uno la longitud
    void eliminar (int pos);

    // obtiene el DAto en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: devuelve el dato que esta en la posicion pos (la 1 es la primera)
    Dato obtener_dato (int pos);

    // cambia el DAto que esta en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: cambia el dato que esta en la posicion pos (la 1 es la primera)
    void cambiar_dato (Dato d, int pos);

    //PRE: tiene que haber mas de un item en la lista para que haga efecto.
    //POST: revierte la lista (la modifica). El último elemento pasa al primer lugar, el penúltimo al segundo, etc.
    void revertir( );

    //PRE: pos1 y pos 2 tienen que estar dentro de los parametros de la lista
    //POST: intercambia entre si dos datos de lugar.
    void intercambio_datos(int pos1, int pos2);

private:
    // devuelve un puntero al Nodo en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: devuelve un puntero al Nodo que esta en la posicion pos (la 1 es la primera)
    Nodo* obtener_nodo (int pos);

};

void Lista::revertir(){
    int tam = obtener_longitud();

    for (int i=0;i<(tam/2);i++){
        intercambio_datos(i,tam-(i+1));
    }}


void Lista::intercambio_datos(int pos1, int pos2){
    Dato d1 = obtener_dato(pos1);
    Dato d2 = obtener_dato(pos2);

    cambiar_dato(d1,pos2);
    cambiar_dato(d2,pos1);
}


#endif // LISTA_H_INCLUDED