/*
{ 
public: 
// Crea un alimento con su nombre, la cantidad de calorías y una lista 
// de los ingredientes que lo conforman 
Alimento (string nombre, unsigned int calorias, Lista<string>* ingredientes); 
string obtener_nombre(); // devuelve el nombre del alimento 
unsigned int obtener_calorias (); // devuelve la cantidad de calorías 
Lista<string>* obtener_ingredientes (); // devuelve un ptr la lista de ingredientes 
}; 
Implementar el método comidas_para_celiacos de la clase Buscador_de_comidas: 
class Buscador_de_comidas 
{ 
public: 
// Post: busca en “comidas” aquellas que tienen algún ingrediente de la 
// lista “ingredientes_permitidos” y ninguno de la lista 
“ingredientes_no_permitidos” 
// y tienen una caloría menor a “caloría_maxima”. 
// Devuelve una lista con los alimentos que cumplen con estas características. 
Lista<Alimento *>* comidas_para_celiacos (Lista<Alimento *>* comidas, 
Lista<string>* ingredientes_permitidos, Lista<string>* 
ingredientes_no_permitidos, 
unsigned int calora_maxima); 
}; í
*/
#ifndef LISTA_ALIMENTOS_INCLUDED
#define LISTA_ALIMENTOS_INCLUDED

#include <iostream>
#include "lista.h"

using namespace std;

class Alimento{ 
    public: 
        // Crea un alimento con su nombre, la cantidad de calorías y una lista 
        // de los ingredientes que lo conforman 
        Alimento (string nombre, unsigned int calorias, Lista<string>* ingredientes); 

        string obtener_nombre(); // devuelve el nombre del alimento 
 
        unsigned int obtener_calorias (); // devuelve la cantidad de calorías 
 
        Lista<string>* obtener_ingredientes (); // devuelve un ptr la lista de ingredientes 
    };


class Buscador_de_comidas { 
    public: 
        // Post: busca en “comidas” aquellas que tienen algún ingrediente de la 
        // lista “ingredientes_permitidos” y ninguno de la lista “ingredientes_no_permitidos” 
        // y tienen una caloría menor a “caloría_maxima”. 
        // Devuelve una lista con los alimentos que cumplen con estas características. 
        Lista<Alimento *>* comidas_para_celiacos (Lista<Alimento *>* comidas, 
        Lista<string>* ingredientes_permitidos, Lista<string>* ingredientes_no_permitidos, unsigned int caloría_maxima); 
        Lista<string>* verificar_alimentos(Lista<string>* ingredientes, Lista<string>* ingredientes_chequear);
        }; 

Lista<string>* Buscador_de_comidas::verificar_alimentos(Lista<string>* ingredientes, Lista<string>* ingredientes_chequear){
    bool esta = false;
    Lista<string>* alimentos_chequeados = new Lista<string>;
    int k=0;

    for (int i=0,i>ingredientes->obtener_longitud(),i++){
        int j=0;
        while(j<ingredientes_chequear->obtener_longitud() && !esta){
            if (ingredientes->obtener_dato(i) == ingredientes_chequear->obtener_dato(j)){
                alimentos_chequeados -> insertar(ingredientes->obtener_dato(i),k);
                k++;
                esta = true;
            }
            j++;}}
    return alimentos_chequeados;
    
}

Lista<Alimento *>* Buscador_de_comidas::comidas_para_celiacos(Lista<Alimento *>* comidas, Lista<string>* ingredientes_permitidos, Lista<string>* ingredientes_no_permitidos, unsigned int caloría_maxima){
    Lista<Alimento *>* aptos_celiacos = new Lista<Alimento>;
    int j = 0;

    for (int i=0,i<comidas->obtener_longitud(),i++){
        Nodo<Dato>* comida = comidas->obtener_nodo(i);
        Lista<string>* ali_permit;
        ali_permit = verificar_alimentos(comida->obtener_ingredientes(),ingredientes_permitidos);
        ali_no_permit = verificar_alimentos(comida->obtener_ingredientes(),ingredientes_no_permitidos);
        int calorias = comida->obtener_calorias();

        if ((ali_permit->obtener_longitud() > 0) && (ali_no_permit->obtener_longitud()==0) && (calorias<CALORIA_MAXIMA)){
            aptos_celiacos -> insertar(comida,j);
            j++;
        }

    }
    return aptos_celiacos;
}
#endif // LISTA_ALIMENTOS