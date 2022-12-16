#include <iostream>

#include "cola.h"

//Constructor
Cola::Cola() {
    primero = 0;
    ultimo = 0;
}


bool Cola::vacia() {
    return (primero == 0);
}


Dato Cola::consulta() {
    return primero->obtener_dato();
}


void Cola::alta(Dato d) {
    Nodo* nuevo = new Nodo(d);
    std::cout << "Pedi memoria en la dir: " << nuevo << std::endl;

    if (! vacia())
        ultimo->cambiar_siguiente(nuevo);
    else
        primero = nuevo;

    ultimo = nuevo;
}


Dato Cola::baja() {
    Nodo* aux = primero;
    primero = aux->obtener_siguiente();
    if (! primero)
        ultimo = 0;

    Dato d = aux->obtener_dato();
    std::cout << "Libero memoria de la dir: " << aux << std::endl;

    delete aux;
    return d;
}

Cola::~Cola() {

    while (! vacia())
        baja();
}
