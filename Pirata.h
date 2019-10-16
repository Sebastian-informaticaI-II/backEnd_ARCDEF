#ifndef PIRATA_H
#define PIRATA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

class Pirata: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Pirata();
public slots:
    void move();
};

#endif // PIRATA_H
