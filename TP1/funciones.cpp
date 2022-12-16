#include <iostream>
#include "utiles.h"
#include <fstream>

using namespace std;

void cargar_materiales(Info* info){
    fstream archivo_materiales(PATH_MATERIALES, ios::in);
    string nombre,cantidad;
    Materiales* materiales;
    
    int i = 0;

    if (!archivo_materiales.is_open()) {
        cout << "\nError al abrir el archivo." <<endl;
    }else{
        while(archivo_materiales >> nombre){
            archivo_materiales >> cantidad;

            materiales = new Materiales;
            materiales -> nombre = nombre;
            materiales -> cantidad = stoi(cantidad);

            agregar_material(info, materiales);
            i++;
        }

        int cantidad_materiales = i;
        
        info -> cantidad_materiales = cantidad_materiales;

        archivo_materiales.close();}
}

void agregar_material(Info* info,Materiales* materiales){
    int tope_viejo = info->cantidad_materiales;
    Materiales** nuevo_vector_materiales = new Materiales*[tope_viejo + 1];

    for(int i = 0; i < info -> cantidad_materiales; i++){
        nuevo_vector_materiales[i] = info -> materiales[i];
    }
    nuevo_vector_materiales[tope_viejo] = materiales;

    if(info -> cantidad_materiales != 0){
        delete[] info -> materiales;
    }

    info -> materiales = nuevo_vector_materiales;
    info -> cantidad_materiales++;
    }

void cargar_edificios(Info* info){
    fstream archivo_edificios(PATH_EDIFICIOS, ios::in);
    string nombre, piedra, madera, metal, construidos, maxima_cantidad;
    Edificios* edificios;
    
    int i = 0;

    if (!archivo_edificios.is_open()) {
        cout << "\nError al abrir el archivo." <<endl;
    }else{
        while(archivo_edificios >> nombre){
            archivo_edificios >> piedra;
            archivo_edificios >> madera;
            archivo_edificios >> metal;
            archivo_edificios >> construidos;
            archivo_edificios >> maxima_cantidad;

            edificios = new Edificios;
            edificios -> nombre = nombre;
            edificios -> piedra = stoi(piedra);
            edificios -> madera = stoi(madera);
            edificios -> metal = stoi(metal);
            edificios -> construidos = stoi(construidos);
            edificios -> maxima_cantidad = stoi(maxima_cantidad);

            agregar_edificio(info, edificios);
            i++;
        }

        int cantidad_edificios = i;
        
        info -> cantidad_edificios = cantidad_edificios;

        archivo_edificios.close();}
}

void agregar_edificio(Info* info,Edificios* edificios){
    int tope_viejo = info->cantidad_edificios;
    Edificios** nuevo_vector_edificios = new Edificios*[tope_viejo + 1];

    for(int i = 0; i < info -> cantidad_edificios; i++){
        nuevo_vector_edificios[i] = info -> edificios[i];
    }
    nuevo_vector_edificios[tope_viejo] = edificios;

    if(info -> cantidad_edificios != 0){
        delete[] info -> edificios;
    }

    info -> edificios = nuevo_vector_edificios;
    info -> cantidad_edificios++;
    }

void mostrar_menu(){
    cout << endl << endl << endl;
    cout << "MENU" << endl
    << '\t' << "1. Listar materiales de construccion." << endl
    << '\t' << "2. Construir edificio por nombre." << endl
    << '\t' << "3. Listar los edificios construidos." << endl
    << '\t' << "4. Listar todos los edificios." << endl
    << '\t' << "5. Demoler un edificio por nombre." << endl
    << '\t' << "6. Guardar y salir." << endl;
}

int pedir_opcion(){
    int opcion_elegida = -1;
    cout << "\nIngrese el numero de su accion elegida: ";
    cin >> opcion_elegida;

    return opcion_elegida;
}

void verificar_rango( int &opcion){
    bool es_opcion_valida = opcion > 0 && opcion <= OPCIONES_VALIDAS;
    while (!es_opcion_valida){
        cout <<"\nLa opcion elegida no esta dentro del rango, por favor ingrese otra opcion: ";
        cin >> opcion;
        es_opcion_valida = opcion > 0 && opcion <= OPCIONES_VALIDAS;
    }
}

