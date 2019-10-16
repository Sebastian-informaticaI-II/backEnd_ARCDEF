#include "Barco.h"

Barco::Barco(QGraphicsItem *parent): QGraphicsPixmapItem (parent)
{
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet"));
    setPixmap(QPixmap(":/images/player"));
}

void Barco::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    else if (event->key()== Qt::Key_Space) {
        CannonBall * bullet = new CannonBall();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
        if(bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }

    }
}

void Barco::spawn()
{
    Pirata * enemy = new Pirata();
    scene()->addItem(enemy);
}
