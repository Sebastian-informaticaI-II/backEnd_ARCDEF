#ifndef BARCO_H
#define BARCO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QGraphicsScene>

#include <CannonBall.h>
#include <Pirata.h>

class Barco:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Barco(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
    QMediaPlayer * bulletsound;
};

#endif // BARCO_H
