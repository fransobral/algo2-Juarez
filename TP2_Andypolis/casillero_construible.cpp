#include <iostream>
#include "casillero_construible.h"

void casillero_construible::mostrar_casillero(){
    if (edificio_en_casillero.delvolver_cantidad_construida() > 0){
        cout << "Soy un casillero transitable y no me encuentro vacío." << endl;
        edificio_en_casillero.mostrar_edificio_en_casillero();
    }
    else
    cout << "Soy un casillero transitable y me encuentro vacío." << endl;
}

void casillero_construible::agregar_edificio(edificio edificio_en_casillero){
    this -> edificio_en_casillero = edificio_en_casillero;
}