#include "menu.h"
#include <iostream>

using namespace  std;

void mostrar_menu(){
    cout << "1. Contar total de frutas" << endl;
    cout << "2. Buscar fruta por nombre" << endl;
    cout << "3. Ordenar alfabeticamente las frutas" << endl;
    cout << "4. Salir" << endl;
}

void procesar_opcion(int opcion_elegida, Fruta frutas[MAX_FRUTAS], int tope) {

    switch (opcion_elegida) {
        case CONTAR_FRUTAS:
            contar_frutas(frutas, tope);
            break;
        case BUSCAR_FRUTAS:
            buscar_frutas(frutas, tope);
            break;
        case ORDENAR_FRUTAS:
            ordenar_frutas(frutas, tope);
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