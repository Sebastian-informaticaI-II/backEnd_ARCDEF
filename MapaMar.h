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

class MapaMar: public QGraphicsView
{
public:
    MapaMar(QWidget * parent=0);
private:
    QGraphicsScene *scene;
    list<Base> naviosEnemigos;
    Base player;
};

#endif // MAPAMAR_H
