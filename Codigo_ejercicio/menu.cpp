#include "menu.h"
#include <iostream>
#include "frutas.h"

using namespace  std;

void mostrar_menu(){
    cout << "1. Contar total de frutas" << endl;
    cout << "2. Buscar fruta por nombre" << endl;
    cout << "3. Ordenar alfabeticamente las frutas" << endl;
    cout << "4. Salir" << endl;
}

void procesar_opcion(int opcion_elegida) {

    switch (opcion_elegida) {
        case CONTAR_FRUTAS:
            //rellenar con una sola linea
            break;
        case BUSCAR_FRUTAS:
            //rellenar con una sola linea
            break;
        case ORDENAR_FRUTAS:
            //rellenar con una sola linea
            break;
        case SALIR:
            cout << "Adios!"<< endl;
            break;
        default:
            cout << "Error: opcion invalida";
    }
}

bool es_opcion_valida(int elegida) {
    return (elegida >= OPCION_MINIMA && elegida <= OPCION_MAXIMA);
}