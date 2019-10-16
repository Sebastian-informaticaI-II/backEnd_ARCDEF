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
#include <MapaMar.h>

class CannonBall: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CannonBall();
public slots:
    void move();
};

#endif // CANNONBALL_H
