#include <fstream>
#include <iostream>
#include "juego.h"

using namespace std;

int pedir_y_validad_opcion(){
    int opcion = ERROR;
    cout<<"\nElegi una de las opciones: ";
    cin >> opcion;
    system(CLR_SCREEN);

    bool es_opcion_valida = opcion > 0 && opcion <= SALIR;
    while(!es_opcion_valida){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        cin >> opcion;
        es_opcion_valida = opcion > 0 && opcion <= SALIR;
    }

    return opcion;
}


void procesar_materiales(Datos* datos){
    ifstream archivo(PATH_MATERIALES);
    
    Material* material;
    string nombre, cantidad;
    datos -> cantidad_de_materiales = 0;

    while(archivo >> nombre){
        archivo >> cantidad;
        
        material = new Material;
        material -> nombre = nombre;
        material -> cantidad = stoi(cantidad);

        agregar_material(datos, material);
    }
    archivo.close();

}

void agregar_material(Datos* datos, Material* material){
    int tope_viejo = datos->cantidad_de_materiales;
    Material** materiales_aux = new Material*[(tope_viejo + 1)];

    for(int i = 0; i < datos->cantidad_de_materiales; i++){
        materiales_aux[i] = datos->materiales[i];
    }
    materiales_aux[tope_viejo] = material;

    if(datos->cantidad_de_materiales != 0){
        delete [] datos->materiales;
    }

    datos->materiales = materiales_aux;
    datos->cantidad_de_materiales++;
}


void procesar_edificios(Datos* datos){
    Edificio* edificio;
    string nombre, piedra, madera, metal, n_construidos, n_max_construibles;

    ifstream archivo(PATH_EDIFICIOS);
    
    datos -> cantidad_de_edificios = 0;

    while(archivo >> nombre){
        archivo >> piedra;
        archivo >> madera;
        archivo >> metal;
        archivo >> n_construidos;
        archivo >> n_max_construibles;

        edificio = new Edificio;
        edificio -> nombre = nombre;
        edificio -> piedra = stoi(piedra);
        edificio -> madera = stoi(madera);
        edificio -> metal = stoi(metal);
        edificio -> n_construidos = stoi(n_construidos);
        edificio -> n_max_construibles = stoi(n_max_construibles);

        agregar_edificio(datos, edificio);
    }

    archivo.close();
}


void agregar_edificio(Datos* datos, Edificio* edificio){
    int tope_viejo = datos -> cantidad_de_edificios;
    Edificio** edificios_aux = new Edificio*[(tope_viejo + 1)];

    for(int i = 0; i < datos -> cantidad_de_edificios; i++){
        edificios_aux[i] = datos -> edificios[i];
    }
    edificios_aux[tope_viejo] = edificio;

    if(datos->cantidad_de_materiales != 0){
        delete [] datos -> edificios;
    }

    datos -> edificios = edificios_aux;
    datos -> cantidad_de_edificios++;
}

void menu(int opcion,Datos* datos){
    switch (opcion) {
        case CONSTRUIR:
            construir_edificio(datos);
            break;
        case LISTAR_EDIF_C:
            listar_edificios_construidos(datos);
            break;
        case LISTAR_EDIF:
            listar_edificios(datos);
            break;
        case DEMOLER:
            demoler_edificio(datos);
            break;
        case MOSTRAR_MAPA:
            //funcion mapa;
            break;
        case CONSULTAR_COORD:
            //funcion consultar coordenada;
            break;
        case MOSTRAR_INVENTARIO:
            listar_inventario(datos);
            break;
        case COLECTAR_RECURSOS:
            //funcion recolectar recursos producidos;
            break;
        case LLUVIA_RECURSOS:
            //funcion recolectar recursos producidos;
            break;
        case SALIR:
            guardar_contenido(datos);
            break;
        default:
            cout << "Error: opcion invalida";
    }
}

void mostrar_menu(){
    cout<<endl<<"1. Construir edificio por nombre."<<endl;
    cout<<"2. Listar los edificios construidos."<<endl;
    cout<<"3. Listar todos los edificios."<<endl;
    cout<<"4. Demoler un edificio por coordenada. "<<endl;
    cout<<"5. Mostrar mapa."<<endl;
    cout<<"6. Consultar coordenada."<<endl;
    cout<<"7. Mostrar inventario."<<endl;
    cout<<"8. Recolectar recursos producidos."<<endl;
    cout<<"9. Lluvia de recursos. "<<endl;
    cout<<"10. Guardar y salir. "<<endl;
}

void listar_inventario(Datos* datos){
    cout<<"Tienes la siguiente cantidad de materiales:\n"<<endl;

    for (int i=0; i<datos -> cantidad_de_materiales; i++)
        cout<<datos -> materiales[i] -> nombre<<": "<<datos -> materiales[i] -> cantidad<<" unidades"<<endl;
}

void listar_edificios_construidos(Datos* datos){
    cout<<"Los edificios construidos y sus cantidades son:\n"<<endl;
    for (int i = 0; i<datos ->cantidad_de_edificios; i++){
        if (datos -> edificios[i] -> n_construidos > 0)
            cout<<datos -> edificios[i] -> nombre<<": "<<datos -> edificios[i] -> n_construidos<<" construido"<<endl; 
    }
}

