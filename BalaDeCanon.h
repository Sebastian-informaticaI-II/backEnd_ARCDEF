#ifndef BALADECANON_H
#define BALADECANON_H

#include <iostream>
#include <Definiciones.h>
#include <LanzamientoParabolico.h>

using namespace std;

class BalaDeCanon : private LanzamientoParabolico
{
public:
    BalaDeCanon(PesoBala calibre);

    void disparase(int angulo, pair <int, int> puntoDeDisparo, int velocidadInicial);

    int damage() const;
    pair <int, int> calcularPosicionActual(int segundosDesdeDisparo);

    int damageByCaliber(PesoBala calibre);
private:
    int _damage;
    PesoBala _calibre;
    bool _disparada;
};

#endif // BALADECANON_H
