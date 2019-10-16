#include "CannonBall.h"
#include <MapaMar.h>
extern MapaMar* game;

CannonBall::CannonBall()
{
    setPixmap(QPixmap(":/images/canonBall"));

    //Conexion
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void CannonBall::move()
{
    QList<QGraphicsItem *> colliding_items =collidingItems();
    for (int i = 0, n = colliding_items.size();i<n;i++) {
        if(typeid(*(colliding_items[i])) == typeid(Pirata)){

            game->ganarPuntos();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(),y()-10);
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
