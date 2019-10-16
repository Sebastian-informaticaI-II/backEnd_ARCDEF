#include "Pirata.h"
#include <MapaMar.h>
extern MapaMar* game;

Pirata::Pirata()
{
    int random_number = rand() % 700;
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/pirata"));

    //Conexion
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Pirata::move()
{
    setPos(x(),y()+5);
    if(pos().y() > 500){
        game->recibirDamage();
        scene()->removeItem(this);
        delete this;
    }
}
