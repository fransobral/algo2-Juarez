#ifndef TP1_UTILES_H
#define TP1_UTILES_H
#include <string>

using namespace std;

const int OPCIONES_VALIDAS = 6;
const string PATH_MATERIALES = "materiales.txt";
const string PATH_EDIFICIOS = "edificios.txt";

const int LISTAR_MATERIALES_CONSTRUCCION = 1;
const int CONSTRUIR_EDIFICIO = 2;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 3;
const int LISTAR_TODOS_LOS_EDIFICIOS = 4;
const int DEMOLER_EDIFICIO = 5;
const int GUARDAR_SALIR = 6;


struct Materiales{
    string nombre;
    int cantidad;
};

struct Edificios{
    string nombre;
    int piedra;
    int madera;
    int metal;
    int construidos;
    int maxima_cantidad;
};

struct Info{
    Materiales** materiales;
    int cantidad_materiales;
    Edificios** edificios;
    int cantidad_edificios;
};


//Pre: -
//Post: Lee el archivo materiales.txt y almacena su informacion en un struct.
void cargar_materiales(Info* info);

void agregar_material(Info* info,Materiales* materiales);

//Pre: -
//Post: Lee el archivo edificios.txt y almacena su informacion en un struct.
void cargar_edificios(Info* info);

void agregar_edificio(Info* info,Edificios* edificios);

//Pre: -
//Post: imprime por pantalla el menu
void mostrar_menu();

//Pre: -
//Post: Le solicita al usuario que ingrese el numero de la opcion que desea seleccionar//
int pedir_opcion();

//Pre: Se le ingresa un entero.
//Post: Se verifica que ese numero se encuentre dentro de un rango de opcopnes validas. De lo contrario se solicita denuevo.
void verificar_rango(int &opcion);

//Pre: Necesita la opcion elegida por el usuario,el sruct materiales y la cantidad de materiales.
//Post: Procesa la opcion del usuario y ejecuta las funciones que cumplan el objetivo del mismo.
void procesar_opcion(int opcion,Info* info);

//Pre: Necesito pasarle el struct materiales y la cantidad de materiales que contiene.
//Post: Imprime por pantalla el nombre del material y su cantidad.
void listar_materiales(Info* info);

//Pre: Necesito el struct edificios, su cantidad de elementos y el edificio a buscar.
//Post: Me busca ese edificio dentro del struct. Me devuelve un valor booleano.
bool exsiste_edificio(string nombre,Info* info);

//Pre: Le pido el nombre del edificio a buscar, la cantidad de edificios y el sruct que los almacena.
//Post: Le devuelvo la coordenada en la cual se encuentra dicho edificio.
int buscar_coordenada_edificio(string nombre,Info* info);

//Pre: Le ingreso los structs con toda la informacion, los enteros de cada material y la posicion en la cual se encuentra el edificio a construir.
//Post: Me devuelve cuanto material me quedaria tras realizar dicha construccion.
void calculadora_materiales(int posicion_edificio,Info* info, int &piedra, int &metal, int &madera);

//Pre: Necesito los structs edificios y materiales, sus respectivas cantidades y el nombre del edificio a crear.
//Post: Verifica si tengo los materiales necesarios para construir el edificio. De no ser asi, le dira cual falta.
bool verificar_disponibilidad_materiales(string nombre,Info* info);

//Pre: Necesito los structs edificios y materiales, y sus respectivas cantidades.
//Post: Construye el edificio solicitado por el usuario (en caso de ser posible).
void construir_edificio(Info* info);

//Pre: Recibe el struct materiales, su cantidad y los nuevos valores para cada elemento.
//Post: Reemplaza los valores del struct por estos nuevos ingresados.
void actualizador_materiales(Info* info, int piedra, int madera, int metal);

//Pre: Recibe el struct materiales, su cantidad y los nuevos valores para cada elemento.
//Post: Suma al struct los valores dados.
void sumar_materiales(Info*info, int piedra, int madera, int metal);


//Pre: Le paso el struct edficios y la cantidad de edificios.
//Post: Imprimo por pantalla la cantidad de edificios construidos de cada tipo (siempre y cuando haya alguno construido).
void listar_edificios_construidos(Info* info);

//Pre: Le paso el struct edificios y la cantidad de edificios.
//Post: Imprimo por pantalla toda la informacion acerca de cada edificio.
void listar_todos_edificios(Info* info);

//Pre: Le paso los structs y sus cantidades.
//Post: Le pido al usuario que edificio quiere demoler y si exsiste, lo derrumbo.
void demoler_edificio(Info *info);

//Pre: Le paso el struct materiales y la cantidad de materiales.
//Post: Paso el struct a un archivo txt para que quede todo actualizado.
void escribir_archivo_materiales(Info* info);

//Pre: Le paso el struct edificios y la cantidad de edificios.
//Post: Paso el struct a un archivo txt para que quede todo actualizado.
void escribir_archivo_edificios(Info* info);

#endif //TP1_UTILES_H
