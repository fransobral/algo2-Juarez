#ifndef FRUTAS_H
#define FRUTAS_H

#include <string>

const int MAX_FRUTAS = 50;
const int ERROR =-1;

struct Fruta{
    std::string nombre;
    int cantidad;
};

//pre: El tope debe ser un numero positivo y valido, el vector de frutas debe estar cargado y respetar el tope
//post: Muestra la cantidad de frutas que hay
void contar_frutas(Fruta frutas[MAX_FRUTAS], int tope);

//pre: El tope debe ser un numero positivo y valido, el vector de frutas debe estar cargado y respetar el tope
//post: Muestra si hay o no una fruta en la heladera
void buscar_frutas(Fruta frutas[MAX_FRUTAS], int tope);

//pre:  El tope debe ser un numero positivo y valido, el vector de frutas debe estar cargado y respetar el tope
//post: Ordena las frutas que hay en la heladera
void ordenar_frutas(Fruta frutas[MAX_FRUTAS], int tope);

//pre:  El tope debe ser un numero positivo y valido, el vector de frutas debe estar cargado y respetar el tope
//post: Muestra todas las frutas por pantalla
void mostrar_frutas(Fruta frutas[MAX_FRUTAS], int tope);

#endif //FRUTAS_H
