#ifndef VIDA_H
#define VIDA_H

#include <QGraphicsTextItem>
#include <QFont>

class Vida: public QGraphicsTextItem
{
public:
    Vida(QGraphicsItem * parent=0);
    int getVida() const;
    void decrementarVida();
private:
    int vida;
};

#endif // VIDA_H