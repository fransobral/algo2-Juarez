class Pelicula {

    public:

    /* Crea una Pelicula con su nombre, puntaje y una lista de actores (strings) */
    Pelicula (string nombre, int puntaje, Lista<string>* actores);

    /* devuelve el nombre de la Pelicula */
    string obtener_nombre(); 

    /* devuelve el puntaje */
    int obtener_puntaje (); 

    /* devuelve un ptr a lista de actores */
    Lista<string>* obtener_actores (); 
    };



//Implementar el método recomendar_peliculas de la clase Servicio_streaming según:

class Servicio_streaming {
    public:
    /* 
    Post: busca en “pelculas_ofrecidas” aquellas que tienen por lo menos un actor de la lista 
    “peliculas_vistas” y un puntaje mayor o igual a puntaje_minimo.
    Devuelve un puntero a una lista con las películas que cumplen con estas características.
    */

    Lista<Pelicula *>* recomendar_peliculas (Lista<Pelicula *>*  peliculas_ofrecidas, 

    Lista<Pelicula *>* peliculas_vistas, int puntaje_minimo);


    //Pre: Necesito tener todos los parametros necesarios para plicar el filtro para ver si agregamos la pelicula o no.
    //Post: Me agrega la pelicula a la lista nueva si cumple las condiciones necesarias.
    void verificar_peliculas_vistas(Lista<Pelicula*>* peliculas_filtardas,Lista<Pelicula *>* peliculas_vistas,
            Pelicula* pelicula,Lista<string>* actores,int puntaje_minimo,int k);

    //pre: necesito un nombre de actor para poder comparar con la lista de actores pedida tambien como parametro
    //post: me devuelve un true si el actor pasado se encuentra en la lista de actores
    bool verificar_actores(string nombre,Lista<string>* actores_vistos);

    };

Lista<Pelicula *>* Servicio_streaming::recomendar_peliculas(Lista<Pelicula *>*  peliculas_ofrecidas, 
    Lista<Pelicula *>* peliculas_vistas,int puntaje_minimo){
        Lista<Pelicula*>* peliculas_filtardas = new Lista<Pelicula*>;
        int k=0;
        peliculas_ofrecidas->reiniciar();

        while(peliculas_ofrecidas -> hay_siguiente()){

            Pelicula* pelicula = peliculas_ofrecidas->siguiente();
            Lista<string>* actores = pelicula->obtener_actores();
            actores -> reiniciar();

            verificar_peliculas_vistas(peliculas_filtradas,peliculas_vistas,pelicula,actores,puntaje_minimo,k);
            }}

    return peliculas_filtradas;
        
bool Servicio_streaming::verificar_actores(string nombre,Lista<string>* actores_vistos){
    bool esta = false;
    int i=0;

    while (!esta && i<actores_vistos->obtener_longitud()){
        if (actores_vistos->obtener_dato(i) == nombre){
            esta = true;
        }
        i++;
    }
    return esta;
}

void Servicio_streaming::verificar_peliculas_vistas(Lista<Pelicula*>* peliculas_filtardas,Lista<Pelicula *>* peliculas_vistas,
            Pelicula* pelicula,Lista<string>* actores,int puntaje_minimo,int k){
    peliculas_vistas->reiniciar();
    bool agregue = false;

    while(peliculas_vistas ->hay_siguiente()&& !agregue){
        Pelicula* pelicula_vista = peliculas_vistas->siguiente();
        Lista<string>* actores_vistos = pelicula->obtener_actores();
        actores_vistos -> reiniciar();

        for (int j=0;j<actores->obtener_longitud();j++){
            esta = verificar_actores(actores->obtener_dato(j),actores_vistos);

            if ((esta) && (pelicula->obtener_puntaje >= puntaje_minimo)){
                peliculas_filtardas->insertar(pelicula,k);
                agregue = true;
                k++;}
        }
    }} 
    }