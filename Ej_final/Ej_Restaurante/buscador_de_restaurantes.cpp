#include "buscador_de_restaurantes.h"

Lista<Restaurante *>* Buscador_restaurantes::recomendar_restaurantes(Lista<Restaurante *>*
    restaurantes, Lista<string>* platos_deseados, int precio_maximo){
    
    Lista<Restaurante*>* recomendados = new Lista<Restaurante*>* ;
    int cantidad_de_restaurantes = 0;
    Restaurante* restaurante;
    Lista<string>* menu;
    
    restaurantes -> reiniciar();

    while (restaurantes -> hay_siguiente()){
        restaurante = restaurantes -> siguiente();
        menu = restaurante -> obtener_platos();
        menu -> reiniciar();
        
        

        if (restaurante -> obtener_precio_promedio() <= precio_maximo){
            if (esta_plato(platos_deseados,menu)){
                recomendados -> insertar(restaurante,cantidad_de_restaurantes);
                cantidad_de_restaurantes++; 
            }
        }
    }

    return recomendados;
}

bool Buscador_restaurantes::esta_plato(Lista<string>* platos_deseados, Lista<string>* menu){
    
    int platos_iguales = 0;
    string plato_deseado, plato;
    
    while (menu -> hay_siguiente() && platos_iguales < 2){ 
        plato = menu -> siguiente();
        
        while (platos_deseados -> hay_siguiente() && plato_deseado != plato){
            plato_deseado = platos_deseados -> siguiente();
        }
        platos_deseados -> reiniciar();

        if (plato_deseado == plato){
            platos_iguales++;
        }
    }

    return (platos_iguales == 2);
}