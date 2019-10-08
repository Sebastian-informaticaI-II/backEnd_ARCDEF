#include "Canon.h"

Canon::Canon(QObject *parent): QObject(parent)
{

}

Canon::~Canon() {};

int Canon::damage() const
{
    return _damage;
}

void Canon::setDamage(int damage)
{
    _damage = damage;
}

int Canon::alcance() const
{
    return _alcance;
}

void Canon::setAlcance(int alcance)
{
    _alcance = alcance;
}

bool Canon::cargado() const
{
    return _cargado;
}

void Canon::setCargado(bool cargado)
{
    _cargado = cargado;
}

void Canon::recargar()
{
    cout << " recargar " << endl;
}

void Canon::disparar()
{
    cout << " disparar " << endl;
}


