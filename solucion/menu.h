#ifndef MENU_H
#define MENU_H

#include "frutas.h"

const int CONTAR_FRUTAS = 1;
const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 4;
const int BUSCAR_FRUTAS = 2;
const int ORDENAR_FRUTAS = 3;
const int SALIR = 4;

//pre: -
//post: Imprime por pantalla el menu
void mostrar_menu();

//pre: -
//post: Realiza la opcion pedida
void procesar_opcion(int opcion_elegida, Fruta frutas[MAX_FRUTAS], int tope);

//pre: -
//post: devuelve true si la opcion recibida esta en el rango valido y sino devuelve false.
bool es_opcion_valida(int elegida);

#endif //MENU_H
