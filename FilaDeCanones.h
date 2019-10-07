#ifndef FILADECANONES_H
#define FILADECANONES_H

#include <iostream>

using namespace std;

class FilaDeCanones
{
public:
    FilaDeCanones();

    void apuntar(int angulo);
    void disparar();
    void recargar();
private:
    //TODO Amunition
    int _cantidad;
    int _damage;
    int _accurasi;
    int _alcance;
    int _reloadTime;
    int _estadoCarga;
    int _anguloDisparo;

};

#endif // FILADECANONES_H
