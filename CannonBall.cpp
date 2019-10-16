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
    int px = x();
    int py = y();
    lanzado = new LanzamientoParabolico();
    lanzado->configurarLanzamiento(px,py,100,45);
    time=0;
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
//    time += 0.5;
//    pair <int, int> punto = lanzado->posicionActual(time);
//    int py = punto.first;
//    int px = punto.second;

//    setPos(px, y()-px);
    setPos(x()+10,y());


    if(pos().x() > 800){
        scene()->removeItem(this);
        delete this;
    }
}
