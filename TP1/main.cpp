#include <iostream>
#include <cstdlib>
#include "utiles.h"
int main() {

    Info* info = new Info;

    cargar_materiales(info);
    cargar_edificios(info);

    mostrar_menu();
    int opcion = pedir_opcion();

    while (opcion != GUARDAR_SALIR){
        verificar_rango(opcion);
        procesar_opcion(opcion,info);
        mostrar_menu();
        opcion = pedir_opcion();
        if (opcion == GUARDAR_SALIR){
            escribir_archivo_materiales(info);
            escribir_archivo_edificios(info);
            cout << "\nLos cambios fueron guardados con exito, cerraremos el programa." << endl;
        }
    }
    return 0;
}
