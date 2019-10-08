#ifndef BALADECANON_H
#define BALADECANON_H

#include <iostream>

using namespace std;

enum PesoBala {LB_12, LB_18, LB_24, LB_36};

class BalaDeCanon
{
public:
    BalaDeCanon();

    bool posibleImpacto(int heigtTarget, pair <int, int> posicionObjeto);
    int damageDeal();
private:
    int _damage;
    int _accurasi;
    int _alcance;
    PesoBala _calibre;
    pair <int, int> _puntoDeDisparo;
};

#endif // BALADECANON_H
