#ifndef CANON_H
#define CANON_H

#include <iostream>
#include <QObject>

using namespace std;

class Canon : public QObject
{
    Q_OBJECT
public:
    Canon(QObject *parent = nullptr);
    virtual ~Canon() = 0;

public slots:
    int damage() const;
    void setDamage(int damage);

    int alcance() const;
    void setAlcance(int alcance);

    bool cargado() const;
    void setCargado(bool cargado);

    virtual void recargar();
    virtual void disparar();

private:
    int _damage;
    int _alcance;
    bool _cargado;
};

#endif // CANON_H
