#ifndef MENUDIFICULTAD_H
#define MENUDIFICULTAD_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QBrush>
#include <QImage>
#include <QObject>
#include <QWidget>
#include <QPushButton>

class MenuDificultad: public QGraphicsView
{
    Q_OBJECT
public:
    MenuDificultad(QWidget * parent = nullptr);
    ~MenuDificultad();
signals:
    void dificultadElegida(int dificultad);
public slots:
    void setMenuDificultad();
private slots:
    void dificultadNivel_1();
    void dificultadNivel_2();
    void dificultadNivel_3();
    QPushButton* crearBotonMenu(int x,int y, const QString &icono,const QString &texto);
private:
    QPushButton* dificultad_1;
    QPushButton* dificultad_2;
    QPushButton* dificultad_3;
    QGraphicsScene *scene;
};

#endif // MENUDIFICULTAD_H
