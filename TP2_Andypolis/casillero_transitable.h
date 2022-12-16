#include "casillero.h"
#include "material.h"

using namespace std;

class casillero_transitable : public Casillero
{
    private:
        material material_en_casillero;

    public:
        void mostrar_casillero();
        void agregar_material(material material_en_casillero);
};