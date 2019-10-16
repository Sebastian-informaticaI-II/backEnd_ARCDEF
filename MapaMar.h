#ifndef MAPAMAR_H
#define MAPAMAR_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QBrush>
#include <QImage>
#include <QTimer>
#include <QObject>
#include <QWidget>

#include <Base.h>
#include <Definiciones.h>
#include <Vida.h>
#include <Puntaje.h>

class MapaMar: public QGraphicsView
{
public:
    MapaMar(Partida partida,QWidget * parent = nullptr);
    Partida obtenerPartida();
private:
    QGraphicsScene *scene;
    list<Base> naviosEnemigos;
    Base player;
    Vida* vida;
    Puntaje* puntos;
    int dificultdad;
};

#endif // MAPAMAR_H