void procesar_opcion(int opcion,Info* info){
    switch (opcion){
        case LISTAR_MATERIALES_CONSTRUCCION:
            listar_materiales(info);
            break;
        case CONSTRUIR_EDIFICIO:
            construir_edificio(info);
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            listar_edificios_construidos(info);
            break;
        case LISTAR_TODOS_LOS_EDIFICIOS:
            listar_todos_edificios(info);
            break;
        case DEMOLER_EDIFICIO:
            demoler_edificio(info);
            break;
    };

}

void listar_materiales(Info* info){
    cout << endl;
    for (int i = 0; i<info -> cantidad_materiales;i++){
    cout << "Nombre: " << info -> materiales[i] -> nombre << 
    " Cantidad: " << info -> materiales[i] -> cantidad << endl;}
}

bool exsiste_edificio(string nombre,Info* info){
    bool exsiste_edificio = false;
    int i = 0;
    
    while(!exsiste_edificio && i < info -> cantidad_edificios){
        if(nombre == info -> edificios[i] -> nombre){
            exsiste_edificio = true;}
        i++;    
        }
    return exsiste_edificio;
}

int buscar_coordenada_edificio(string nombre,Info* info){
    int i = 0;
    while(nombre != info -> edificios[i] -> nombre && i < info -> cantidad_edificios){
        i += 1;
    }
    return i;
}

void calculadora_materiales(int posicion_edificio,Info* info, int &piedra, int &metal, int &madera){
    for (int j = 0; j < info -> cantidad_materiales;j++){
        if (info -> materiales[j] -> nombre == "piedra"){
            piedra = (info -> materiales[j] -> cantidad) - (info -> edificios[posicion_edificio] -> piedra);
        }
        else if (info -> materiales[j] -> nombre == "madera"){
            madera = (info -> materiales[j] -> cantidad) - (info -> edificios[posicion_edificio] -> madera);
        }
        else if (info -> materiales[j] -> nombre == "metal"){
            metal = (info -> materiales[j] -> cantidad )- (info -> edificios[posicion_edificio] -> metal);
        }
    }
}

bool verificar_disponibilidad_materiales(string nombre,Info* info){
    int piedra,madera,metal;
    bool verificar_disponibilidad_materiales = false;
    int i = buscar_coordenada_edificio(nombre,info);

    calculadora_materiales(i,info,piedra,metal,madera);

    if ((madera < 0) || (piedra < 0) || (metal < 0)){
        cout << "\nNo se puede  construir el edificio ya que faltan los siguientes materiales: " <<endl;
        if (metal < 0 ){
            cout << (metal*-1) << " metales. " <<endl;
        }
        if (piedra < 0 ){
            cout << (piedra*-1) << " piedras. " <<endl;
        }
        if (madera < 0 ){
            cout << (madera*-1) << " maderas. " <<endl;
        }
    }
    else if((info -> edificios[i] -> construidos) >= (info -> edificios[i] -> maxima_cantidad)){
        cout << "\nNo se puede contruir ya que ya se cumplio la cantidad maxima de construcciones para este edificio. Volveremos al menu principal." << endl;
    }else{verificar_disponibilidad_materiales = true;}

    return verificar_disponibilidad_materiales;
}

void construir_edificio(Info* info){
    string nombre_buscar;

    cout << "\nPor favor ingrese el nombre del edificio que desea construir (escriba S para salir): ";
    cin >> nombre_buscar;

    while (!exsiste_edificio(nombre_buscar,info) && (nombre_buscar != "S")){
        cout << "\nEl edificio mencionado no exsiste, por favor ingrese otro (escriba S para salir): ";
        cin >> nombre_buscar;
    }

    if ( (nombre_buscar != "S") && verificar_disponibilidad_materiales(nombre_buscar,info)){
        string confirmacion;

        cout <<"\nEsta seguro que desea construir el " << nombre_buscar <<"? (si/no)";
        cin >> confirmacion;

        if (confirmacion == "si"){

            cout << "\nMuy bien, procederemos a construir el edificio. " << endl;
            int piedra,metal,madera;
            int posicion_edificio = buscar_coordenada_edificio(nombre_buscar,info);
            
            calculadora_materiales(posicion_edificio,info,piedra,metal,madera);

            info -> edificios[posicion_edificio] -> construidos ++;
            actualizador_materiales(info,piedra,madera,metal);

            cout << "Edificio construido con exito!" << endl;
        }
    };
}

