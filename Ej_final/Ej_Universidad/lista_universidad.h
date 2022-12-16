#ifndef LISTA_UNIVERSIDAD_INCLUDED
#define LISTA_UNIVERSIDAD_INCLUDED

#include <iostream>
#include "lista.h"

using namespace std;

class Universidad 
{ 
    public: 
    // Crea una universidad con su nombre, el ranking y una lista de carreras 
    Universidad (string nombre, int ranking, Lista<string>* carreras); 
    string obtener_nombre(); // devuelve el nombre de la universidad 
    unsigned int obtener_ranking (); // devuelve el ranking 
    Lista<string>* obtener_carreras (); // devuelve ptr a lista de carreras 
    }; 
    //Implementar el método recomendar_universidades de la clase Buscador_universidades: 


class Buscador_universidades 
    { 
    public: 
    // Post: busca en “universidades” aquellas que tienen alguna carrera de la 
    // lista “vocaciones” y un ranking mayor o igual a ranking_minimo. 
    // Devuelve una lista con las universidades que cumplen con estas características. 
    Lista<Universidad *>* recomendar_universidades (Lista<Universidad *>* universidades, Lista<string>* vocaciones, int ranking_minimo); 
    bool verificar_vocacion(string nombre,Lista<string>* vocaciones);
}; 
#endif // LISTA_UNIVERSIDAD

Lista<Universidad *>* Buscador_universidades::recomendar_universidades (Lista<Universidad *>* universidades, Lista<string>* vocaciones, int ranking_minimo){
    
    Lista<Universidad*>* univ_chequeadas = new Lista<Universidad*>;
    int k = 0;

    while (universidades->hay_siguiente()){
        Universidad* universidad = universidades->obtener_nodo(i);
        Lista<string>* carreras = universidad->obtener_carreras;

        for (int j=0;j<carreras.obtener_longitud();j++){
            bool esta = verificar_vocacion(carreras->obtener_dato(i),vocaciones);
            if ((esta) && (universidad->obtener_dato(1) >= RANKING_MINIMO)){
                univ_chequeadas->insertar(universidad,k);
                k++;
            }
        }
    }`
    return univ_chequeadas;
}

bool Buscador_universidades::verificar_vocacion(string nombre,Lista<string>* vocaciones){
    bool esta = false;
    int i=0;

    while (!esta && i<vocaciones->obtener_longitud()){
        if (vocaciones->obtener_dato(i) == nombre){
            esta = true;
        }
        i++;
    }
    return esta;
}
#endif // LISTA_UNIVERSIDAD