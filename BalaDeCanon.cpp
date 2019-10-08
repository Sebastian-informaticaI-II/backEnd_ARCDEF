#include "BalaDeCanon.h"

BalaDeCanon::BalaDeCanon(PesoBala calibre)
{
    _calibre = calibre;
    _damage = damageByCaliber(calibre);
    _disparada = false;

}

int BalaDeCanon::damage() const
{
    return _damage;
}

void BalaDeCanon::disparase(int angulo, pair<int, int> puntoDeDisparo, int velocidadInicial)
{
    configurarLanzamiento(puntoDeDisparo.first,puntoDeDisparo.second,velocidadInicial,angulo);
}

pair<int, int> BalaDeCanon::calcularPosicionActual(int segundosDesdeDisparo)
{
    return posicionActual(segundosDesdeDisparo);
}

int BalaDeCanon::damageByCaliber(PesoBala calibre)
{
    int damageBala = 0;
    switch (calibre) {
    case PesoBala::LB_12 :
        damageBala = DAMAGE_12_LB;
        break;
    case PesoBala::LB_18 :
        damageBala = DAMAGE_18_LB;
        break;
    case PesoBala::LB_24 :
        damageBala = DAMAGE_24_LB;
        break;
    default:
        damageBala = DAMAGE_36_LB;
        break;
    }
    return damageBala;
}
