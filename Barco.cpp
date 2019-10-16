#include "Barco.h"

BarcoJugador::BarcoJugador(QGraphicsItem *parent): QGraphicsPixmapItem (parent)
{
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet"));
    setPixmap(QPixmap(":/images/player"));
}

void BarcoJugador::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().y() > 0)
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().y() + 100 < 533)
        setPos(x(),y()+10);
    }
    else if (event->key()== Qt::Key_Space) {
        CannonBall * bullet = new CannonBall();
        bullet->setPos(x()+45,y()+40);
        scene()->addItem(bullet);
        if(bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }

    }
}

void BarcoJugador::spawn(int dif)
{
    for(int i=0; i < dif;i++){
        Pirata * enemy = new Pirata();
        scene()->addItem(enemy);
    }
}
