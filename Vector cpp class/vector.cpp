#include <iostream>
#include "vector.h"

// Constructor
Vector::Vector(int l) {
    largo = l;
    datos = new Dato[largo];
    inicializar(0, largo);
}

void Vector::inicializar(int desde, int hasta) {
    for (int i = desde; i < hasta; i++)
        datos[i] = NULO;
}

Dato Vector::consultar(int posicion) {
    return datos[posicion];
}

void Vector::cambiar(int posicion, Dato valor) {
    datos[posicion] = valor;
}

void Vector::mostrar() {
    for (int i = 0; i < largo; i++)
        std::cout << datos[i] << " ";
    std::cout << std::endl;
}

Vector::~Vector() {
    std::cout << "Ejecuta el destructor" << std::endl;

    if (largo > 0)
        delete [] datos;
}



void Vector::agrandar(int cantidad) {
    int nueva_longitud = largo + cantidad;
    Dato* aux = new Dato[nueva_longitud];
    copiar(aux, 0, largo);
    delete [] datos;
    datos = aux;
    inicializar(largo, nueva_longitud);
    largo = nueva_longitud;
}


void Vector::copiar(Dato* pd, int desde, int hasta) {
    for (int i = desde; i < hasta; i++)
        pd[i] = datos[i];
}
