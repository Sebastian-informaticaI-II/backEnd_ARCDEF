#include "FilaDeCanones.h"

FilaDeCanones::FilaDeCanones(Canon *parent): Canon(parent)
{

}

void FilaDeCanones::setCanones(const Canon &modelo, int cantidad)
{
    setDamage(modelo.damage());
    setAlcance(modelo.alcance());
    setCargado(modelo.cargado());
    _cantidad = cantidad;
}

void FilaDeCanones::disparar()
{
    cout << "Disparo " << endl;
    setCargado(false);
}

void FilaDeCanones::recargar()
{
    cout << "recargando " << endl;
    QTimer::singleShot(_reloadTime,this, SLOT(recargado()));
}

int FilaDeCanones::reloadTime() const
{
    return _reloadTime;
}

void FilaDeCanones::setReloadTime(int reloadTime)
{
    _reloadTime = reloadTime;
}

int FilaDeCanones::accurasi() const
{
    return _accurasi;
}

void FilaDeCanones::setAccurasi(int accurasi)
{
    _accurasi = accurasi;
}

void FilaDeCanones::recargado()
{
    cout << "recargado " << endl;
    setCargado(true);
}
