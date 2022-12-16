#include "frutas.h"
#include <iostream>

using namespace  std;

void mostrar_cantidad_frutas(int total);

string pedir_fruta();

int buscar_fruta(Fruta frutas[MAX_FRUTAS], int tope, string fruta_buscada);

void mostrar_posicion_fruta(int posicion, string fruta);


void contar_frutas(Fruta frutas[MAX_FRUTAS], int tope){
    int total = 0;
    for (int i = 0; i < tope; i++){
        total += frutas[i].cantidad;
    }
    mostrar_cantidad_frutas(total);
}

void mostrar_cantidad_frutas(int total) {
    cout << "La cantidad de frutas que hay en la heladera es: " << total << endl << endl;
}

void buscar_frutas(Fruta frutas[MAX_FRUTAS], int tope){
    string fruta_buscada = pedir_fruta();
    int posicion = buscar_fruta(frutas, tope, fruta_buscada);
    mostrar_posicion_fruta(posicion, fruta_buscada);


}

void mostrar_posicion_fruta(int posicion, string fruta) {
    if(posicion == ERROR){
        cout << "No se encontro una fruta con el nombre " << fruta << endl << endl;
    }else{
        cout << "La fruta " << fruta << " se encuentra en la posicion " << (posicion - 1) << endl << endl;
    }
}

int buscar_fruta(Fruta frutas[MAX_FRUTAS], int tope, string fruta_buscada) {
    bool es_encontrada = false;
    int contador = 0;

    while(contador < tope && !es_encontrada){
        if(frutas[contador].nombre == fruta_buscada){
            es_encontrada = true;
        }
        contador++;
    }

    if(!es_encontrada){
        contador = ERROR;
    }

    return contador;
}

string pedir_fruta() {
    string fruta;
    cout << "Indique el nombre de la fruta que desea buscar" << endl;
    cin >> fruta;
    return fruta;
}

void ordenar_frutas(Fruta frutas[MAX_FRUTAS], int tope){
    Fruta temporal;

    for (int i = 0;i < tope; i++){
        for (int j = 0; j< tope - 1; j++){

            if (frutas[j].nombre > frutas[j+1].nombre){
                temporal = frutas[j];
                frutas[j] = frutas[j+1];
                frutas[j+1] = temporal;
            }
        }
    }
}

void mostrar_frutas(Fruta frutas[MAX_FRUTAS], int tope){

    cout << endl << "Estas son las frutas de la heladera:" << endl;
    for (int i = 0; i < tope; i++){
        cout << "Tenemos " << frutas[i].cantidad << " unidades de " << frutas[i].nombre << endl;
    }
    cout << endl;
}