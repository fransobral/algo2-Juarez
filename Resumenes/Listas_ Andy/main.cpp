#include <iostream>
#include "pila.h"
#include "cola.h"
#include "lista.h"


using namespace std;

int main()
{
    Lista l;
    l.alta(5, 1);
    l.alta(8, 2);
    cout << "\nCon los primeros datos " << endl;
    l.mostrar();
    l.alta(3, 1);
    l.alta(9, 2);
    l.baja(3);
    cout << "Luego de los cambios " << endl;
    l.mostrar();

    /*
    Cola c;
    c.alta(5);
    c.alta(3);
    c.alta(8);
    cout << "El siguiente elemento a procesar es: " << c.consulta() << endl;
    cout << "Doy de baja a: " << c.baja() << endl;
    c.alta(2);


    while (! c.vacia())
        cout << "Doy de baja a: " << c.baja() << endl;
    */

    /*
    Pila p;
    p.alta(5);
    p.alta(8);
    p.alta(3);
    cout << "El ultimo elemento es: " << p.consulta() << endl;
    p.baja();
    cout << "El ultimo elemento es: " << p.consulta() << endl;
    p.alta(7);

    while (! p.vacia())
        cout << p.baja() << endl;
        */

    return 0;
}
