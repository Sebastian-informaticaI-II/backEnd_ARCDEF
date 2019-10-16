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
    void configurarLanzamiento(double x_0,double y_0, double v_0, double anguloDisparo);
    pair <double, double> posicionActual(double tiempo);
    double calacularPostX(double tiempo);
    double calacularPostY(double tiempo);
private:
    double _postX0;
    double _postY0;
    double _v0x;
    double _v0y;
};

#endif // LANZAMIENTOPARABOLICO_H
