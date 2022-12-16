#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

using namespace std;

template <typename Dato>

class Nodo {
private:
    // atributos
    Dato dato;
    Nodo<Dato>* siguiente;

public:
    // Constructor con parametro
    // PRE: d es un Dato valido
    // POS: crea un Nodo con d como dato y NULL en siguiente
    Nodo (Dato d);

    // Cambia el dato
    // PRE: d es un Dato valido
    // POS: cambia el dato actual por d
    void cambiar_dato (Dato d);

    // Cambia el siguiente
    // PRE: s es un puntero a Nodo valido
    // POS: cambia el siguiente por s
    void cambiar_siguiente (Nodo* s);

    // Obtiene el dato
    // PRE:
    // POS: devuelve el dato
    Dato obtener_dato();

    // Obtiene el siguiente
    // PRE:
    // POS: devuelve el puntero siguiente
    Nodo<Dato>* obtener_siguiente();

    // Destructor
    // PRE:
    // POS: libera la memoria solicitada
    ~Nodo();

    int comparar_con(Dato d);
};


template <typename Dato>
Nodo<Dato>::Nodo(Dato d){
    this->dato = d;
    this->siguiente = nullptr;
}

template <typename Dato>
void Nodo<Dato>::cambiar_dato(Dato d){
    dato = d;
}

template <typename Dato>
void Nodo<Dato>::cambiar_siguiente(Nodo* s){
    siguiente = s;
}

template <typename Dato>
Dato Nodo<Dato>::obtener_dato(){
    return dato;
}

template <typename Dato>
Nodo<Dato> * Nodo<Dato>::obtener_siguiente(){
    return siguiente;
}


template <typename Dato>
Nodo<Dato>::~Nodo(){
    dato = 0;
}

template <typename Dato>
int Nodo<Dato>::comparar_con(Dato d){
    if (d> dato){
        return 1;
    }else if( d == dato){return 0;}
    else if (d<dato){return -1;
    }
    return 4;
}
#endif // NODO_H_INCLUDED