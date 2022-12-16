#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include "nodo.h"

using namespace std;

template <typename Dato>

class Lista {

private:
    // atributos
    Nodo<Dato>* primero;
    int longitud;

public:
    // Constructor sin parametros
    // PRE:
    // POS: crea una Lista de longitud 0 y primero apunta a NULL
    Lista ();

    // Destructor
    // PRE:
    // POS: libera la memoria solicitada
    ~Lista ();

    // Lista vacia?
    // PRE:
    // POS: devuelve verdadero si la lista esta vacia, falso de lo contrario
    bool vacia();

    // obtener longitud de la lista
    // PRE:
    // POS: devuelve la longitud de la lista
    int obtener_longitud();

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

    // obtiene el Dato en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: devuelve el dato que esta en la posicion pos (la 1 es la primera)
    Dato obtener_dato (int pos);

    // cambia el Dato que esta en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: cambia el dato que esta en la posicion pos (la 1 es la primera)
    void cambiar_dato (Dato d, int pos);

    // PRE;
    // POS: Muestra los contenidos de la lista
    void mostrar();

    void swap(int pos1, int pos2);

private:
    // devuelve un puntero al Nodo en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: devuelve un puntero al Nodo que esta en la posicion pos (la 1 es la primera)
    Nodo<Dato>* obtener_nodo (int pos);

};

template <typename Dato>
Lista<Dato>::Lista(){
    
    this -> primero = 0;
    this -> longitud = 0;

}

template <typename Dato>
Lista<Dato>::~Lista(){
    Nodo<Dato> * siguiente;
    while ( primero != nullptr ){
        siguiente = primero->obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}

template <typename Dato>
bool Lista<Dato>::vacia(){
    return (longitud == 0);
}

template <typename Dato>
Nodo<Dato> * Lista<Dato>::obtener_nodo(int pos){
    Nodo<Dato> * aux = primero;
    for ( int i = 0 ; i < pos ; i++){
        aux = aux->obtener_siguiente();
    }
    return aux;
}

template <typename Dato>
int Lista<Dato>::obtener_longitud(){
    return longitud;
}

template <typename Dato>
void Lista<Dato>::insertar(Dato d, int pos){   

    Nodo<Dato> * nuevo = new Nodo<Dato>(d);
    Nodo<Dato> * siguiente = primero;

    if ( pos == 0){
        primero = nuevo;
    } 
 
    else {
        Nodo<Dato> * anterior = obtener_nodo(pos - 1);
        siguiente = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);

    }

    nuevo->cambiar_siguiente(siguiente);
    longitud++;
}

template <typename Dato>
void Lista<Dato>::eliminar(int pos){
    Nodo<Dato> * baja = primero;

    // En caso de dar de baja el primer nodo , paso al siguiente
    if ( pos == 0){
        primero = baja->obtener_siguiente();
    }

    else {

        Nodo<Dato>* anterior = obtener_nodo(pos - 1);
        baja = anterior->obtener_siguiente();

        anterior->cambiar_siguiente(baja->obtener_siguiente());

    }

    longitud--;
    delete baja;
}

template <typename Dato>
Dato Lista<Dato>::obtener_dato(int pos){
    Nodo<Dato> * aux = obtener_nodo(pos);
    Dato d = aux->obtener_dato();
    return d;
}

template <typename Dato>
void Lista<Dato>::cambiar_dato(Dato d, int pos){
    insertar(d, pos);
    eliminar(pos-1);
}

template <typename Dato>
void Lista<Dato>::mostrar(){
    Nodo<Dato> * aux = primero;
    for ( int i = 0; i < longitud; i++){
        cout << aux->obtener_dato() << endl;
        aux = aux->obtener_siguiente();
    }
}

template <typename Dato>
void Lista<Dato>::swap(int pos1, int pos2){
    Dato d1 = obtener_dato(pos1);
    Dato d2 = obtener_dato(pos2);
    cambiar_dato(d1,pos2);
    cambiar_dato(d2,pos1);
}

#endif // LISTA_H_INCLUDED