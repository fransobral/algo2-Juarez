#include "lista_universidad.h"
//string nombre, int ranking, Lista<string>* carreras

using namespace std;

int main(){
    Lista<Universidad> lista1;
    for (int i = 0; i<4; i++){
        lista1.insertar();
    }
    lista1.mostrar();
    cout << endl;
    

    Lista<int>* lista2 = new Lista<int>;
    int numero = 3;

    for (int i = 0; i<5; i++){
        lista2->insertar(numero,i);
        numero ++;
    }

    lista2->mostrar();
    //lista1.swap(1,3);
    cout << endl;

    lista1.mostrar();

    Lista<int>* lista4;
    lista4 = lista1.append_list_pointer(lista2);
    cout<<"lista punteroo"<<endl;
    lista4->mostrar();

    cout << "\nJunte las listas" << endl;
    lista1.append_lists(lista2);
    lista1.mostrar();   

    lista1.revert_list();
    cout <<"revertida bro"<<endl;
    lista1.mostrar();

    Lista<int>* lista5;
    lista5 = lista1.puntero_swap();
    cout <<"revertida bro"<<endl;
    lista5 -> mostrar();

    lista1.eliminar_dato_ingresado(2);
    lista1.mostrar();

    cout <<"borrado bro"<<endl;
    lista1.eliminacion_completa_dato(3);
    cout << "Borro los 3"<<endl;
    lista1.mostrar();
    lista1.borrar_repetidos();
    lista1.ordenar();

    cout << "Lista 1" << endl;
    lista1.mostrar();

    cout << "Lista 2" << endl;
    lista2 -> mostrar();

    Lista<int>* lista3;
    lista3 = lista1.diferencias(lista2);
    cout << endl;
    cout << "nueva lista" <<endl;
    lista3 ->mostrar();

    delete lista3;
    delete lista2;
    delete lista4;
    delete lista5;

    return 0;
}