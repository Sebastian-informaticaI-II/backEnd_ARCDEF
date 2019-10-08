#ifndef MAPAMAR_H
#define MAPAMAR_H

#include <Base.h>
#include <Definiciones.h>

class MapaMar
{
public:
    MapaMar();
private:
    list<Base> naviosEnemigos;
    list<Base> islas;
    Base player;
};

#endif // MAPAMAR_H
