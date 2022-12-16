#include "casillero.h"
#include "edificio.h"

using namespace std;

class casillero_construible : public Casillero
{
    private:
        edificio edificio_en_casillero;

    public:
        void mostrar_casillero();
        void agregar_edificio(edificio edificio_en_casillero);
};