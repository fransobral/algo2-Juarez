#ifndef CASILLERO_H
#define CASILLERO_H

using namespace std;

class Casillero{
    protected:
        int coordenada_x, coordenada_y;
    
    public:
        virtual void mostrar_casillero() = 0;
};

#endif //CASILLERO_H