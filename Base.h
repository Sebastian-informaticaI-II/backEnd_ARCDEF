#ifndef BASE_H
#define BASE_H

#include <Oficial.h>
#include <FilaDeCanones.h>
#include <set>

enum TipoBase {BARCO,FORTIN};

class Base
{
public:
    Base();
    void girarT(bool derecha);
    void posicionVela();
    void anclar();
    void disparar();

private:
    string _nombre;
    string _capitan;
    TipoBase _base;
    set<Oficial> _oficiales;
    FilaDeCanones canones;
    int _carga;
    int _capacidadMax;
    int _HP;
    int _maxHP;
};

#endif // BASE_H
