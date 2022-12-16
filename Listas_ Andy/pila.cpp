#include <iostream>
#include "pila.h"

//Constructor
Pila::Pila() {
    tope = 0;
}


bool Pila::vacia() {
    return (tope == 0);
}


Dato Pila::consulta() {
    return tope->obtener_dato();
}


void Pila::alta(Dato d) {
    Nodo* nuevo = new Nodo(d);
    std::cout << "Pedi memoria en la dir: " << nuevo << std::endl;
    nuevo->cambiar_siguiente(tope);
    tope = nuevo;
}


Dato Pila::baja() {
    Nodo* aux = tope;
    tope = aux->obtener_siguiente();
    Dato d = aux->obtener_dato();
    std::cout << "Libero memoria de la dir: " << aux << std::endl;

    delete aux;
    return d;
}

Pila::~Pila() {

    while (! vacia())
        baja();
}

