#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <QGraphicsTextItem>
#include <QFont>

class Puntaje: public QGraphicsTextItem
{
public:
    Puntaje(QGraphicsItem * parent=0);
    int getPuntos() const;
    void ganarPuntos();
private:
    int puntos;
};

#endif // PUNTAJE_H
