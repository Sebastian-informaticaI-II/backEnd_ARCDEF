#ifndef CANON_H
#define CANON_H

#include <iostream>
#include <QObject>
#include <Definiciones.h>

using namespace std;

class Canon : public QObject
{
    Q_OBJECT
public:
    Canon(QObject *parent = nullptr);
    virtual ~Canon() = 0;

public slots:
    PesoBala calibre() const;
    void setCalibre(const PesoBala &calibre);

    int damage() const;
    void setDamage(int damage);

    int alcance() const;
    void setAlcance(int alcance);

    bool cargado() const;
    void setCargado(bool cargado);

    virtual void recargar();
    virtual void disparar();

private:
    PesoBala _calibre;
    int _damage;
    int _alcance;
    bool _cargado;
};

#endif // CANON_H
