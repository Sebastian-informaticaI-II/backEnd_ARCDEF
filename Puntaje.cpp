#include "Puntaje.h"

Puntaje::Puntaje(QGraphicsItem * parent): QGraphicsTextItem(parent)
{
    puntos = 0;
    setPlainText(QString("Puntaje: ")+QString::number(puntos));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

int Puntaje::getPuntos() const
{
    return puntos;
}

void Puntaje::ganarPuntos()
{
    puntos++;
    setPlainText(QString("Score: ")+QString::number(puntos));
}

void Puntaje::setPuntos(int value)
{
    puntos = value;
    setPlainText(QString("Score: ")+QString::number(puntos));
}
