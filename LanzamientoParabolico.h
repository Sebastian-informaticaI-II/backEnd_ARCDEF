#ifndef LANZAMIENTOPARABOLICO_H
#define LANZAMIENTOPARABOLICO_H

#include <utility>
#include <Definiciones.h>
#include <math.h>

using namespace std;

class LanzamientoParabolico
{
public:
    LanzamientoParabolico();
    void configurarLanzamiento(int x_0,int y_0, int v_0, int anguloDisparo);
    pair <int, int> posicionActual(int tiempo);
    int calacularPostX(int tiempo);
    int calacularPostY(int tiempo);
private:
    int _postX0;
    int _postY0;
    double _v0x;
    double _v0y;
};

#endif // LANZAMIENTOPARABOLICO_H
