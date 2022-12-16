#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    Vector vec(4);

    cout << "Antes de cargarlo" << endl;
    vec.mostrar();
    vec.cambiar(0, 8);
    vec.cambiar(1, 3);
    vec.cambiar(2, 5);
    vec.cambiar(3, 4);
    cout << "Despues de cargarlo" << endl;
    vec.mostrar();
    vec.agrandar(3);
    cout << "Despues de agrandar" << endl;
    vec.mostrar();

    return 0;
}
