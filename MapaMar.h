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

#include <Definiciones.h>
#include <Vida.h>
#include <Puntaje.h>
#include <Barco.h>

class MapaMar: public QGraphicsView
{
    Q_OBJECT
public:
    MapaMar(Partida partida,QWidget * parent = nullptr);
    ~MapaMar();
    Partida obtenerPartida();
    void recibirDamage();
    void ganarPuntos();
private slots:
    void spawnByDif();
private:
    QGraphicsScene *scene;
    Vida* vida;
    Puntaje* puntos;
    QMediaPlayer *music;
    QMediaPlaylist *playlist;
    BarcoJugador* jugador;
    int dificultdad;
};

#endif // MAPAMAR_H
