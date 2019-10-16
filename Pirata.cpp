#include "Pirata.h"
#include <MapaMar.h>
extern MapaMar* game;

Pirata::Pirata()
{
    int random_number = rand() % 433;
    setPos(800,random_number);

    setPixmap(QPixmap(":/images/pirata"));

    //Conexion
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Pirata::move()
{
    setPos(x()-5,y());
    if(pos().x() < 50){
        game->recibirDamage();
        scene()->removeItem(this);
        delete this;
    }
}
