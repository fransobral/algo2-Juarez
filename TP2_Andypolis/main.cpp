#include <iostream>
#include "juego.h"

using namespace std;

int main(){
    
    Datos* datos = new Datos;
    int opcion = 0;

    procesar_materiales(datos);
    procesar_edificios(datos);
    system(CLR_SCREEN);
    cout<<"Bienvenido a Andypolis!"<<endl;
    do
    {
        mostrar_menu();
        opcion = pedir_y_validad_opcion();
        menu(opcion,datos);
    } while (opcion != SALIR);
    
    cout<<endl<<"Gracias por jugar! Hasta pronto!\n"<<endl;

    delete datos;

    return 0;
}
