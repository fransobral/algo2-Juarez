#ifndef JUEGO_H
#define JUEGo_H
#include <string>

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__

using namespace std;

const int ERROR = -1;
const int CONSTRUIR = 1;
const int LISTAR_EDIF_C = 2;
const int LISTAR_EDIF = 3;
const int DEMOLER = 4;
const int MOSTRAR_MAPA = 5;
const int CONSULTAR_COORD = 6;
const int MOSTRAR_INVENTARIO = 7;
const int COLECTAR_RECURSOS = 8;
const int LLUVIA_RECURSOS = 9;
const int SALIR = 10;

const string PATH_MATERIALES = "materiales.txt";
const string PATH_EDIFICIOS = "edificios.txt";
const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";

struct Material{
    string nombre;
    int cantidad;
};

struct Edificio
{
    string nombre;
    int piedra;
    int madera;
    int metal;
    int n_construidos;
    int n_max_construibles;
};

struct Datos
{
    Material** materiales;
    int cantidad_de_materiales;
    Edificio** edificios;
    int cantidad_de_edificios;
};


//PRE: -
//POST: Devuelve una opcion valida para usar el menu
int pedir_y_validad_opcion();

//PRE: Se necesesita los punteros de unas variable de tipo Datos y de tipo Material
//POST: Un vector que agrega el siguiente material y devuelve su nuevo tope dentro de la variable de tipo Datos
void agregar_material(Datos* datos, Material* material);

//PRE: Se necesesita los punteros de unas variable de tipo Datos y de tipo Edificio 
//POST: Un vector que agrega el siguiente edificio y devuelve su nuevo tope dentro de la variable de tipo Datos
void agregar_edificio(Datos* datos, Edificio* edificio);

//PRE: La existencia del archivo "edificios.txt"
//POST: Recibimos una variable de tipo de dato Datos con un vector de tipo de dato Edificio completo con su respectivo tope
void procesar_edificios(Datos* datos);

//PRE: La existencia del archivo "materiales.txt"
//POST: Recibimos una variable de tipo de dato Datos con un vector de tipo de dato Material completo con su respectivo tope
void procesar_materiales(Datos* datos);

//PRE: Se necesita un numero para poder seleccionar la opcion
//POST: Te dirige a la opcion elegida
void menu(int opcion,Datos* datos);

//PRE: -
//POST: Muestra por consola las opciones del menu
void mostrar_menu();

//PRE: Se necesita un vector y un tope dentro del rango del vector
//POST:Muestra por consola los materiales y sus cantidades
void listar_inventario(Datos* datos);

//PRE: Se necesita un vector y un tope dentro del rango del vector
//POST: Muestra por consola los edificios construidos y sus cantidades
void listar_edificios_construidos(Datos* datos);

//PRE: Se necesita un vector y un tope dentro del rango del vector
//POST: Muestra por consola los datos sacados del archivo
void listar_edificios(Datos* datos);

//PRE: Vectores con los datos como integer 
//POST: Se agregan la mitad de los materiales necesarios al vector materiales y se reduce en 1 la cantidad de edificios construidos
void demoler_edificio(Datos* datos);

//PRE: Vectores con los datos como integer
//POST: Se reduce la cantidad de materiales necesarios al vector materiales y se suma en 1 la cantidad de edificios construidos
void construir_edificio(Datos* datos);

//PRE: -
//POST: Modifica los Archivos con los datos cambiados en el programa
void guardar_contenido(Datos* datos);

//PRE: -
//POST: Modifica el archivo "materiales.txt" con los datos cambiados en el programa
void guardar_materiales(Datos* datos);

//PRE: -
//POST: Modifica el archivo "edificios.txt" con los datos cambiados en el programa
void guardar_edificios(Datos* datos);

//PRE: Se necesita un vector y un tope dentro del rango del vector (que esta incluido en el puntero de la variable de tipo Datos)
//POST: Devuelve la posicion del edificio buscado
void buscador_de_posicion_edificio(int &posicion, string nombre_edificio, Datos* datos);

//PRE: Se necesita un vector y un tope dentro del rango del vector (que esta incluido en el puntero de la variable de tipo Datos)
//POST: Devuelve la posicion del material buscado
void buscador_posicion_del_material(int &posicion, string nombre_material, Datos* datos);

#endif //JUEGO_H
