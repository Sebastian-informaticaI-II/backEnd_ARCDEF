#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

#include <Pirata.h>
#include <LanzamientoParabolico.h>

class CannonBall: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CannonBall();
public slots:
    void move();
private:
    double time;
    LanzamientoParabolico* lanzado;
};

#endif // CANNONBALL_H
