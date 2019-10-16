#include "LanzamientoParabolico.h"


LanzamientoParabolico::LanzamientoParabolico()
{

}

void LanzamientoParabolico::configurarLanzamiento(double  x_0, double  y_0, double  v_0, double  anguloDisparo)
{
    _postX0 = x_0;
    _postY0 = y_0;
    double anguloRadianes = (anguloDisparo * PI / ANGULO_PI );
    _v0x = v_0 * cos(anguloRadianes);
    _v0y = v_0 * sin(anguloRadianes);
}

pair<double , double > LanzamientoParabolico::posicionActual(double  tiempo)
{
    double  postX = calacularPostX(tiempo);
    double  postY = calacularPostY(tiempo);
    return make_pair(postX,postY);
}

double  LanzamientoParabolico::calacularPostX(double  tiempo)
{
    double  desplazamiento_x = (_v0x * tiempo);
    return _postX0 + desplazamiento_x;
}

double  LanzamientoParabolico::calacularPostY(double  tiempo)
{
    double efectoGravedad = (GRAVEDAD * pow(tiempo,2)) / 2;
    double desplazamiento_y = (_v0y * tiempo) - efectoGravedad;
    return _postY0 + (desplazamiento_y);
}

