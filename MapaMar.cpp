#include "MapaMar.h"

MapaMar::MapaMar(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/fondo_claro")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    //------------ Agregar elementos a escena ------------


    //------------- Agregar Sonido de fondo --------------
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/bgsound"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
    //---------------------- Mostrat ---------------------
    show();
}
