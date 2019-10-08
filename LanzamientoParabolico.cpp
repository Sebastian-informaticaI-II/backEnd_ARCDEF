#include "LanzamientoParabolico.h"


LanzamientoParabolico::LanzamientoParabolico()
{

}

void LanzamientoParabolico::configurarLanzamiento(int x_0, int y_0, int v_0, int anguloDisparo)
{
    _postX0 = x_0;
    _postY0 = y_0;
    double anguloRadianes = (anguloDisparo * PI / ANGULO_PI );
    _v0x = v_0 * cos(anguloRadianes);
    _v0y = v_0 * sin(anguloRadianes);
}

pair<int, int> LanzamientoParabolico::posicionActual(int tiempo)
{
    int postX = calacularPostX(tiempo);
    int postY = calacularPostY(tiempo);
    return make_pair(postX,postY);
}

int LanzamientoParabolico::calacularPostX(int tiempo)
{
    int desplazamiento_x = static_cast<int>(_v0x * tiempo);
    return _postX0 + desplazamiento_x;
}

int LanzamientoParabolico::calacularPostY(int tiempo)
{
    double efectoGravedad = (GRAVEDAD * pow(tiempo,2)) / 2;
    double desplazamiento_y = (_v0y * tiempo) - efectoGravedad;
    return _postY0 + static_cast<int>(desplazamiento_y);
}

