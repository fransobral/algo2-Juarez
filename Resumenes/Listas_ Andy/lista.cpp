#include <iostream>
#include "lista.h"

Lista::Lista() {
    primero = 0;
    cantidad = 0;
}


bool Lista::vacia() {
    return (cantidad == 0);
}


void Lista::alta(Dato d, int pos) {
    Nodo* nuevo = new Nodo(d);
    std::cout << "Pido memoria en: " << nuevo << std::endl;
    Nodo* siguiente = primero;

    if (pos == 1) {
        primero = nuevo;
    }
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        siguiente = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(siguiente);
    cantidad++;
}

void Lista::baja(int pos) {
    Nodo* baja = primero;
    if (pos == 1)
        primero = baja->obtener_siguiente();
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        baja = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(baja->obtener_siguiente());
    }
    cantidad--;
    std::cout << "Libero memoria en: " << baja << std::endl;

    delete baja;
}

Dato Lista::consulta(int pos) {
    Nodo* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

Lista::~Lista() {
    while (! vacia())
        baja(1);
}

Nodo* Lista::obtener_nodo(int pos) {
    Nodo* aux = primero;
    for (int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}

void Lista::mostrar() {
    Nodo* aux = primero;
    while (aux) {
        std::cout << aux->obtener_dato() << " - ";
        aux = aux->obtener_siguiente();
    }
}
