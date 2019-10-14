#ifndef BASE_H
#define BASE_H

#include <set>

#include <Oficial.h>
#include <Canon.h>
#include <Definiciones.h>
#include <BalaDeCanon.h>

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
    set<Canon> canonesDeBase;
    int _HP;
    int _maxHP;
    BalaDeCanon* municion;
    int posEnX;
    int posEnY;
};

#endif // BASE_H
