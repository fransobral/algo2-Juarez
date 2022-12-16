#include <iostream>
#include <fstream>
#include "menu.h"
#include "frutas.h"

using namespace std;
const string PATH_ARCHIVO = "C:\\Users\\Vanina\\CLionProjects\\untitled3\\frutas.txt";

//pre: -
//post: procesa el archivo y carga el vector de frutas.
void procesar_archivo(Fruta frutas[MAX_FRUTAS], int &tope);

int main() {
    Fruta frutas[MAX_FRUTAS];
    int tope;
    procesar_archivo(frutas, tope);
    if(tope != ERROR){
        int opcion_elegida;
        do{
            cout << "Bienvenido a la fruteria!" << endl;
            mostrar_frutas(frutas, tope);
            cout << "Escriba una opcion" << endl;
            mostrar_menu();
            cin >> opcion_elegida;
            while(!es_opcion_valida(opcion_elegida)){
                cout << "Ese numero de opcion no es valido, intentemos otra vez:"<< endl;
                mostrar_menu();
                cin >> opcion_elegida;
            }
            procesar_opcion(opcion_elegida, frutas, tope);
        }while(opcion_elegida != SALIR);

    }

    return 0;
}


void procesar_archivo(Fruta frutas[MAX_FRUTAS], int &tope) {
    Fruta fruta;
    string cantidad;
    int contador = 0;

    ifstream archivo(PATH_ARCHIVO);

    if (!archivo.is_open()){
        cout << "No se enontro el archivo" << endl;
        tope = ERROR;
    }else{
        while(archivo >> fruta.nombre){
            archivo >> cantidad;
            fruta.cantidad = stoi(cantidad);
            frutas[contador] = fruta;
            contador++;
        }
        tope = contador;
    }

    archivo.close();
}