void listar_edificios(Datos* datos){
    cout<<"Los edificios construidos y sus cantidades son:\n"<<endl;

    for (int i = 0; i<datos ->cantidad_de_edificios;i++){
        cout << "\n-----------------------" << endl
             << "Nombre: " << datos -> edificios[i] -> nombre << endl << endl
             << "Materiales necesarios para su construccion: " << endl
             << "Madera: " <<datos -> edificios[i] -> madera << endl
             << "Piedra: " << datos -> edificios[i] -> piedra << endl
             << "Metal: " << datos -> edificios[i] -> metal << endl << endl
             << "Cantidad construida hasta el momento: " << datos -> edificios[i] -> n_construidos << endl << endl;
             if ((datos -> edificios[i] -> n_max_construibles - datos -> edificios[i] -> n_construidos) > 0){
                cout << "Se pueden construir " << (datos -> edificios[i] -> n_max_construibles - datos -> edificios[i] -> n_construidos) << " mas." << endl;
                }else (cout << "No se pueden construir mas edificios." <<endl);
    }
}

void demoler_edificio(Datos* datos){
    string nombre_edificio;
    int posicion = ERROR, posicion_metal, posicion_madera, posicion_piedra;;

    cout<<"Nombre del edificio que queres demoler: ";
    cin>> nombre_edificio;

    buscador_de_posicion_edificio(posicion,nombre_edificio,datos);

    buscador_posicion_del_material(posicion_piedra, PIEDRA, datos);
    buscador_posicion_del_material(posicion_madera, MADERA, datos);
    buscador_posicion_del_material(posicion_metal, METAL, datos);

    if (datos -> edificios[posicion] -> n_construidos > 0){
        datos -> materiales[posicion_piedra] -> cantidad += datos -> edificios[posicion] -> piedra/2;
        datos -> materiales[posicion_madera] -> cantidad += datos -> edificios[posicion] -> madera/2;
        datos -> materiales[posicion_metal] -> cantidad += datos -> edificios[posicion] -> metal/2;
        
        datos -> edificios[posicion] -> n_construidos -= 1;
        cout<<"\nEdificio demolido con exito!\n"<<endl;
    }

    else
        cout<<"No hay edificio de este tipo para demoler."<<endl;
} 

void construir_edificio(Datos* datos){
    string nombre_edificio;
    int posicion_edificio = ERROR, posicion_metal, posicion_madera, posicion_piedra;
    
    cout<<"Nombre del edificio que queres construir: ";
    cin>> nombre_edificio;

    buscador_de_posicion_edificio(posicion_edificio,nombre_edificio,datos);

    buscador_posicion_del_material(posicion_piedra, PIEDRA, datos);
    buscador_posicion_del_material(posicion_madera, MADERA, datos);
    buscador_posicion_del_material(posicion_metal, METAL, datos);

    if (datos -> edificios[posicion_edificio] -> n_construidos < datos -> edificios[posicion_edificio] -> n_max_construibles 
        && datos -> edificios[posicion_edificio] -> piedra < datos -> materiales[posicion_piedra] -> cantidad
        && datos -> edificios[posicion_edificio] -> madera < datos -> materiales[posicion_madera] -> cantidad
        && datos -> edificios[posicion_edificio] -> metal < datos -> materiales[posicion_metal] -> cantidad){

            datos -> materiales[posicion_piedra] -> cantidad -= datos -> edificios[posicion_edificio] -> piedra;    
            datos -> materiales[posicion_madera] -> cantidad -= datos -> edificios[posicion_edificio] -> madera;
            datos -> materiales[posicion_piedra] -> cantidad -= datos -> edificios[posicion_edificio] -> metal;
            datos -> edificios[posicion_edificio] -> n_construidos += 1;
            cout<<"\nEdificio construido con exito!"<<endl;
        }

    else if (datos -> edificios[posicion_edificio] -> n_construidos == datos -> edificios[posicion_edificio] -> n_max_construibles)
        cout<<"No puedes construir mas edificios de este tipo."<<endl;
    else
        cout<<"No tienes los materiales suficientes para construirlos."<<endl;
}

void guardar_contenido(Datos* datos){
    guardar_materiales(datos);
    guardar_edificios(datos);
}

void guardar_materiales(Datos* datos){
    ofstream archivo(PATH_MATERIALES);

    for (int i=0;i<datos -> cantidad_de_materiales;i++){
        archivo<<datos -> materiales[i] -> nombre<<" "<<datos -> materiales[i] -> cantidad<<endl;
        delete datos -> materiales[i];
    }

    delete[] datos->materiales;
    datos -> materiales = nullptr;
    archivo.close();
}
void guardar_edificios(Datos* datos){

    ofstream archivo(PATH_EDIFICIOS);

    for (int i=0;i<datos -> cantidad_de_edificios;i++){
        archivo<<datos -> edificios[i] -> nombre<<" "<<datos -> edificios[i] -> piedra<<" ";
        archivo<<datos -> edificios[i] -> madera<<" "<<datos -> edificios[i] -> metal<<" ";
        archivo<<datos -> edificios[i] -> n_construidos<<" "<<datos -> edificios[i] -> n_max_construibles<<endl;
        delete datos -> edificios[i];
    }

    delete[] datos->edificios;
    datos -> edificios = nullptr;

    archivo.close();
}

void buscador_de_posicion_edificio(int &posicion, string nombre_edificio, Datos* datos){
    while (posicion == ERROR)
    {
       for (int i=0;i<datos -> cantidad_de_edificios ;i++){
            if(nombre_edificio == datos -> edificios[i] -> nombre)
            posicion = i;
        }
        if (posicion == ERROR){
            cout<<"El edificio ingresado no existe, intente de nuevo: ";
            cin>> nombre_edificio;
        }   
    } 
}

void buscador_posicion_del_material(int &posicion, string nombre_material, Datos* datos){
    for (int i=0;i<datos -> cantidad_de_materiales ;i++){
                if(nombre_material == datos -> materiales[i] -> nombre)
                posicion = i;
    }   
}
