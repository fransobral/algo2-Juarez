#include <iostream>
#include "menu.h"

using namespace std;

//pre: -
//post: procesa el archivo y carga el vector de frutas.
void procesar_archivo();

int main() {
    procesar_archivo();
    int opcion_elegida;
    do{
        cout << "Bienvenido a la fruteria! ¿que desea hacer?" << endl;
        mostrar_menu();
        cin >> opcion_elegida;
        while(!es_opcion_valida(opcion_elegida)){
            cout << "Ese numero de opcion no es valido, intentemos otra vez:";
            mostrar_menu();
            cin >> opcion_elegida;
        }
        procesar_opcion(opcion_elegida);
    }while(opcion_elegida != SALIR);

    return 0;
}


void procesar_archivo() {

}


