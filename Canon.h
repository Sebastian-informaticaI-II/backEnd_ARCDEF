#ifndef CANON_H
#define CANON_H

#include <iostream>
#include <QObject>
#include <QTimer>
#include <Definiciones.h>

using namespace std;

class Canon : public QObject
{
    Q_OBJECT
public:
    Canon(QObject *parent = nullptr);

public slots:
    PesoBala calibre() const;
    void setCalibre(const PesoBala &calibre);

    int velocidadImpresa() const;
    void setVelocidadImpresa(int velocidadImpresa);

    bool cargado() const;
    void setCargado(bool cargado);

    int reloadTime() const;
    void setReloadTime(int reloadTime);

    virtual void recargar();
    virtual void disparar();
private slots:
    void recargado();
private:
    PesoBala _calibre;
    int _velocidadImpresa;
    int _reloadTime;
    bool _cargado;
};

#endif // CANON_H
