#include "Canon.h"

Canon::Canon(QObject *parent): QObject(parent)
{

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
    cout << "recargando " << endl;
    QTimer::singleShot(_reloadTime,this, SLOT(recargado()));
}

void Canon::disparar()
{
    cout << " disparar " << endl;
    if(!_cargado){
        return;
    }
    //TODO Disparar
    _cargado =false;
}

void Canon::recargado()
{
    cout << "recargado " << endl;
    setCargado(true);
}

int Canon::reloadTime() const
{
    return _reloadTime;
}

void Canon::setReloadTime(int reloadTime)
{
    _reloadTime = reloadTime;
}

int Canon::velocidadImpresa() const
{
    return _velocidadImpresa;
}

void Canon::setVelocidadImpresa(int velocidadImpresa)
{
    _velocidadImpresa = velocidadImpresa;
}

PesoBala Canon::calibre() const
{
    return _calibre;
}

void Canon::setCalibre(const PesoBala &calibre)
{
    _calibre = calibre;
}