void actualizador_materiales(Info* info, int piedra, int madera, int metal){

    for (int j = 0; j < info -> cantidad_materiales;j++){
        if (info -> materiales[j] -> nombre == "piedra"){
            info -> materiales[j] -> cantidad = piedra;
        }
        else if (info -> materiales[j] -> nombre == "madera"){
            info -> materiales[j] -> cantidad = madera;
        }
        else if (info -> materiales[j] -> nombre == "metal"){
            info -> materiales[j] -> cantidad = metal;
        }
    }
}

void sumar_materiales(Info* info, int piedra, int madera, int metal){
    for (int j = 0; j < info -> cantidad_materiales;j++){
        if (info -> materiales[j] -> nombre == "piedra"){
            info -> materiales[j] -> cantidad += piedra;
        }
        else if (info -> materiales[j] -> nombre == "madera"){
            info -> materiales[j] -> cantidad += madera;
        }
        else if (info -> materiales[j] -> nombre == "metal"){
            info -> materiales[j] -> cantidad += metal;
        }
    }
}

void listar_edificios_construidos(Info* info){
    cout << endl;
    for (int i = 0; i<info -> cantidad_edificios;i++){
        if (info -> edificios[i] -> construidos > 0){
            cout << "Nombre: " << info -> edificios[i] -> nombre 
            << " Cantidad construida: " << info -> edificios[i] -> construidos  << endl;}
        }
    }    

void listar_todos_edificios(Info* info){
    cout << endl;
    for (int i = 0; i<info -> cantidad_edificios;i++){
        cout << "-----------------------" << endl
        << "Nombre: " << info -> edificios[i] -> nombre << endl << endl
        << "Materiales necesarios para su construccion: " << endl
        << "Madera: " << info -> edificios[i] -> madera << endl
        << "Piedra: " << info -> edificios[i] -> piedra << endl
        << "Metal: " << info -> edificios[i] -> metal << endl << endl
        << "Cantidad construida hasta el momento: " << info -> edificios[i] -> construidos  << endl << endl
        << "Se pueden construir " << (info -> edificios[i] -> maxima_cantidad - info -> edificios[i] -> construidos) << " mas." << endl;
    }
}

void demoler_edificio(Info* info){
    string nombre_edificio;
    cout << "\nIngrese el nombre del edificio a demoler: ";
    cin >> nombre_edificio;
    int piedra,madera,metal,index;

    if (exsiste_edificio(nombre_edificio,info)){
        index = buscar_coordenada_edificio(nombre_edificio,info);
        if (info -> edificios[index] -> construidos > 0){

            madera = (info -> edificios[index] -> madera/2);
            piedra = (info -> edificios[index] -> piedra/2);
            metal = (info -> edificios[index] -> metal/2);

            sumar_materiales(info,piedra,madera,metal);

            info -> edificios[index] -> construidos --;
            cout << "\nEdificio derrumbado con exito!" <<endl;
        }else {cout << "\nEl edificio mencionado no tiene construcciones para demoler. Volveremos al menu principal.";}

    }else{cout << "\nEl edificio mencionado no exsiste. Volveremos al menu principal.";}
}

void escribir_archivo_materiales(Info* info){

    ofstream archivo_materiales(PATH_MATERIALES);

    int cantidad_materiales = info -> cantidad_materiales;

    if (!archivo_materiales.is_open()) {
        cout << "\nError al abrir el archivo materiales." <<endl;}

    for (int i=0;i < cantidad_materiales;i++){
        archivo_materiales << info -> materiales[i] -> nombre << " " << 
        info -> materiales[i] -> cantidad << endl;

        delete info -> materiales[i]; 
        info -> cantidad_materiales --;
    }
    delete[] info -> materiales;
    info -> materiales = nullptr;
    archivo_materiales.close();
    }

void escribir_archivo_edificios(Info* info){

    ofstream archivo_edificios(PATH_EDIFICIOS);

    int cantidad_edificios = info -> cantidad_edificios;

    if (!archivo_edificios.is_open()) {
        cout << "\nError al abrir el archivo edificios." <<endl;}

    for (int i=0;i < cantidad_edificios;i++){
        archivo_edificios << info -> edificios[i] -> nombre << " " << info -> edificios[i] -> piedra 
        << " " << info -> edificios[i] -> madera  << " " << info -> edificios[i] -> metal  << " "
        << info -> edificios[i] -> construidos << " " << info -> edificios[i] -> maxima_cantidad << endl;

        delete info -> edificios[i]; 
        info -> cantidad_edificios --;
    }
    delete[] info -> edificios;
    info -> edificios = nullptr;
    archivo_edificios.close();
}