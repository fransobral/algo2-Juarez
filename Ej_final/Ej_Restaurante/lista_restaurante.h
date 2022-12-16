#ifndef LISTA_RESTAURANTE_INCLUDED
#define LISTA_RESTAURANTE_INCLUDED

#include <iostream>
#include "lista.h"

using namespace std;

class Restaurante 
{ 
    public: 
    // Crea un restaurante con su nombre, el precio promedio por cubierto y 
    // una lista de platos que sirve 
    Restaurante (string nombre, int precio_promedio, Lista<string>* platos); 
    string obtener_nombre(); // devuelve el nombre del restaurante 
    int obtener_precio_promedio (); // devuelve el precio promedio 
    Lista<string>* obtener_platos (); // devuelve ptr a la lista de platos 
    }; 
//Implementar el método recomendar_restaurantes de la clase Buscador_restaurantes: 

class Buscador_restaurantes 
{ 
    public: 
    // Post: busca en “restaurantes” aquellos que tienen por lo menos dos platos de la 
    // lista “platos_deseados” y un precio promedio menor o igual a precio_maximo. 
    // Devuelve una lista con los restaurantes que cumplen con estas características. 
    Lista<Restaurante *>* recomendar_restaurantes (Lista<Restaurante *>* 
    restaurantes, Lista<string>* platos_deseados, int precio_maximo); 
}; 

Lista<Restaurante *>* Buscador_restaurantes::recomendar_restaurantes (Lista<Restaurante *>* restaurantes, Lista<string>* platos_deseados, int precio_maximo){
    Lista<Restaurante*>* rest_chequeadas = new Lista<Restaurante*>;
    int k = 0;

    for (int i = 0; i<restaurantes.obtener_longitud();i++){
        Nodo<Dato>* restaurante = restaurantes->obtener_nodo(i);
        bool esta = verificar_deseados(restaurante->obtener_nombre());
        if (esta && restaurante->obtener_precio_promedio() <= PRECIO_MAXIMO){
            rest_chequeadas->insertar(restaurante,k);
            k++;
        }}
    return rest_chequeadas;
}

bool Buscador_restaurantes::verificar_deseados(string nombre,Lista<string>* deseados){
    bool esta = false;
    int i=0;

    while (!esta && i<deseados->obtener_longitud()){
        if (deseados->obtener_dato(i) == nombre){
            esta = true;
        }
        i++;
    }
    return esta;
}
#endif // LISTA_RESTAURANTE