#include "lista.h"

using namespace std;

int main(){
    Lista<int> lista1;
    for (int i = 0; i<4; i++){
        lista1.insertar(i,i);
    }
    lista1.mostrar();
    cout << endl;
    

    Lista<int> lista2;
    lista2.mostrar();
    cout << "Hola" << endl;
    lista1.swap(1,3);
    cout << "Hola" << endl;
    lista1.mostrar();

    return 0;
}