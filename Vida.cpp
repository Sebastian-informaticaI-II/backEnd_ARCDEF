#include "Vida.h"

Vida::Vida(QGraphicsItem * parent): QGraphicsTextItem(parent)
{
    vida = 3;
    setPlainText(QString("Vida: ")+QString::number(vida));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

int Vida::getVida() const
{
    return vida;
}

void Vida::decrementarVida()
{
    vida--;
    setPlainText(QString("Vida: ")+QString::number(vida));
}

void Vida::setVida(int value)
{
    vida = value;
    setPlainText(QString("Vida: ")+QString::number(vida));
}
