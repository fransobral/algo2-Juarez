
//1) Método que, dadas dos posiciones, intercambia sus datos.
template<typename Dato>
void Lista<Dato>::intercambiar(int pos_1, int pos_2) {
    //Guardo dato pos 1
    Dato aux_dato_1 = devolver_dato(pos_1);
    
    //Coloco el dato de la pos 2 en la pos 1
    cambiar_dato(devolver_dato(pos_2), pos_1);

    //Coloco el dato de la pos 1 en la pos 2
    cambiar_dato(aux_dato_1, pos_2);
}

// 2) Método que une la lista original con otra que se pasa por parámetro, modificando a la
// lista que llama. La lista pasada por parámetro va al final.
template<typename Dato>
void Lista<Dato>::colocar_al_final(Lista<Dato>* lista_al_fnal){
    
    for(int i=1; i<= lista_al_fnal->devolver_longitud(); i++ ){
        Dato dato = lista_al_fnal->devolver_dato(i);        
        insertar(dato); 
    }
}


// 3) Método que une la lista original con otra que se pasa por parámetro y devuelve un
// puntero a la nueva lista. La lista pasada por parámetro va al final.
template<typename Dato>
Lista<Dato>* Lista<Dato>::colocar_al_final_y_devolver_resultante(Lista<Dato>* lista_al_fnal){
    
    //CORREGIR!!!!!!!!

    Lista<Dato>* lista_nueva= new Lista<Dato>;
    
    lista_nueva = this;
    lista_nueva->colocar_al_final(lista_al_fnal);

    return lista_nueva;
}   

//4) Método que revierte la lista, modificándola (el último elemento pasa al primer lugar, etc).
template<typename Dato>
void Lista<Dato>::revertir(){
    
    // inicializar actual, anterior y siguiente
    ultimo = primero;
    actual = primero;
    Nodo<Dato>* siguiente = nullptr;

    while ( hay_siguiente() ) {
        // guardo el siguiente
        siguiente = actual->devolver_siguiente();
                        
        // doy vuelta el siguiente del actual
        actual-> cambiar_siguiente(anterior);
        
        //doy vuelta el anterior del actual
        //DE
        actual-> cambiar_anterior(siguiente);
        
        // Avanzo (No me sirve funcion porque cambie el siguiente y el anterior)
        anterior = actual;
        actual = siguiente;
    }
    primero = anterior;

    // cout<<"primero: "<<primero->devolver_dato()<<endl;
    // if (primero->devolver_siguiente()){
    //     cout<<"sig del primero: "<<primero->devolver_siguiente()->devolver_dato()<<endl;
    // }
    // if (ultimo->devolver_anterior()){
    // cout<<"anterior del ultimo: "<<ultimo->devolver_anterior()->devolver_dato()<<endl;
    // }
    // cout<<"ultimo: "<<ultimo->devolver_dato()<<endl;
}

//5) Método que revierte la lista en una nueva lista, y devuelve un puntero de la misma.
template<typename Dato>
Lista<Dato>* Lista<Dato>::revertir_y_devolver_nueva(){
    //OJO CON HACER
    //b    
    //a=b, modifico a, estoy modificando b (a->b)
    //modifico b, NO ESTOY MODIFICANDO a, b sigue apuntando a la misma direc de mem q antes
    Lista<Dato>* nueva_lista_revertida = new Lista<Dato>;

    for(int i=longitud; i>0; i-- ){
        Dato dato = devolver_dato(i);        
        nueva_lista_revertida->insertar(dato); 
    }
    
    return nueva_lista_revertida;
}