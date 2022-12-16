#include <iostream>
#include "casillero_transitable.h"

using namespace std;

void casillero_transitable::mostrar_casillero(){
    if (material_en_casillero.devolver_cantidad() > 0){
    cout << "Soy un casillero transitable y no me encuentro vacío. " << endl;
    material_en_casillero.mostrar_material_en_casillero();
    }
    else
    cout << "Soy un casillero transitable y me encuentro vacío. " << endl;
}

void casillero_transitable::agregar_material(material material_en_casillero){
    this -> material_en_casillero = material_en_casillero;
}